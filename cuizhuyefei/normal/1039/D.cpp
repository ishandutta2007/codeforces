#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 233333;
Vi e[N];int n,fa[N],dep[N],ans[N],s[N],f[100200];
void DFS(int u, int Fa, int Dep){
	fa[u]=Fa;dep[u]=Dep;
	per(i,SZ(e[u])-1,0)if(e[u][i]!=Fa)DFS(e[u][i],u,Dep+1);
}
bool cmp(int u, int v){return dep[u]>dep[v];}
inline void solve(int k){
	if(ans[k]>=0)return;memset(f,0,4*(n+2));ans[k]=0;
	rep(t,1,n){
		int u=s[t];f[u]++;//if(k==3)printf("%d:%d\n",u,f[u]);
		if(f[u]>=k)ans[k]++;
		else if(f[fa[u]]+f[u]+1>=k)f[fa[u]]=k-1;
		else f[fa[u]]=max(f[fa[u]],f[u]);
	}
}
int main() {//freopen("1.in","r",stdin);
	read(n);rep(i,2,n){int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);}
	DFS(1,0,0);rep(i,1,n)s[i]=i;sort(s+1,s+n+1,cmp);
	int m=min((int)(sqrt(n*40)),n);memset(ans,-1,sizeof(ans));
	rep(i,1,m)solve(i);
	rep(i,m+1,n){
		solve(i);int l=i+1,r=n,pos=i;
		while(l<=r){
			int mid=(l+r)>>1;solve(mid);
			if(ans[mid]==ans[i])pos=mid,l=mid+1;else r=mid-1;
		}
		rep(j,i,pos)ans[j]=ans[i];i=pos;
	}
	rep(i,1,n)printf("%d\n",ans[i]);
	return 0;
}