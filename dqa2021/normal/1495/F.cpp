#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
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
#define all(x) (x).begin(),(x).end()
//typedef pair<int,int> P;
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
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)

int n,q;
int p[200010],a[200010],b[200010];
vector<int> e[200010];

int fat[200010],dep[200010],son[200010],siz[200010];
int top[200010],id[200010],dfn[200010];
ll w[200010],dp[200010];

void dfs1(int x,int f,int d){
	fat[x]=f; dep[x]=d; siz[x]=1;
	ll S=0;
	for (const int &y: e[x]){
		dfs1(y,x,d+1);
		siz[x]+=siz[y];
		if (siz[y]>siz[son[x]]) son[x]=y;
		S+=dp[y];
	}
	if (e[x].empty()) /*w[x]=*/dp[x]=min(a[x],b[x]);
	else w[x]=(a[x])-(min(0LL+a[x],b[x]-S)),dp[x]=min(a[x]+S,0LL+b[x]);
	//printf("node %d: dp %lld w %lld S %lld\n",x,dp[x],w[x],S);
}

void dfs2(int x,int t){
	top[x]=t; dfn[++*dfn]=x; id[x]=++*id;
	if (siz[x]==1) return;
	w[son[x]]+=w[x]; dfs2(son[x],t);
	for (const int &y: e[x]){
		if (y==son[x]) continue;
		w[y]+=w[x]; dfs2(y,y);
	}
}

int getlca(int x,int y){
	while (top[x]^top[y])
		if (dep[top[y]]<dep[top[x]]) x=fat[top[x]];
		else y=fat[top[y]];
	return dep[x]<dep[y]?x:y;
}

void solve(){
	n=read(),q=read();
	rep(i,1,n) p[i]=read();
	rep(i,1,n) a[i]=read();
	rep(i,1,n) b[i]=read();
	
	static int stk[200010],top;
	stk[0]=n+1; //p[0]=1e9;
	rep(i,1,n){
		while (top&&p[stk[top]]<p[i]) --top;
		//printf("%d -> %d\n",stk[top],i);
		e[stk[top]].pb(i);
		stk[++top]=i;
	}
	
	dfs1(n+1,0,1); dfs2(n+1,n+1);
	
	ll W=0;
	for (const int &y: e[n+1]) W+=dp[y];
	set<int> st;
	st.insert(1);
	
	static int mrk[200010]; mrk[n+1]=1;
	static bool inq[200010];
	
	while (q--){
		int y=read(); inq[y]^=1;
		int x=fat[y];
		if (inq[y]) ++mrk[x];
		else --mrk[x];
		if (!inq[y]&&!mrk[x]){
			const auto it=st.find(id[x]);
			assert(it!=st.end());
			auto s=it;
			int l=n+1;
			if ((++s)!=st.end()){
				const int t=getlca(x,dfn[*s]);
				if (dep[t]>dep[l]) l=t;
			}
			s=it;
			if (s!=st.begin()){
				const int t=getlca(x,dfn[*--s]);
				if (dep[t]>dep[l]) l=t;
			}
			W-=w[x]-w[l];
			//printf("unchange %d -> %d\n",l,x);
			st.erase(it);
		}
		else if (inq[y]&&mrk[x]==1){
			//printf("test x %d\n",x);
			const auto it=st.insert(id[x]).fi;
			auto s=it;
			int l=n+1;
			if ((++s)!=st.end()){
				const int t=getlca(x,dfn[*s]);
				//printf("get t %d s %d\n",t,*s);
				if (dep[t]>dep[l]) l=t;
			}
			s=it;
			if (s!=st.begin()){
				const int t=getlca(x,dfn[*--s]);
				//printf("get t %d s %d\n",t,*s);
				if (dep[t]>dep[l]) l=t;
			}
			W+=w[x]-w[l];
			//printf("change %d -> %d\n",l,x);
			st.insert(it,id[x]);
		}
		printf("%lld\n",W);
	}
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}