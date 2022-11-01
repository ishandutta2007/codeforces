#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 755, M = 10000005;
int n, t, cnt, pos[N], p[N], f[M], fa[M], q[M], fail[M], ch[M][2];
bool vis[N], mat[N], a[N][N];
char s[M];
bool match(int x){
	for(int i=1; i<=n; ++i) if(!vis[i] && a[x][i]){
		vis[i]=1;
		if(!p[i] || match(p[i])) return p[i]=x, mat[x]=1;
	}
	return 0;
}
int main() {
	scanf("%d", &n);
	cnt=1;
	for(int i=1; i<=n; ++i){
		scanf("%s", s);
		int &p=pos[i];
		p=1;
		for(int j=0; s[j]; ++j){
			int &x=ch[p][s[j]-'a'];
			fa[x?x:x=++cnt]=p, p=x;
		}
		f[p]=i;
	}
	q[t=1]=1;
	for(int i=1; i<=t; ++i){
		int u=q[i];
		if(!f[u]) f[u]=f[fail[u]];
		for(int i=0; i<2; ++i) if(ch[u][i]){
			int x=fail[u];
			while(x && !ch[x][i]) x=fail[x];
			fail[ch[u][i]]=x?ch[x][i]:1;
			q[++t]=ch[u][i];
		}
	}
	for(int i=1; i<=n; ++i){
		a[i][f[fail[pos[i]]]]=1;
		for(int j=fa[pos[i]]; j; j=fa[j]) a[i][f[j]]=1;
	}
	for(int k=1; k<=n; ++k) for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j)
		a[i][j]|=a[i][k] && a[k][j];
	for(int i=1; i<=n; ++i) match(i), memset(vis, 0, sizeof vis);
	t=0;
	for(int i=1; i<=n; ++i) if(!mat[i]) q[++t]=i;
	printf("%d\n", t);
	for(int i=1; i<=t; ++i) for(int j=1; j<=n; ++j) if(a[q[i]][j] && !vis[j]){
		vis[j]=1;
		if(mat[p[j]]) q[++t]=p[j], mat[p[j]]=0;
	}
	for(int i=1; i<=n; ++i) if(!mat[i] && !vis[i]) printf("%d ", i);
	for(int i=1; i<=n; ++i) assert(!(mat[i] && vis[i]));
	return 0;
}