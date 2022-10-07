#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,p,k,i,a[50005],b[50005],s;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s+=a[i]/2;
		b[i]=a[i]/2;
	}
	if(s<0)
	{
		for(i=1;i<=n&&s;i++)
			if(a[i]>0&&a[i]%2)
			{
				b[i]++;
				s++;
			}
	}
	else
		for(i=1;i<=n&&s;i++)
			if(a[i]<0&&a[i]%2)
			{
				b[i]--;
				s--;
			}
	for(i=1;i<=n;i++)
		printf("%d\n",b[i]);
}