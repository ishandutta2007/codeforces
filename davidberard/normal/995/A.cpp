#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, K;
vector<int> createMove(int id, int pos, int level) {
	// level 0 for parking, 1 for not
	vector<int> ans(3);
	ans[0] = id;
	if(pos < N) {
		ans[1] = 1+level;
		ans[2] = pos+1;
	} else {
		ans[1] = 4-level;
		ans[2] = 2*N-pos;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	/**
	 *  0 1 2 3 4
	 *  9 8 7 6 5 
	 */
	cin >> N;
	cin >> K;
	vector<int> here(2*N, -1);
	vector<int> goal(K+1, -1);
	for(int i=0;i<N;++i) {
		int v;
		cin >> v;
		goal[v] = i;
	}
	int open = -1;
	for(int i=0;i<N;++i) {
		int v;
		cin >> v;
		here[i] = (v == 0 ? -1 : v);
		open = (v == 0 ? i : open);
	}
	for(int i=0;i<N;++i) {
		int v;
		cin >> v;
		here[2*N-i-1] = (v == 0 ? -1 : v);
		open = (v == 0 ? 2*N-i-1 : open);
	}
	for(int i=0;i<N;++i) {
		int v;
		cin >> v;
		goal[v] = 2*N-i-1;
	}
	vector<vector<int>> moves;
	int remaining = K;
	if(open == -1) {
		bool found = false;
		for(int i=0;i<2*N;++i) {
			if(goal[here[i]] == i) {
				open = i;
				moves.push_back(createMove(here[i], i, 0));
				here[i] = -1;
				--remaining;
				found = true;
				break;
			}
		}
		if(!found) {
			cout << -1 << endl;
			return 0;
		}
	}
	while(remaining) {
		//cerr << " rem " << remaining << endl;
		// look for and place any "good" cars
		for(int i=0;i<2*N;++i) {
			if(here[i] != -1 && goal[here[i]] == i) {
				//cerr << "   !" << here[i] << endl;
				moves.push_back(createMove(here[i], i, 0));
				--remaining;
				here[i] = -1;
			}
		}
		if(!remaining) break;
		// move cars backwards into the open spot...
		for(int i=0;i<2*N-1;++i) {
			if(here[(open+i+1)%(2*N)] != -1) {
				//cerr << " move " << here[(open+i+1)%(2*N)] << " to " << (i+open)%(2*N) << endl;
				moves.push_back(createMove(here[(open+i+1)%(2*N)], (open+i)%(2*N), 1));
				swap(here[(open+i)%(2*N)], here[(open+i+1)%(2*N)]);
			}
		}
		open=(open+2*N-1)%(2*N);
		
		/*
		cerr << "    ";
		for(int i=0;i<N;++i) {
			cerr << here[i] << " ";
		}
		cerr << "\n    ";
		for(int i=0;i<N;++i) {
			cerr << here[2*N-1-i] << " ";
		}
		cerr << endl;

		cerr << "  " << open << endl;
		*/
	}

	cout << moves.size() << endl;
	for(auto& v : moves) {
		cout << v[0] << " " << v[1] << " " << v[2] << "\n";
	}

	return 0;
}