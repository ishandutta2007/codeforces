#include"bits/stdc++.h"


#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define iout(x) printf("%d\n",x)
#define lout(x) printf("%lld\n",x)
#define REP(x,l,u) for(ll x = (l);x<=(u);x++)
#define RREP(x,l,u) for(ll x = (l);x>=(u);x--)
#define mst(x,a) memset(x,a,sizeof(x))
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair
#define se second
#define fi first
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define sz(x) ((int)x.size())
#define cl(x) x.clear()

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
using namespace std;

const int maxn = 100010;
const int mod = 1e9+7;
const double eps = 1e-6;
const double PI = acos(-1);

template<typename T> inline void read(T &x){
x=0;T f=1;char ch;do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');do x=x*10+ch-'0',ch=getchar();while(ch<='9'&&ch>='0');x*=f;
}

template<typename A,typename B> inline void read(A&x,B&y){read(x);read(y);}
template<typename A,typename B,typename C> inline void read(A&x,B&y,C&z){read(x);read(y);read(z);}
template<typename A,typename B,typename C,typename D> inline void read(A&x,B&y,C&z,D&w){read(x);read(y);read(z);read(w);}
template<typename A,typename B> inline A fexp(A x,B p){A ans=1;for(;p;p>>=1,x=1LL*x*x%mod)if(p&1)ans=1LL*ans*x%mod;return ans;}
template<typename A,typename B> inline A fexp(A x,B p,A mo){A ans=1;for(;p;p>>=1,x=1LL*x*x%mo)if(p&1)ans=1LL*ans*x%mo;return ans;}

ll f,T,t0,a1,t1,p1,a2,t2,p2;

ll ans;

void Work(){
	ans=1e18;
	REP(i,0,f/a1+1){
		if(t2>=t0){
			if(min(i*a1,f)*t1+max(0ll,f-i*a1)*t0<=T)ans=min(ans,i*p1);
		}
		else if(i*a1>=f){
			if(f*t1<=T)ans=min(ans,i*p1);
		}
		else{
			if(i*a1*t1+(f-i*a1)*t2>T)continue;
			if(i*a1*t1+(f-i*a1)*t0<=T){
				ans=min(ans,i*p1);
				continue;
			}
			ll nT=T-i*a1*t1;
			ll nf=f-i*a1;
			
			//type 2 use x bytes
			//x*t2+t0*(nf-x)<=nT
			//x*t2+t0*nf-t0*x<=nT
			//x*t2-x*t0<=nT-nf*t0
			//x*t0-x*t2>=nf*t0-nT
			//x>=(nf*t0-nT)/(t0-t2)
			ll x=(nf*t0-nT)/(t0-t2);
			if((nf*t0-nT)%(t0-t2))x++;
			ll tim=x/a2;
			if(x%a2)tim++;
			ans=min(ans,i*p1+tim*p2);
		}
	}
	swap(a1,a2);swap(t1,t2);swap(p1,p2);
	REP(i,0,f/a1+1){
		if(t2>=t0){
			if(min(i*a1,f)*t1+max(0ll,f-i*a1)*t0<=T)ans=min(ans,i*p1);
		}
		else if(i*a1>=f){
			if(f*t1<=T)ans=min(ans,i*p1);
		}
		else{
			if(i*a1*t1+(f-i*a1)*t2>T)continue;
			if(i*a1*t1+(f-i*a1)*t0<=T){
				ans=min(ans,i*p1);
				continue;
			}
			ll nT=T-i*a1*t1;
			ll nf=f-i*a1;
			
			//type 2 use x bytes
			//x*t2+t0*(nf-x)<=nT
			//x*t2+t0*nf-t0*x<=nT
			//x*t2-x*t0<=nT-nf*t0
			//x*t0-x*t2>=nf*t0-nT
			//x>=(nf*t0-nT)/(t0-t2)
			ll x=(nf*t0-nT)/(t0-t2);
			if((nf*t0-nT)%(t0-t2))x++;
			ll tim=x/a2;
			if(x%a2)tim++;
			ans=min(ans,i*p1+tim*p2);
		}
	}
	if(ans==1e18)cout<<-1<<endl;else cout<<ans<<endl;
}

void Init(){
	read(f,T,t0);
	read(a1,t1,p1);
	read(a2,t2,p2);
}

int main(){
	Init();
	Work();
	return 0;
}