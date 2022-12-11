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
typedef pair<int,int> Pii;
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
#define forall(x,y) for (const int &y: e[x])

int n,w[2010],c[2010];

struct P{
	int x,y,id;
}p[2010];
P operator-(const P &x,const P &y){
	return (P){x.x-y.x,x.y-y.y,x.id};
}
ll cross(const P &x,const P &y){
	return 1LL*x.x*y.y-1LL*x.y*y.x;
}
bool operator<(const P &x,const P &y){
	const bool a=x.x>0||!x.x&&x.y>0;
	const bool b=y.x>0||!y.x&&y.y>0;
	if (a^b) return a>b;
	return cross(x,y)<0;
}

vector<Pii> S;

int fat[2010],siz[2010];
int find(int x){return fat[x]?fat[x]=find(fat[x]):x;}
bool merge(int x,int y){
	x=find(x),y=find(y);
	if (x==y) return 0;
	return fat[y]=x,1;
}

void solve(){
	n=read();
	rep(i,1,n){
		int x=read(),y=read(); w[i]=read();
		p[i]=(P){x,y,i};
	}
	if (is_sorted(w+1,w+n+1)) return puts("0"),void();
	rep(i,1,n){
		if (c[i]) continue;
		const int col=++*c;
		for (int j=i;!c[j];c[j]=col,j=w[j],++siz[col]);
	}
	//rep(i,1,n) printf("%d ",c[i]); puts("");
	int o=-1;
	rep(i,1,n) if (siz[c[i]]>1){o=i; break;}
	assert(~o);
	swap(p[o],p[1]);
	rep(i,2,n) p[i]=p[i]-p[1];
	sort(p+2,p+n+1);
	rep(i,2,n){
		const int u=p[i].id,v=p[i==n?2:i+1].id;
		if (cross(p[i],p[i==n?2:i+1])>0) continue;
		if (merge(c[u],c[v])) S.emplace_back(u,v),swap(w[u],w[v]);
	}
	for (int i=w[o];i^o;i=w[i]) S.emplace_back(o,i);
	printf("%d\n",int(S.size()));
	for (const auto &[x,y]: S) printf("%d %d\n",x,y);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}