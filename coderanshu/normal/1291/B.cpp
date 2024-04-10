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

ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll t,n,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<int> a(n),b(n),c(n);
		for(i=0;i<n;++i)cin>>a[i];
		for(i=0;i<n;++i){b[i]=i;c[i]=n-1-i;}
		for(i=0;i<n;++i)
		{
			if(a[i]>=b[i])continue;
			else break;
		}
		if(i==n)
		{
			cout<<"Yes\n";continue;
		}
		for(j=n-1;j>=i-1;--j)
		{
			if(a[j]<c[j])break;
		}
		if(j==i-2)cout<<"Yes";
		else cout<<"No";
		cout<<endl;

	}
	return 0;
}