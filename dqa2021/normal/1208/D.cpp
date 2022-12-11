#include<bits/stdc++.h>
#define pb push_back
using namespace std;

//#define DEBUG
#ifdef DEBUG
template<typename ...Args>
int debug(const Args &...args){
	return fprintf(stderr,args...);
}
#else
#define debug(...) void()
#endif

typedef unsigned long long ull;
typedef unsigned uint;
typedef long long ll;
#define G getchar()
ll read()
{
	ll x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
/*
const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
*/
//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n; ll w[200010];
int p[200010];

ll tri[200010];
void add(int x,int w){
	for (;x<=n;x+=x&-x) tri[x]+=w;
}
ll ask(int x){
	ll z=0;
	for (;x;x-=x&-x) z+=tri[x];
	return z;
}

void solve(){
	n=read();
	rep(i,1,n) w[i]=read();
	set<int> st;
	rep(i,1,n) st.insert(i);
	rep(i,1,n) add(i,i);
	per(i,1,n){
		if (!w[i]){
			auto it=st.begin();
			p[i]=*it;
			st.erase(it);
			add(p[i],-p[i]);
			continue;
		}
		int l=1,r=n,mid;
		while (l<r){
			mid=l+r>>1;
			if (ask(mid)>=w[i]) r=mid;
			else l=mid+1;
		}
		auto it=st.upper_bound(r);
		p[i]=*it;
		st.erase(it);
		add(p[i],-p[i]);
	}
	rep(i,1,n) printf("%d ",p[i]);
	puts("");
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}