/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*******************Debugging defines*************************/

#define ok_dump() cerr<<"OK\n"
#define var_dump(x) cerr<<#x": "<<x<<'\n'
#define arr_dump(x, n) do{cerr<<#x"[]: ";\
     for(int _=0;_<n;++_) cerr<<x[_]<<" ";cerr<<'\n';}while(0)

/*************************************************************/

#define int long long
const int kMaxN = 10000;

int A[kMaxN], B[kMaxN], C[kMaxN], D[kMaxN], I[kMaxN], X[kMaxN];
int DP[kMaxN], Ant[kMaxN];

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, s, e;
	cin >> n >> s >> e;

	for(int i = 1; i <= n; ++i) cin >> X[i];
	for(int i = 1; i <= n; ++i) cin >> A[i];
	for(int i = 1; i <= n; ++i) cin >> B[i];
	for(int i = 1; i <= n; ++i) cin >> C[i];
	for(int i = 1; i <= n; ++i) cin >> D[i];



	for(int j = 1; j <= n + 1; ++j) 
		Ant[j] = 1e18;
	
	for(int i = 1; i <= n; ++i) {

		for(int j = 0; j <= n + 1; ++j) 
			DP[j] = 1e18;


		int land_small = X[i] + A[i];
		int land_large = -X[i] + B[i];

		int go_small = X[i] + C[i];
		int go_large = -X[i] + D[i];


		if(i == s) {
			for(int j = 1; j <= n; ++j) {
				DP[j] = min(DP[j], Ant[j] + go_small);
				DP[j] = min(DP[j], Ant[j - 1] + go_large);
			}
		}

		else if(i == e) {
			for(int j = 1; j <= n; ++j) {
				DP[j] = min(DP[j], Ant[j] + land_small);
				DP[j] = min(DP[j], Ant[j - 1] + land_large);
			}
		}

		else {
			for(int j = 1; j <= n; ++j) {

				DP[j] = min(DP[j], Ant[j - 1] + land_large + go_large);				
				if(i < s || j > 1) DP[j] = min(DP[j], Ant[j] + land_large + go_small);
				if(i < e || j > 1) DP[j] = min(DP[j], Ant[j] + land_small + go_large);
				DP[j] = min(DP[j], Ant[j + 1] + land_small + go_small);
			}
		}

		if(i >= s && i >= e && i != n) DP[1] = 1e18;
		for(int j = 0; j <= n + 1; ++j)
			if(DP[j] > 1e17)
				DP[j] = 1e18;

		swap(DP, Ant);
	}

	cout << Ant[1] << endl;

	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/