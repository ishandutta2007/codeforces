#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;
typedef unsigned uint;
typedef long double ld;
typedef unsigned long long ull;

#define IO_FAST 0
#define MULTIPLE 1

const int MB=1<<21;
struct FastIO
{
	char buf[MB+100],*p,*e;
	int getChar()
	{
		if(p==e)p=buf,e=buf+fread(buf,1,MB,stdin);
		return p==e?EOF:*p++;
	}
#if !IO_FAST
#define getChar getchar
#endif
	template<typename T>
	FastIO& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getChar())l=c;
		for(x=0;isdigit(c);c=getChar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IO;

int mian();
int main()
{
	int t=1;
#if MULTIPLE
	IO>>t;
#endif
	while(t --> 0)mian();
}
#define main mian
//#define int long long

template<typename T>
inline T Abs(T x){return x>=0?x:-x;}

template<typename T,typename U>
bool max_eq(T& a,U b){return a<b?a=b,1:0;}
template<typename T,typename U>
bool min_eq(T& a,U b){return a>b?a=b,1:0;}

const int Inf=0x3f3f3f3f;
const ll InfL=0x3f3f3f3f3f3f3f3fll;

const int MX=100100;
int N;
ll A[MX],S[MX];

int main()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%lld",&A[i]);
	sort(A+1,A+N+1);
	Fr(i,1,N)S[i]=S[i-1]+A[i];
	ll ans=0;
	Fr(i,3,N)ans-=A[i]*(i-2)-S[i-2];
	printf("%lld\n",ans);
	return 0;
}