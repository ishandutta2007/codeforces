#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int,int> Pii;
#define reg register
#define mp make_pair
#define pb push_back
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=510,INF=1e9+10;

int n,m;
ll a[N],b[N];

ll x;

ll Calc(int i,ll c,ll s){
	if(!c) return 0;
	if(c>=(1ll<<i)) {
		return (1ll<<i)-1+Calc(i,c-(1ll<<i),s+(1ll<<i)*((1ll<<x)-1));
	}
	if(s>=c) return c;
	return Calc(i-1,c,s)+1;
}


int main(){
	n=rd(),m=rd();
	rep(i,0,n-1) a[i]=rd();
	while(m--) {
		int opt=rd();
		if(opt==1) {
			int x=rd();
			a[x]=rd();
		} else {
			rep(i,0,n-1) b[i]=a[i];
			x=rd();
			ll k=rd<ll>();
			ll s=0,ans=0;
			ll sum=0;
			rep(i,0,n-1) sum+=a[i]<<i;
			if(sum<k){ puts("-1"); continue; }
			//rep(i,0,n-1) cout<<a[i]<<' ';
			//puts("");

			rep(i,0,x) k-=a[i],s+=((1ll<<i)-1)*a[i];
			if(k<=0) {
				puts("0");
				continue;
			}
			rep(i,x+1,n-1) {
				ll c=min(a[i],k>>(i-x));
				ans+=((1ll<<(i-x))-1)*c;
				a[i]-=c,k-=c<<(i-x),s+=((1ll<<x)-1)*(c<<(i-x));
			}
			rep(i,x+1,n-1) if(a[i] && k) {
				assert((1ll<<(i-x))>=k);
				//cout<<"$"<<i-x<<' '<<k<<' '<<s<<' '<<Calc(i-x,k,s)<<endl;
				ans+=Calc(i-x,k,s),k=0;
				break;
			}
			ans+=k;
			rep(i,0,n-1) a[i]=b[i];
			printf("%lld\n",ans);
		}
	}
}