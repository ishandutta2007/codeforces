#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;
typedef pair<ld, ld> pdd;

int c1;

struct state {
	int h1, a1, h2, a2, level;
	int laststate;
	state() {}
	state(int a, int b, int c, int d, int e, int f)
		:h1(a), a1(b), h2(c), a2(d), level(e), laststate(f) {}
};

/*
void bfs(int h1i, a1i, h2i, a2i) {
	queue<int> q;
	vector<state> states;
	map<state, int> Map;
	states.push_back(state(h1i, a1i, h2i, a2i, 0, -1));
	Map[states[0]] = 0;

	state fin;
	
	q.push_back(0);
	while(q.size() > 0) {
		st = states[q.front()];
		q.pop();
		// try each of the 
	}
}
*/

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int N;
	cin >> N;
	vector<int> boxes(N);
	for(int i=0;i<N;++i) {
		cin >> boxes[i];
	}
	sort(boxes.begin(), boxes.end());
	vector<bool> taken(N, false);
	int ntaken = 0;
	int outside = 0;
	for(int i=0;i<N && ntaken < N;++i) {
		int lsize = boxes[N-1]+1;
		++outside;
		for(int j=N-1;j>=0;--j) {
			if(!taken[j] && lsize > boxes[j])
			{
				taken[j] = true;
				++ntaken;
				lsize = boxes[j];
			}
		}
	}

	cout << outside << endl;

	return 0;
}