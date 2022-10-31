#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
using namespace std;
double x[3000],y[3000];
int main()
{
	int n;
	double r;
    scanf("%d%lf",&n,&r);
    for(int i=1;i<=n;i++)
    {
        scanf("%lf",&x[i]);
        y[i]=r;
        for(int j=1;j<=i-1;j++)
        {
        	double t=sqrt(4*r*r-(x[i]-x[j])*(x[i]-x[j]))+y[j];
			y[i]=max(y[i],t);
		}
        printf("%.9lf%c",y[i],i==n?'\n':' ');
    }
    return 0;
}