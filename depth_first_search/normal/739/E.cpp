#include<bits/stdc++.h>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define uint unsigned int
#define LL long long
#define ull unsigned long long
#define swap(x,y) (x^=y,y^=x,x^=y)
#define abs(x) ((x)<0?-(x):(x))
#define INF 1e9
#define Inc(x,y) ((x+=(y))>=MOD&&(x-=MOD))
#define ten(x) (((x)<<3)+((x)<<1))
#define N 100000
#define eps 1e-12
using namespace std;
int n,A,B;double s1[N+5],s2[N+5];
class Class_WQS
{
	private:
		double C1,C2,f[N+5];int g1[N+5],g2[N+5];
		inline void check()
		{
			for(register int i=1;i<=n;++i)
			{
				f[i]=f[i-1],g1[i]=g1[i-1],g2[i]=g2[i-1];
				if(f[i-1]+(s1[i]-C1)-f[i]>eps) f[i]=f[i-1]+(s1[i]-C1),g1[i]=g1[i-1]+1,g2[i]=g2[i-1];
				if(f[i-1]+(s2[i]-C2)-f[i]>eps) f[i]=f[i-1]+(s2[i]-C2),g1[i]=g1[i-1],g2[i]=g2[i-1]+1;
				if(f[i-1]+(s1[i]+s2[i]-C1-C2-s1[i]*s2[i])-f[i]>eps) f[i]=f[i-1]+(s1[i]+s2[i]-C1-C2-s1[i]*s2[i]),g1[i]=g1[i-1]+1,g2[i]=g2[i-1]+1;
 			}
 		}
 		inline void GetRes()
 		{
			register double l=0.0,r=1.0;
			for(C2=(l+r)/2;r-l>eps;C2=(l+r)/2) 
			{
				if(check(),!(g2[n]^B)) return;
				g2[n]>B?l=C2:r=C2;
			}
		}
	public:
		inline double GetAns()
		{
			register double l=0.0,r=1.0;
			for(C1=(l+r)/2;r-l>eps;C1=(l+r)/2) 
			{
				if(GetRes(),!(g1[n]^A)) break;
				g1[n]>A?l=C1:r=C1;
			}
			return f[n]+A*C1+B*C2;
		}
}WQS;
int main()
{
    register int i;
    while(~scanf("%d%d%d",&n,&A,&B))
    {
    	for(i=1;i<=n;++i) scanf("%lf",&s1[i]);
    	for(i=1;i<=n;++i) scanf("%lf",&s2[i]);
    	printf("%.10lf\n",WQS.GetAns());
	}
    return 0;
}