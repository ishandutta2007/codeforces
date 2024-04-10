#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,x) for(int i=H[x],y=E[i].y;i;i=E[i].nx,y=E[i].y)
using namespace std;
typedef long long ll;

template<typename T>
inline T Abs(T x){return x>=0?x:-x;}

template<typename T,typename U>
bool max_eq(T& a,U b){return a<b?a=b,1:0;}
template<typename T,typename U>
bool min_eq(T& a,U b){return a>b?a=b,1:0;}

const int Mod=1000000007;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n,ans=0;
		scanf("%lld",&n);
		for(ll i=1,x=1;x<=n;++i,x=lcm(x,i))
			ans+=n/x,ans%=Mod;//,printf("%lld\n",x);
		printf("%lld\n",(ans+n)%Mod);
	}
	return 0;
}