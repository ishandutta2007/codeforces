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
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define forall(x,y) for (const int &y: e[x])

int n,m,q;
bitset<2048> b[2048];
int pop[2048];
set<P> st;
bitset<2048> d;

bool check(int s,int t){
	const auto &x=b[s],&y=b[t];
	const auto z=x&y;
	return z!=x&&z!=y;
}

void del(int x){
	auto it=st.find(P(pop[x],x)),pre=it,suf=it;
	assert(it!=st.end());
	if ((++suf)!=st.end()) d.reset(suf->se);
	d.reset(x);
	if (pre!=st.begin()&&suf!=st.end()){
		--pre;
		if (check(pre->se,suf->se)) d.set(suf->se);
	}
	st.erase(it);
}

void ins(int x){
	auto it=st.emplace(pop[x],x).fi,pre=it,suf=it;
	if ((++suf)!=st.end())
		d.reset(suf->se);
	if (pre!=st.begin()&&check((--pre)->se,x))
		d.set(x);
	if (suf!=st.end()&&check(x,suf->se))
		d.set(suf->se);
}

void getans(int s,int t){
	const auto &x=b[s],&y=b[t];
	int f=(x&~y)._Find_first(),g=(~x&y)._Find_first();
	assert(max(f,g)<2048);
	//if (f==2048||g==2048) return puts("-1"),void();
	if (s>t) swap(s,t);
	if (f>g) swap(f,g);
	printf("%d %d %d %d\n",s,f,t,g);
}

void solve(){
	n=read(),m=read(),q=read();
	rep(i,1,n) st.emplace(pop[i],i);
	while (q--){
		int x=read(),l=read(),r=read();
		bitset<2048> c; c.set();
		c=c>>l<<(l+2047-r)>>(2047-r);
		del(x);
		b[x]^=c; pop[x]=b[x].count();
		ins(x);
		int p=d._Find_first();
		if (p==2048) {puts("-1"); continue;}
		auto it=st.find(P(pop[p],p));
		assert(it!=st.end()&&it!=st.begin());
		getans(p,(--it)->se);
	}
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}