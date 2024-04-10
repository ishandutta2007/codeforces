#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 2020;const ll inf=1e16;
int n,m,s,t,a[N];vector<Pii>e[N];
ll d1[N],d2[N],qz1[N][N],qz2[N][N],f[N][N],g[N][N],ans[N],pos[N];
int l1,l2,id1[N],id2[N],bel1[N],bel2[N],vis[N],cnt[N][N];
bool cmp1(int x, int y){return d1[x]<d1[y];}
bool cmp2(int x, int y){return d2[x]<d2[y];}
void dij(ll *dis, int s){
	rep(i,1,n)dis[i]=inf;dis[s]=0;
	static bool vis[N];rep(i,1,n)vis[i]=0;
	rep(ttt,1,n){
		int u=0;rep(i,1,n)if(!vis[i]&&(!u||dis[i]<dis[u]))u=i;
		vis[u]=1;rep(i,0,SZ(e[u])-1)if(dis[e[u][i].fi]>dis[u]+e[u][i].se)
			dis[e[u][i].fi]=dis[u]+e[u][i].se;
	}
}
int main() {
	read(n);read(m);read(s);read(t);
	rep(i,1,n)read(a[i]);
	rep(i,1,m){
		int u,v,w;read(u);read(v);read(w);
		e[u].pb(Pii(v,w));e[v].pb(Pii(u,w));
	}
	dij(d1,s);dij(d2,t);
	rep(i,1,n)id1[i]=i;sort(id1+1,id1+n+1,cmp1);
	rep(i,1,n)id2[i]=i;sort(id2+1,id2+n+1,cmp2);
	rep(i,1,n){
		int j=i;while(j+1<=n&&d1[id1[i]]==d1[id1[j+1]])j++;
		l1++;rep(k,i,j)bel1[k]=l1;i=j;
	//	rep(k,i,j)printf("%d ",id1[k]);printf(" | ");
	}//puts("");
	rep(i,1,n){
		int j=i;while(j+1<=n&&d2[id2[i]]==d2[id2[j+1]])j++;
		l2++;rep(k,i,j)bel2[k]=l2;i=j;
	//	rep(k,i,j)printf("%d ",id2[k]);printf(" | ");
	}//puts("");
	rep(j,0,n){
		int r=j;while(r+1<=n&&bel2[j]==bel2[r+1])r++;
		rep(k,j,r)vis[id2[k]]++;ll ans=0;int sum=r;
		cnt[0][bel2[j]]=sum;
		rep(i,1,n){
			int p=i;while(p+1<=n&&bel1[i]==bel1[p+1])p++;
			rep(k,i,p){if(!vis[id1[k]])ans+=a[id1[k]],sum++;vis[id1[k]]++;}
			qz1[bel1[i]][bel2[j]]=ans;cnt[bel1[i]][bel2[j]]=sum;i=p;
		}
		rep(i,1,n)vis[i]--;
		j=r;
	}
	memset(vis,0,sizeof(vis));
	rep(i,0,n){
		int r=i;while(r+1<=n&&bel1[i]==bel1[r+1])r++;
		rep(k,i,r)vis[id1[k]]++;ll ans=0;
		rep(j,1,n){
			int p=j;while(p+1<=n&&bel2[j]==bel2[p+1])p++;
			rep(k,j,p){if(!vis[id2[k]])ans+=a[id2[k]];vis[id2[k]]++;}
			qz2[bel1[i]][bel2[j]]=ans;j=p;
		}
		rep(i,1,n)vis[i]--;
		i=r;
	}
//	rep(i,0,l1){rep(j,0,l2)printf("%d ",cnt[i][j]);puts("");}puts("");
//	rep(i,0,l1){rep(j,0,l2)printf("%lld ",qz1[i][j]);puts("");}puts("");
//	rep(i,0,l1){rep(j,0,l2)printf("%lld ",qz2[i][j]);puts("");}puts("");
	rep(j,0,l2)pos[j]=l1+1,ans[j]=-inf;
	per(i,l1,0){
		per(j,l2,0){
			while(cnt[pos[j]-1][j]>cnt[i][j])pos[j]--,umax(ans[j],qz1[pos[j]][j]-g[pos[j]][j]);
			if(cnt[i][j]<n)f[i][j]=ans[j]-qz1[i][j];
		}
		ll Ans=-inf;int Pos=l2+1;
		per(j,l2,0){
			while(cnt[i][Pos-1]>cnt[i][j])Pos--,umax(Ans,qz2[i][Pos]-f[i][Pos]);
			if(cnt[i][j]<n)g[i][j]=Ans-qz2[i][j];
		}
	}
//	rep(i,0,l1){rep(j,0,l2)printf("%lld ",f[i][j]);puts("");}puts("");
//	rep(i,0,l1){rep(j,0,l2)printf("%lld ",g[i][j]);puts("");}puts("");
	if(f[0][0]>0)puts("Break a heart");
	else if(f[0][0]==0)puts("Flowers");
	else puts("Cry");
	return 0;
}