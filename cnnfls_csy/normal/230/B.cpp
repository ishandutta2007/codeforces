#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
long long nopri[1000005],n,m,i,j,x;
int main()
{
	nopri[1]=1;
	for (i=2;i<=1000000;i++)
	{
		if (!nopri[i])
		{
			for (j=2;i*j<=1000000;j++) nopri[i*j]=1;
		}
	}
	cin>>n;
	for (i=1;i<=n;i++)
	{
		scanf("%I64d",&x);
		if (sqr((long long)(sqrt(x)))!=x) {puts("NO");continue;}
		if (nopri[((long long)(sqrt(x)+1e-4))]) {puts("NO");continue;}
		puts("YES");
	}
	return 0;
}