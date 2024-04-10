#include<bits/stdc++.h>
using namespace std;
int a[100003],b[100003],s[100003];
int main()
{
	int n,m,mod;
	cin>>n>>m>>mod;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
		s[i]=s[i-1]+b[i];
	}
	for(int i=1;i<=n;i++)
	{
		int l=max(1,m+i-n),r=min(m,i);
		cout<<(a[i]+s[r]-s[l-1])%mod<<' ';
	}
}