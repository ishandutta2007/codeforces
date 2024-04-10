#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	double ans;
	for(int i=1;i<=n;i++)
	{
		double x;
		scanf("%lf",&x);
		int t1=i-max(i-k+1,1)+1;
		int t2=k-(min(i+k-1,n)-i+1)+1;
		double t=abs(t2-t1)+1;
		ans=ans+t*x;
		//cout<<t<<endl;
	}
	ans/=(double)(n-k+1);
	printf("%.10lf\n",ans);
	return 0;
}