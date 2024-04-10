#include<bits/stdc++.h>
using namespace std;
int a[103],n,qzh[103],times;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	a[0]+=10;
	for(int i=0;i<n;i++)
		qzh[i+1]=qzh[i]+a[i];
	int i;
	for(i=1;i<=n&&qzh[i]<=720;i++)
		times=times+max(0,qzh[i]-360);
	cout<<(i==n+1?n:i-1)<<' '<<times;
}