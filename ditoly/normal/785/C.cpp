#include<iostream>
using namespace std;
int main()
{
	long long n,m,l,r,mid,ans;
	cin>>n>>m;
	if(m>n)return cout<<n,0;
	for(l=0,r=3000000000;l<=r;)
	{
		mid=l+r>>1;
		if(mid*(mid+1)>>1>=n-m)ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans+m;
}