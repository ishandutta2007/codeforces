#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<algorithm>
#include<sstream>
#include<stdlib.h>
#include<queue>
#include<stack>
using namespace std;

#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define S(X) ((X)*(X))
#define ABS(X) ((X)>0?(X):(-(X)))

typedef __int64 LL;
typedef pair<int,int> PII;

double h[3004],r[3004],R[3004];
double bottom[3004];

double calc(int d,int u)
{
	double r1, r2, R1, R2, h1, h2, b, tb, hh, rr1, rr2, t;

	r1 = r[d];
	R1 = R[d];
	h1 = h[d];
	b = bottom[d];

	r2 = r[u];
	R2 = R[u];
	h2 = h[u];

	if(r2 >= R1) return b+h1;


	if(r2 < r1) 
	{
		hh = MIN(h1, h2);
		rr1 = r1 + (R1-r1)/h1*hh;
		rr2 = r2 + (R2 - r2)/h2*hh;

		if(rr2 <= rr1) return b;

		t = (R1 - r2)*h2/(R2-r2);
		if(t<=h2) return b+h1-t;

		t = (R2 - r1)*h1/(R1-r1);
		return b+t-h2;
	}
	else
	{
		tb = (r2 - r1)*h1/(R1-r1);

		if( (R2-r2)*h1 <= (R1-r1)*h2 )
			return tb+b;

		t = (R1 - r2)*h2/(R2-r2);
		if(t<=h2) return b+h1-t;

		t = (R2 - r1)*h1/(R1-r1);
		return b+t-h2;
	}

}

int main()
{
	double ans=0,temp;
	int i,j,n;

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%lf%lf%lf",&h[i],&r[i],&R[i]);

	ans = h[0];
	bottom[0]=0;
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			temp = calc(j,i);
			bottom[i] = MAX(bottom[i], temp);
		}

		ans = MAX(ans, bottom[i] + h[i]);
	}

	printf("%.8lf\n",ans);

	return 0;
}