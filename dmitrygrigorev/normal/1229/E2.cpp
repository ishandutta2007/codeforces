#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1000000007;

int sum(int x, int y){
	if (x+y<0) return x+y+mod;
	if (x+y >= mod) return x+y-mod;
	return x+y;
}

int mult(int x, int y){
	return ((ll) x * (ll) y) % (ll) mod;
}

int pw(int x, int y){
	if (y==0) return 1;
	if (y==1) return x%mod;
	if (y%2) return mult(x, pw(x, y-1));
	int R = pw(x, y/2);
	return mult(R, R);
}

const int SIZE = 7;

int REV = pw(100, mod-2);

int matrix[SIZE][SIZE];

map<vector<int>, int> sums;

map<vector<int>, int> new_sums;

vector<bool> used;

main(){
	#ifdef LOCAL
    freopen("H_input.txt", "r", stdin);
    //freopen("B_output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	for (int i=0;i<n;++i) for (int j=0;j<n;++j){
		cin >> matrix[i][j];
		matrix[i][j] = mult(matrix[i][j], REV);
	}
	for (int i=n; i < SIZE; ++i) matrix[i][i] = 1;
	sums[{0}] = 1;
	for (int i=0; i < SIZE; ++i){
		new_sums.clear();
		for (int j=0; j < (1<<SIZE); ++j){
			int P = 1;
			//cout << j << endl;
			for (int e=0; e < SIZE; ++e){
				int ba = (1<<e)&j;
				if (ba) P = mult(P, matrix[e][i]);
				else P = mult(P, sum(1, -matrix[e][i]));
			}

			for (auto it = sums.begin(); it != sums.end(); it++){
				used.assign(1<<SIZE, false);
				vector<int> Q = (*it).first;
				int T = (*it).second;
				for (int e=0; e < Q.size(); ++e){
					for (int f=0; f < SIZE; ++f){
						int ba = (1<<f)&j;
						if (ba==0) continue;
						int W = Q[e]|(1<<f);
						if (__builtin_popcount(W) == i+1){
							used[W] = true;
						}
					}
				}
				T = mult(T, P);
				vector<int> added;
				for (int e=0; e < (1<<SIZE); ++e) if (used[e]) added.push_back(e);
				if (!added.size()) continue;
				new_sums[added] = sum(new_sums[added], T);
			}

		}
		sums = new_sums;
	}
	int ans = 0;
	for (auto it = sums.begin(); it != sums.end(); it++){
		ans = sum(ans, (*it).second);
	}

	cout << ans;
}