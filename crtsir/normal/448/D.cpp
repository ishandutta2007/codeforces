#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long Less(long long x)
{
	long long res=0;
	for(long long i=1;i<=n;i++)
		res=res+min(m,x/i);
	return res;
}
int main()
{
	cin>>n>>m>>k;
	long long l=1,r=n*m,res=0;
	while(l<=r)
	{
		long long mid=(l+r)>>1;
		//cout<<l<<' '<<r<<' '<<mid<<endl;
		if(Less(mid)>=k)
			res=mid,
			r=mid-1;
		else
			l=mid+1;
	}
	cout<<res;
}