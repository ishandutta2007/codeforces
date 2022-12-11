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
#define forall(x,y) for (const int &y: e[x])
const int INF=1e9;

int n,a[500010];
P b[500010];
bool c[500010];

void solve(){
	n=read();
	rep(i,1,n) b[i]=P(read(),i);
	sort(b+1,b+n+1);
	
	priority_queue<int> A,B;
	set<P> st;
	rep(i,1,n) A.push(0),st.emplace_hint(st.end(),i,i);
	
	const auto cut=[&](const int &x){
		//printf(" cut %d\n",x);
		const auto suf=st.upper_bound(P(x,INF));
		auto it=suf; assert(it!=st.begin());
		--it; const auto [l,r]=*it; st.erase(it);
		//printf("  l %d r %d\n",l,r);
		assert(l<x);
		B.push(r-l+1); A.push(x-l); A.push(r-x+1);
		st.emplace_hint(suf,l,x-1);
		st.emplace_hint(suf,x,r);
		//printf("  test %d %d %d %d\n",l,x-1,x,r);
		//for (const auto &[l,r]: st) printf("  st %d %d\n",l,r);
	};
	const auto link=[&](const int &x){
		auto b=st.lower_bound(P(x,0));
		assert(b!=st.begin()&&b!=st.end()&&b->fi==x);
		auto a=b,c=b; --a; ++c;
		B.push(a->se-a->fi+1);
		B.push(b->se-b->fi+1);
		const int l=a->fi,r=b->se;
		A.push(b->se-a->fi+1);
		st.erase(a); st.erase(b);
		st.emplace_hint(c,l,r);
	};
	vector<P> S,T;
	const auto add=[&](int l,int r,vector<P> &S){
		//printf("    add %d %d\n",l,r);
		if ((r-l+1)&1) S.pb(r,c[r]);
		else S.pb(l+r>>1,c[r]^1),S.pb(r,c[r]);
	};
	const auto ins=[&](const int &x){
		S.clear();
		auto it=st.upper_bound(P(x,INF)); --it;
		if (x>1&&c[x]==c[x-1]){
			const auto &[l,r]=*--it;
			add(l,r,S);
			++it;
		}
		const auto &[l,r]=*it;
		add(l,r,S);
		if (x<n&&c[x]==c[x+1]){
			const auto &[l,r]=*++it;
			add(l,r,S);
			--it;
		}
	};
	const auto modify=[&](int l,int r,int w){
		rep(i,l,r) a[i]=w;
	};
	const auto work=[&](const int &x,const int &w){
		T.clear(); int lim;
		auto it=st.upper_bound(P(x,INF)); --it;
		if (x>1&&c[x]==c[x-1]){
			const auto &[l,r]=*--it;
			add(l,r,T);
			lim=l;
			++it;
		}
		else lim=it->fi;
		const auto &[l,r]=*it;
		add(l,r,T);
		if (x<n&&c[x]==c[x+1]){
			const auto &[l,r]=*++it;
			add(l,r,T);
			--it;
		}
		
		//printf("  work %d %d lim %d\n",x,w,lim);
		//for (const auto &[t,c]: S) printf("    S time %d col %d\n",t,c);
		//for (const auto &[t,c]: T) printf("    T time %d col %d\n",t,c);
		
		--lim;
		for (int i=0,j=0;i<int(S.size())&&j<int(T.size());){
			if (S[i].fi<T[j].fi){
				if (S[i].se^T[j].se){
					assert(T[j].se);
					modify(lim+1,S[i].fi,w);
				}
				lim=S[i].fi; ++i;
			}
			else{
				if (S[i].se^T[j].se){
					assert(T[j].se);
					modify(lim+1,T[j].fi,w);
				}
				lim=T[j].fi; ++j;
			}
		}
	};
	
	int len=0;
	per(_,1,n){
		const auto &[w,p]=b[_];
		const bool e=_==1||w^b[_-1].fi;
		//printf("work w %d p %d\n",w,p);
		ins(p);
		
		c[p]=1;
		if (p>1&&c[p]==c[p-1]) cut(p);
		if (p<n&&c[p]==c[p+1]) cut(p+1);
		if (p>1&&c[p]^c[p-1]) link(p);
		if (p<n&&c[p]^c[p+1]) link(p+1);
		
		work(p,w);
		
		if (!e) continue;
		while (B.size()&&A.top()==B.top()) A.pop(),B.pop();
		assert(A.size());
		len=max(len,A.top()-1>>1);
		
	}
	
	printf("%d\n",len);
	rep(i,1,n) printf("%d%c",a[i]," \n"[i==n]);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}