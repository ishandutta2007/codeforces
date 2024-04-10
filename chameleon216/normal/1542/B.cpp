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






int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll a,b,n;
		scanf("%lld%lld%lld",&n,&a,&b);
		int bo=0;
		for(ll x=1;x<=n;x*=a)
		{
			if((n-x)%b==0){bo=1,printf("Yes\n");break;}
			if(a==1)break;
		}
		if(!bo)printf("No\n");
	}
	return 0;
}