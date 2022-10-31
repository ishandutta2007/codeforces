#include <bits/stdc++.h>
using namespace std;

const int N = 3005;
const int MOD = 1000000007;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int inv(int n){
    int x, y;
    int g = gcd(n,MOD, x, y);
    return (x%MOD+MOD)%MOD;
}

int n, D;
vector<int> adj[N];
int dp[N][N];

void dfs(int v){
	for(auto u : adj[v]) dfs(u);
	for(int d = 1; d<=n; d++){
		dp[v][d] = dp[v][d-1];
		int p = 1;
		for(auto u : adj[v]) grow(p, dp[u][d]);
		inc(dp[v][d], p);
	}
}

int solve(){
	if(D <= n) return dp[0][D];
	int res = 0;
	for(int i = 0; i<=n; i++){
		int tmp = dp[0][i];
		for(int j = 0; j<=n; j++)
			if(j != i) grow(tmp, mul(D-j, inv(j<i?i-j:i-j+MOD)));
		inc(res, tmp);
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> D;
	for(int i = 1; i<n; i++){
		int p; cin >> p; --p;
		adj[p].push_back(i);
	}
	dfs(0);
	cout << solve() << endl;
}