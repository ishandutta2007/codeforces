#include <bits/stdc++.h>
#define ll long long
 
using namespace std;

vector<vector<int> > columns;
vector<int> mxs;

bool cmp(int x, int y){
	return (mxs[x] > mxs[y]);
}

void solve(){
	int n, m;
	cin >> n >> m;
	columns.assign(m, {});
	mxs.assign(m, {});
	for (int i=0; i < n; ++i){
		for (int j=0; j < m; ++j){
			int x;
			cin >> x;
			columns[j].push_back(x);
		}
	}
	for (int i=0;i<m;++i){
		int M = -1;
		for (int j=0;j<n;++j) M = max(M, columns[i][j]);
		mxs[i] = M;
	}
	vector<int> C;
	for (int i=0; i < m; ++i) C.push_back(i);
	sort(C.begin(), C.end(), cmp);
	int dp[1<<n], dp2[1<<n];
	for (int i=0;i<(1<<n);++i) dp[i] = 0;
	for (int it=0; it < min(n, m); ++it){
		for (int e=0; e < (1<<n); ++e) dp2[e] = 0;
		int i = C[it];
		for (int add=0; add < (1<<n); ++add){
			int mx = 0;
			for (int e=0; e < n; ++e){
				int T = 0;
				for (int j=0; j < n; ++j){
					int ba = add&(1<<j);
					if (ba==0) continue;
					T += columns[i][(e+j)%n];
				}
				mx = max(mx, T);
			}
			int R = ((1<<n)-1)^add;
			int s = m;
			int copy = R;
			while (copy >= 0) {
				dp2[copy+add] = max(dp2[copy+add], mx + dp[copy]);
				if (copy==0) break;
				copy = (copy-1) & R;
			}
		}
		for (int e=0; e < (1<<n); ++e) dp[e] = dp2[e];
	}
	cout << dp[(1<<n)-1] << "\n"; 
}

int main()
{
	#ifdef LOCAL
	    freopen("H_input.txt", "r", stdin);
	    //freopen("B_output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	for (int i=0; i < t; ++i) solve();
}