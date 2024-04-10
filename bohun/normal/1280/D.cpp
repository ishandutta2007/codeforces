#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cout << #x << " = " << x << endl

using namespace std;

const int nax = 3005;

int n, m;
vector <int> v[nax];
int a, b;
int B[nax], W[nax];
pair<int,ll> dp[nax][nax][2];
pair<int,ll> dp2[nax][2];
int siz[nax];

pair<int,ll> merge1(pair<int,ll> A, pair<int,ll> B) {
	pair<int,ll> C;
	C.fi = A.fi + B.fi;
	C.se = A.se;
	return C;
}

pair<int,ll> merge2(pair<int,ll> A, pair<int,ll> B) {
	pair<int,ll> C;
	C.fi = A.fi + B.fi;
	C.se = A.se + B.se;
	return C;
}

void napraw(pair<int,ll> &A) {
	if(A.se > 0)
		A.fi++;
	A.se = 0;
}
	
	

void dfs(int u, int p) {
	//cat("elo");
	//cat(u);
	siz[u] = 1;
	dp[u][1][1] = mp(0, W[u] - B[u]);
	dp[u][1][0] = mp(0, W[u] - B[u]);
	for(auto it : v[u]) {
		if(it == p) continue;
		
		dfs(it, u);
		
		for(int i = 1; i <= min(m, siz[it] + siz[u]); ++i) {
			dp2[i][0] = mp(-1, 0);
			dp2[i][1] = mp(-1, 0);
		}
		
		for(int i = 1; i <= siz[u]; ++i)
			for(int j = 1; j <= siz[it] && i + j <= m + 1; ++j) {
				
				dp2[i + j][1] = max(dp2[i + j][1], merge1(dp[u][i][1], dp[it][j][1]));
				dp2[i + j - 1][1] = max(dp2[i + j - 1][1], merge2(dp[u][i][1], dp[it][j][0]));
				
				dp2[i + j][0] = max(dp2[i + j][0], merge1(dp[u][i][0], dp[it][j][1]));
				dp2[i + j - 1][0] = max(dp2[i + j - 1][0], merge2(dp[u][i][0], dp[it][j][0]));
			}
		
		for(int i = 1; i <= min(m, siz[it] + siz[u]); ++i) {
			dp[u][i][0] = dp2[i][0];
			dp[u][i][1] = dp2[i][1];
		}
		
		siz[u] += siz[it];
	}
	for(int i = 1; i <= min(m, siz[u]); ++i)
			napraw(dp[u][i][1]);
		
	/*cat(u);	
	for(int i = 1; i <= 2; ++i) {
		cat(i);
		cat(dp[u][i][0].fi);
		cat(dp[u][i][0].se);
		cout << endl;
		
		cat(dp[u][i][1].fi);
		cat(dp[u][i][1].se);
	}
	* */
	
}
				
				
		
		

void go() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		v[i].clear();
	for(int i = 1; i <= n; ++i)
		scanf("%d", B + i);
	for(int i = 1; i <= n; ++i)
		scanf("%d", W + i);
	for(int i = 1; i < n; ++i) {
		scanf("%d %d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= m; ++j) {
			dp[i][j][0] = mp(-1, 0);
			dp[i][j][1] = mp(-1, 0);
		}
	
	dfs(1, 0);
	
	printf("%d\n", dp[1][m][1].fi);
}
	
	


int main() {
	int T;
	scanf("%d", &T);
	while(T--)
		go();
	
	return 0;
}