#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
long long k;
long long a[110000],b[110000];
long long l,r,m;
long long test(long long x)
{
	long long t=0;
	for(int i=1;i<=n;i++)
	{
		if (a[i]*x-b[i]>0) t+=a[i]*x-b[i];
		if (t>k) break;
	}
    return t;
}
int main()
{

	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	l=0;
    r=2000000001;
    while (l<=r)
    {
    	m=(l+r)/2;
    	long long need=test(m);
    	if (need==k){ l=m; r=m; break; }
    	else if (need<k)l=m+1;
    	else r=m-1;
    }
    cout<<r<<endl;
    return 0;
}