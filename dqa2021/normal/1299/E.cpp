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
#define F fflush(stdout)

int n;
int q[810],p[810];

bool ask(const vector<int> &S){
	printf("? %d",int(S.size()));
	for (int x: S) printf(" %d",x);
	puts(""); F;
	int z=read();
	assert(~z);
	return z;
}

void solve(){
	n=read();
	rep(i,1,n){
		vector<int> S(n);
		iota(all(S),1);
		S.erase(find(all(S),i));
		static int c=0;
		if (!ask(S)) continue;
		if ((++c)==1) q[1]=i,p[i]=-1;
		else{
			q[n]=i,p[i]=-1;
			break;
		}
	}
	for (int l=1,r=n-l+1,t=0;l+1<=r-1;l<<=1,r=n-l+1,++t){
		int s=0; const int L=l<<1;
		rep(i,1,l) s=(s+i)%L;
		rep(i,r,n) s=(s+i)%L;
		rep(i,1,n) if (~p[i]){
			vector<int> S={i}; int o=-1;
			rep(j,1,l) if ((s-j+p[i]+l)%l) S.pb(q[j]); else o=j;
			rep(j,r,n) S.pb(q[j]);
			assert(~o);
			if (((s-o+p[i]+L)%L==0)==ask(S));
			else p[i]|=1<<t;
		}
		for (int i=1;i<=l&&l+i<r-i;++i){
			vector<int> S;
			rep(j,1,n) if (~p[j]) S.pb(j);
			const int x=l+i,y=r-i;
			rep(j,1,n) if (p[j]%L==x%L){
				vector<int> T(S);
				T.erase(find(all(T),j));
				if (ask(T)){
					p[j]=-1; q[x]=j; break;
				}
			}
			rep(j,1,n) if (p[j]%L==y%L){
				vector<int> T(S);
				T.erase(find(all(T),j));
				if (ask(T)){
					p[j]=-1; q[y]=j; break;
				}
			}
		}
	}
	rep(i,1,n) p[q[i]]=i;
	if (p[1]*2>n){
		rep(i,1,n) p[i]=n-p[i]+1;
	}
	printf("!");
	rep(i,1,n) printf(" %d",p[i]);
	puts(""); F;
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}