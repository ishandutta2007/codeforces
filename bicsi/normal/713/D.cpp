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

const int kMaxN = 500000;

struct Query {
	int l, r, i;
};

int A[1005][1005], DP[1005][1005], Now[1005];
vector<Query> Q[1005][1005];
int Ans[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			scanf("%d", &A[i][j]);
			if(A[i][j]) {
				DP[i][j] = min(DP[i - 1][j], DP[i][j - 1]);
				DP[i][j] = min(DP[i][j], DP[i - 1][j - 1]);
				DP[i][j] += 1;
			}
		}

	int q, a, b, c, d;
	scanf("%d", &q);
	for(int i = 1; i <= q; ++i) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		Q[a][c].push_back((Query) {b, d, i});
	}


	for(int up = 1; up <= n; ++up) {
		memset(Now, 0, sizeof(Now));
		for(int down = 1; down <= n; ++down) {
			for(int right = 1; right <= m; ++right) {
				// Do stuff now

				int now_len = min(DP[down][right], down - up + 1);
				Now[right] = max(Now[right], now_len);
			}

			for(auto q : Q[up][down]) {
				int ans = 0;
				for(int i = q.l; i <= q.r; ++i)
					ans = max(ans, min(Now[i], i - q.l + 1));
				Ans[q.i] = ans;
			}
		}
	}

	for(int i = 1; i <= q; ++i)
		printf("%d\n", Ans[i]);


	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/