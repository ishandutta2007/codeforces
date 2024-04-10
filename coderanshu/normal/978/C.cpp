#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define rep(i,a,b) for(i=a;i<b;i++)
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e9
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll n,m,num,i,j;
	cin>>n>>m;
	ll a[n+1],b[m];
	a[0]=0;
	for(i=1;i<=n;i++)
	{
		cin>>num;
		a[i]=a[i-1]+num;
	}
	for(i=0;i<m;i++)
	{
		cin>>b[i];
	}
	ll k=0;
	for(i=0;i<m;i++)
	{
		while(a[k]<b[i] && k<n)k++;
		cout<<k<<" "<<b[i]-a[k-1]<<endl;
	}
	return 0;
}