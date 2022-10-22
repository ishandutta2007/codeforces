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
		int n,x,c[2]={0};
		scanf("%d",&n);
		Fr(i,1,n*2)scanf("%d",&x),++c[x&1];
		printf(c[0]==c[1]?"Yes\n":"No\n");
	}
	return 0;
}