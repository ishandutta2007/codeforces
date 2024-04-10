#include<iostream>
using namespace std;
int a[300001],n,can,sum[300002],no;
bool cdt(int x)
{
	for(int i=1;i+x<=n+1;i++)
		if(sum[i+x]-sum[i]+can>=x)
		{
			no=i;
			return true;
		}
	return false;
}
int main()
{
	int i;
	cin>>n>>can;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
		sum[i+1]=sum[i]+a[i];
	int lwb=0,upb=n+1,mid;
	while(upb-lwb>1)
	{
		mid=(lwb+upb)/2;
		if(cdt(mid))
			lwb=mid;
		else
			upb=mid;
	}
	cout<<lwb<<"\n";
	for(i=no;i<no+lwb;i++)
		a[i]=1;
	for(i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
}
/*1
7 1
1 0 0 1 1 0 1
*/
/*2
10 2
1 0 0 1 0 1 0 1 0 1
*/