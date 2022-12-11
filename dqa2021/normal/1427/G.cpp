#include<bits/stdc++.h>
#define pb emplace_back
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
typedef long long ll;
/*const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}*/
typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l);i<=(r);i++)
#define per(i,l,r) for (int i(r);i>=(l);i--)
const int INF=1e9;

int n; int a[210][210];
int gethash(int x,int y){return (x-1)*n+y;}

struct E{
	int t,n,v;
}e[1<<18];
int cnt=1,last[40010],S,T;
inline void addedge(int x,int y,int u,int v){
	//printf("addedge cnt %d %d:  %d %d  %d %d\n",cnt+1,cnt+2,x,y,u,v);
	e[++cnt]=(E){y,last[x],u},last[x]=cnt;
	e[++cnt]=(E){x,last[y],v},last[y]=cnt;
}
int dep[40010],que[40010],hd,tl,pid[40010];
bool bfs(){
	memset(dep+1,-1,T<<2); hd=tl=0;
	dep[S]=1; que[++tl]=S;
	while (hd<tl){
		int u=que[++hd],v;
		for (int i=last[u];i;i=e[i].n)
			if (e[i].v&&!~dep[v=e[i].t]){
				dep[v]=dep[u]+1; pid[v]=i;
				if (v==T) return 1;
				que[++tl]=v;
			}
	}
	return 0;
}
bool ibfs(int x){
	memset(dep+1,-1,T<<2); hd=tl=0;
	dep[x]=1; que[++tl]=x;
	while (hd<tl){
		int u=que[++hd],v;
		for (int i=last[u];i;i=e[i].n)
			if (e[i^1].v&&!~dep[v=e[i].t]){
				dep[v]=dep[u]+1; pid[v]=i;
				if (v==T) return 1;
				que[++tl]=v;
			}
	}
	return 0;
}

int del(int x,int d){
	int res=e[d^1].v;
	//printf("  test del %d %d  %d\n",x,d,e[d^1].v);
	e[d].v=e[d^1].v=0;
	rep(t,1,res){
		assert(ibfs(x));
		for (int i=T;i^x;i=e[pid[i]^1].t) e[pid[i]].v++,e[pid[i]^1].v--;
	}
	return res;
}

vector<P> C;
int d[40010];

void solve(){
	n=read(); S=n*n+1,T=S+1;
	rep(i,1,n) rep(j,1,n) a[i][j]=read();
	rep(i,1,n)
		rep(j,1,n){
			if (i<n&&~a[i][j]&&~a[i+1][j])
				addedge(gethash(i,j),gethash(i+1,j),1,1);
			if (j<n&&~a[i][j]&&~a[i][j+1])
				addedge(gethash(i,j),gethash(i,j+1),1,1);
		}
	ll ans=0;
	rep(i,1,n) rep(j,1,n){
		if (1<i&&i<n&&1<j&&j<n) continue;
		//if (!(1<i&&i<n)&&j<n) ans+=abs(a[i][j]-a[i][j+1]);
		//if (!(1<j&&j<n)&&i<n) ans+=abs(a[i][j]-a[i+1][j]);
		C.pb(a[i][j],gethash(i,j));
		d[gethash(i,j)]=cnt+1;
		addedge(S,gethash(i,j),INF,0);
	}
	//printf("test subans %lld\n",ans);
	sort(C.begin(),C.end());
	int flw=0;
	while (C.size()>1){
		const auto &[V,x]=C.back();
		C.pop_back();
		flw-=del(x,d[x]);
		//printf("  test A flw %d\n",flw);
		addedge(x,T,INF,0);
		while (bfs()){
			for (int i=T;i^S;i=e[pid[i]^1].t) e[pid[i]].v--,e[pid[i]^1].v++;
			flw++;
		}
		//printf("  test B flw %d\n",flw);
		//printf("delta %d\n",V-C.back().fi);
		ans+=(V-C.back().fi)*1LL*flw;
	}
	printf("%lld\n",ans);
}
int main()
{
	for (int T=1;T--;) solve();
}