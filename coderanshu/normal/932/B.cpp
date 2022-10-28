#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e18
#define endl "\n"
int pro(int n)
{
	int ans=1;
	while(n!=0)
	{
		if(n%10)
		ans*=n%10;n/=10;
	}
	return ans;
}
int func(int n)
{
	if(n<10)return n;
	return func(pro(n));
}
int a[1000002][10];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i,z;
	mem0(a);	
	for(i=1;i<=1000000;i++)
	{
		z=func(i);
		a[i][z]=a[i-1][z]+1;
		for(int k=1;k<=9;++k)
		{
			if(k!=z)a[i][k]=a[i-1][k];
		}
	}
	int t;
	cin>>t;
	for(i=0;i<t;i++)
	{
		int l,r,kk;
		cin>>l>>r>>kk;
		cout<<a[r][kk]-a[l-1][kk]<<endl;
	}
	return 0;
}