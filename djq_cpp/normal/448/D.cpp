#include <iostream>
using namespace std;

int main()
{
	int n,m;
	long long t;
	cin>>n>>m>>t;
	//t=(long long)(n)*m+1-t;
	long long l=1LL,r=(long long)(n)*m+1;
	while(l<r)
	{
		long long mid=(l+r)>>1;
		long long cnt=0LL;
		for(int k=1;k<=n;k++)
		cnt+=min(mid/k,(long long)(m));
		if(cnt>=t)
		r=mid;
		else
		l=mid+1;
	}
	cout<<r;
	return 0;
}