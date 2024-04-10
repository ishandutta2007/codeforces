#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[100003],b1,b2,tot=0;
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&b1);
	for(int i=1; i<n; i++)
	{
		scanf("%d",&b2);
		tot+=b2-b1;
		a[i]=b2-b1;
		b1=b2;
	}
	sort(a+1,a+n);
	for(int i=n-k+1; i<=n-1; i++) tot-=a[i];
	tot+=k;
	cout<<tot;
	return 0;
}