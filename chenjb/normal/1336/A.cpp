#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second
#define py pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define dep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define lowbit(x) ((x) & -(x))
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 2e5 + 10;
int n, k;
vi G[N];
int dep[N];
ll sz[N]; 
vector<ll> ans;
void dfs(int x, int fa)
{
	dep[x] = dep[fa] + 1;
	sz[x] = 1;
	for(auto to : G[x])
	{
		if(to == fa) continue;
		dfs(to, x);
		sz[x] += sz[to];
	}
}

int main()
{	
	n = read();
	k = read();
	rep(i, 1, n - 1)
	{
		int x = read();
		int y = read();
		G[x].pb(y);
		G[y].pb(x);
	}
	dep[1] = 1;
	dfs(1, 0);
	rep(i, 1, n) ans.pb(sz[i] - dep[i]);
	sort(ALL(ans));
	reverse(ALL(ans));
	ll Ans = 0;
	rep0(i, n - k) Ans += ans[i];
	cout << Ans;

	return 0;
}