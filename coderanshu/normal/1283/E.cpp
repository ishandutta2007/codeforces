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
	ll n,i,countmin,countmax;
	int m[200005];
	mem0(m);
	cin>>n;
	ll a[n];
	ll b[200005];mem0(b);
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		b[a[i]]=1;
	}
	sort(a,a+n);
	for(i=0;i<n;i++)
	{
		if(m[a[i]-1]==0)
			m[a[i]-1]=1;
		else if(m[a[i]]==0)m[a[i]]=1;
		else m[a[i]+1]=1;
	}
	countmax=0;
	for(i=0;i<=n+2;i++)
		if(m[i]==1)countmax++;
	countmin=0;
	for(i=1;i<=n+2;i++)
	{
		if(b[i]==1)
		{
			if(b[i-1]==1)
				b[i]=0;
			else if(b[i+1]==1)
			{
				b[i]=0;
				i++;
			}
			else 
			{
				b[i]=0;b[i+1]=1;i++;
			}
		}
	}
	for(i=0;i<=n+2;i++)
	{
		if(b[i]==1)countmin++;
	}
	cout<<countmin<<" "<<countmax;
	return 0;
}