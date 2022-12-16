#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int> > matrix;
int R, C, k;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	cin >> R >> C >> k;
	matrix = vector<vector<int> >(R, vector<int>(C));
	
	for(int r=0;r<R;++r) {
		for(int c=0;c<C;++c) {
			cin >> matrix[r][c];
		}
	}

	vector<int> bestScore(C), bestRemovals(C);

	int bscore = 0;
	int rmovals = 0;

	for(int c=0;c<C;++c) {
		int amt = 0;
		int pos = 0;
		for(int i=0;i<k && i<R;++i) {
			amt += matrix[i][c];
		}
		bestScore[c] = 0;
		bestRemovals[c] = 0;
		if(matrix[0][c] == 1)
			bestScore[c] = amt;
		int removals = 0;
		for(int i=1;i<R;++i) {
			amt -= matrix[i-1][c];
			if(matrix[i-1][c] == 1)
				removals++;
			if(i+k-1 < R)
				amt += matrix[i+k-1][c];
			if(amt > bestScore[c]) {
				bestScore[c] = amt;
				bestRemovals[c] = removals;
				//cerr << bestScore[c] << " " << bestRemovals[c] << endl;
			}
		}
		bscore += bestScore[c];
		rmovals += bestRemovals[c];
	}
	
	cout << bscore << " " << rmovals << endl;


	return 0;
}