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

ll power(ll b,ll e,ll m)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b%m,(e-1)/2,m)%m;
	else
		return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b,(e-1)/2);
	else
		return power(b*b,e/2);
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long v,a[9],f[9],i,in,m;
	mem0(f);
	cin>>v>>a[0];
	m=a[0],in=0;
	for(auto i=1;i<9;i++)
	{
		cin>>a[i];
		if(a[i]<=m)
		{
			m=a[i];in=i;
		}
	}
	if(v<m)
	{
		cout<<-1;return 0;
	}
	for(auto j=0;j<9;j++)
		a[j]-=m;
	long nod=v/m;
	long rem=v%m;
	f[in]+=nod;
	for(i=8;i>in;i--)
	{
		if(nod>0)
		{
			f[i]+=rem/a[i];
			f[in]-=rem/a[i];
			nod-=rem/a[i];
			rem=rem%a[i];
		}
	}
	for(i=8;i>=0;i--)
	{
		for(auto j=0;j<f[i];j++)cout<<i+1;
	}

	return 0;
}