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

double Calc(int n,int m)
{
	int c=n*(n-1)*(n-2)/6;
	double p3=1.0*(m*(m-1)*(m-2)/6)/c;
	double p2=1.0*(m*(m-1)/2*(n-m))/c;
	double p1=1.0*(m*(n-m)*(n-m-1)/2)/c;
	return 0.5*p1+p2+p3;
}

int main()
{
	int n;
	double p;
	scanf("%d%lf",&n,&p);
	Fr(i,0,n)
	{
		double q=Calc(n,i);
		if(q>=p){printf("%d\n",i);break;}
	}
	return 0;
}