#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n;
double a[N],sz[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%lf",&a[i]),sz[i]=i;
	a[n+1]=N;
	for(int i=n;i>=1;--i)
	{
		double sum=a[i],cnt=1;
		int j=i+1;
		while(a[j]<a[i]){
			sum+=a[j]*(sz[j]-j+1);
			cnt+=sz[j]-j+1;
			a[i]=sum/cnt;
			sz[i]=sz[j];
			j=sz[j]+1;
		}
	}
	int j=1;
	while(j<=n)
	{
		for(int i=j;i<=sz[j];++i) a[i]=a[j];
		j=sz[j]+1;
	}
	for(int i=1;i<=n;++i) printf("%.10lf\n",a[i]);
}