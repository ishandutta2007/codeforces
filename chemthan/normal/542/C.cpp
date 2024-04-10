#include <iostream>
using namespace std;

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR2(i, a, b) for(int i = a; i < b; i++)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
long long gcd(long long a, long long b){long long r; while (b != 0){r = a % b; a = b; b = r;} return a;}
long long lcm(long long a, long long b){return a / gcd(a, b) * b;}

int n;
int f[200];
bool dfs_num[200];
int dfs_low[200];
long long l = 1;

void dfs(int i){
	dfs_num[i] = true;
	if (dfs_num[f[i]]) l = lcm(l, dfs_low[i] - dfs_low[f[i]] + 1); else {dfs_low[f[i]] = dfs_low[i] + 1; dfs(f[i]);}
}

int F(int u, long long k){
	FOR(i, k) u = f[u]; return u;
}

void solve(){
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	cin>>n;
	memset(dfs_num, 0, 200);
	memset(dfs_low, 0, 200 * sizeof(int));
	FOR(i, n) {cin>>f[i]; f[i]--;}
	FOR(i, n){
		memset(dfs_num, 0, 200);
		memset(dfs_low, 0, 200 * sizeof(int));
		if (dfs_num[i]) break; dfs(i);
	}
	if (l > n) {cout<<l; return;}
	long long k = 1;
	while (1){
		bool check = true;
		FOR(i, n) if (F(i, k * l) != F(i, k * 2 * l)) {check = false; break;}
		if (check) {cout<<k * l; return;}
		k++;
	}
}

int main(){
	solve();
	return 0;
}