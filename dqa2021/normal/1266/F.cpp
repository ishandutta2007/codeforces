#include<bits/stdc++.h>
#define pb emplace_back
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
typedef pair<int,int> P;
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

int n;
struct E{
	int t,n;
}e[1000010];
int cnt=1,last[500010],deg[500010];
inline void addedge(int x,int y){
	e[++cnt]=(E){y,last[x]},last[x]=cnt;
	e[++cnt]=(E){x,last[y]},last[y]=cnt;
	deg[x]++,deg[y]++;
}
int ans[500010];

int dep[500010],fat[500010],maxd[500010];

void dfs0(int x,int f,int d){
	dep[x]=d;
	for (int i=last[x],v;i;i=e[i].n)
		if ((v=e[i].t)^f)
			dfs0(v,x,d+1);
}

vector<int> g[500010];

vector<P> S;

void dfs1(int x,int f,int d){
	fat[x]=f; dep[x]=d; maxd[x]=d;
	for (int i=last[x],v;i;i=e[i].n)
		if ((v=e[i].t)^f){
			dfs1(v,x,d+1);
			maxd[x]=max(maxd[x],maxd[v]);
			g[x].pb(maxd[v]-dep[x]);  // caution
		}
	sort(all(g[x]));
	if (g[x].size()>=2) S.pb(g[x][g[x].size()-2],x);
}

int h[500010];  // fat maxd

void dfs2(int x,int f,int d){
	h[x]=d;
	int fi=d,se=0;
	for (int i=last[x],v;i;i=e[i].n)
		if ((v=e[i].t)^f){
			const int w=maxd[v]-dep[x];
			if (w>fi) se=fi,fi=w;
			else if (w>se) se=w;
		}
	
	for (int i=last[x],v;i;i=e[i].n)
		if ((v=e[i].t)^f){
			const int w=maxd[v]-dep[x];
			dfs2(v,x,(w==fi?se:fi)+1);
		}
}

int check(int x,int d){
	//printf("check %d %d\n",x,d);
	if (d&1){
		const int dr=d+1>>1,dl=dr-1;
		int ltot=0,rtot=0;
		int C=g[x].size()-1;
		while (~C&&g[x][C]>=dr) rtot++,--C;
		while (~C&&g[x][C]>=dl) ltot++,--C;
		if (h[x]>=dr) rtot++;
		else if (h[x]>=dl) ltot++;
		//printf("ltot %d rtot %d\n",ltot,rtot);
		return rtot+min(1,ltot);
	}
	int z=0;
	
	int dm=d>>1;
	int atot=0,btot=0;
	int C=g[x].size()-1;
	while (~C&&g[x][C]>=dm) ++atot,--C;
	
	if (h[x]>=dm) ++atot;
	z=atot;
	if (h[x]>=dm) --atot;
	
	//printf("  ans1 %d dm %d C %d\n",z,dm,C);
	//for (int v: g[x]) printf("%d ",v); puts("");
	
	if (!fat[x]) return z;
	
	x=fat[x];
	C=g[x].size()-1;
	while (~C&&g[x][C]>=dm) ++btot,--C;
	if (h[x]>=dm) btot++;
	btot--;
	
	z=max(z,atot+btot);
	//printf("  ans2 %d\n",atot+btot);
	return z;
}

void solve(){
	n=read();
	rep(i,1,n-1) addedge(read(),read());
	rep(i,1,n) ans[1]=max(ans[1],deg[i]+1);
	
	{
	dfs0(1,0,1);
	int S=1;
	rep(i,2,n) if (dep[i]>dep[S]) S=i;
	dfs0(S,0,1);
	S=1;
	rep(i,2,n) if (dep[i]>dep[S]) S=i;
	const int D=dep[S]-1;
	rep(i,1,D) ans[i]=max(ans[i],2);
	rep(i,D+1,n) ans[i]=max(ans[i],1);
	}
	
	dfs1(1,0,1); dfs2(1,0,0);
	
	sort(all(S),[&](const P &x,const P &y){return x>y;});
	
	rep(i,2,n){
		while (S.size()&&S.back().fi<i/2) S.pop_back();
		for (const auto &[d,x]: S) ans[i]=max(ans[i],check(x,i));
	}
	
	rep(i,1,n) printf("%d ",ans[i]); puts("");
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}