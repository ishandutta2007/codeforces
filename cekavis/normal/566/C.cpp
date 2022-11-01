#include<bits/stdc++.h>

using namespace std;
#define ll long long

const double eps = 1e-8;
const int N = 200005;
int n, Size, ans, num, a[N], siz[N], h[N], e[N<<1], pre[N<<1], w[N<<1];
bool vis[N];
double Ans, f[N];
void add(int x, int y, int z){ e[++num]=y, w[num]=z, pre[num]=h[x], h[x]=num;}
pair<int,int> dfs(int u, int fa=0){
	pair<int,int> ans=make_pair(n, 0);
	int mx=0;
	siz[u]=1;
	for(int i=h[u]; i; i=pre[i]) if(e[i]!=fa && !vis[e[i]])
		ans=min(ans, dfs(e[i], u)), siz[u]+=siz[e[i]], mx=max(mx, siz[e[i]]);
	mx=max(mx, Size-siz[u]);
	return min(ans, make_pair(mx, u));
}
double calc(int u, int dep, int fa){
	double ans=sqrt(dep)*dep*a[u];
	f[Size]+=sqrt(dep)*a[u];
	for(int i=h[u]; i; i=pre[i]) if(e[i]!=fa) ans+=calc(e[i], dep+w[i], u);
	return ans;
}
void solve(int u, int _){
	Size=_, vis[u=dfs(u).second]=1;
	double sum=0, t=0;
	for(int i=h[u]; i; i=pre[i])
		f[Size=e[i]]=0, t+=calc(e[i], w[i], u), sum+=f[e[i]];
	if(t<Ans) Ans=t, ans=u;
	// printf("solve: %d %.10lf\n", u, t);
	for(int i=h[u]; i; i=pre[i]) if(!vis[e[i]])
		if(f[e[i]]*2>sum) solve(e[i], siz[e[i]]<siz[u]?siz[e[i]]:_-siz[u]);
}
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=1, x, y, z; i<n; ++i)
		scanf("%d%d%d", &x, &y, &z), add(x, y, z), add(y, x, z);
	Ans=1e100, solve(1, n);
	printf("%d %.10lf\n", ans, Ans);
	return 0;
}