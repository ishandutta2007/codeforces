#include<bits/stdc++.h>  
using namespace std;
typedef long long ll;
const int M=998244353;
int n,p[105],i,k1,k2,j;
unsigned long long a[3000005],b[3000005],u,l,r;
ll y;
bool check(unsigned long long lim)
{
	int i,j=k2;
	long long ans=0;
	for(i=1;i<=k1;i++)
	{
		while(j&&a[i]*b[j]>lim)
			j--;
		ans+=j;
	}
	return ans<y;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&p[i]);
	cin>>y;
	a[k1=1]=1;
	for(i=1;i<=n;i+=2)
		for(j=k1;j>=1;j--)
			for(u=p[i];u*a[j]<=1000000000000000000ll&&u*a[j]%M==(u%M)*(a[j]%M)%M;u*=p[i])
				a[++k1]=u*a[j];
	b[k2=1]=1;
	for(i=2;i<=n;i+=2)
		for(j=k2;j>=1;j--)
			for(u=p[i];u*b[j]<=1000000000000000000ll&&u*b[j]%M==(u%M)*(b[j]%M)%M;u*=p[i])
				b[++k2]=u*b[j];
	sort(a+1,a+1+k1);
	sort(b+1,b+1+k2);
	l=1;r=1000000000000000000ll;
	while(l<r)
	{
		unsigned long long mid=(l+r)/2;
		if(check(mid))
			l=mid+1;
		else
			r=mid;
	}
	cout<<l<<endl;
}