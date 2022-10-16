#include<bits/stdc++.h>
using namespace std;
int n,m,a[103],ans;
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=n-1;m>0;i--)
		ans++,
		m-=a[i];
	cout<<ans;
}