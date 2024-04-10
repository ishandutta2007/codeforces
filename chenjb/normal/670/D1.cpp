#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k;
int a[100000],b[100000];
int l,r,m;
bool judge(int x)
{
	int t=k;
	long long target;
	for(int i=1;i<=n;i++)
	{
        target=(long long)(a[i])*x;
		if (target>b[i]+t) return false;
		else if (target>b[i]) t=t-(target-b[i]);
	}
	return true;
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	l=0;
    r=1000000001;
    while (l<r)
    {
    	m=((l+r)/2)+1;
    	if (judge(m)) l=m;
    	else r=m-1;
    }
    cout<<l<<endl;
    return 0;
}