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

template<typename T,typename U>
void max_eq(T& a,const U& b){if(a<b)a=b;}
template<typename T,typename U>
void min_eq(T& a,const U& b){if(b<a)a=b;}

const int MX=100100;
int N;
struct Pt{ll a,b;}P[MX];
bool operator<(const Pt& x,const Pt& y){return x.b>y.b;}

int main()
{
	scanf("%d",&N);
	ll sum=0;
	Fr(i,1,N)scanf("%lld%lld",&P[i].a,&P[i].b),sum+=P[i].a;
	sort(P+1,P+N+1);
	ll c=sum;
	Fr(i,1,N)
	{
		ll x=c-P[i].b;
		max_eq(x,0),min_eq(x,P[i].a);
		c-=x;
	}
	printf("%lld\n",sum+c);
	return 0;
}