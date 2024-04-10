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
#define rep(i,a,b) for(i=a;i<b;i++)
#define F first
#define S second

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
	ll r=-1,l=-1,n,i;
	string s;
	cin>>n;
	cin>>s;
	l=-1;
	r=n;
	for(i=0;i<n;i++)
	{
		if(s[i]=='>')
		{
			r=i;
			break;
		}
	}
	for(i=n-1;i>=0;i--)
	{
		if(s[i]=='<')
		{
			l=i;
			break;
		}
	}
	ll ans=0;
	for(i=0;i<n;i++)
	{
		if(s[i]=='<' && r>=i)
			ans++;
		else if(s[i]=='>' && l<=i)
			ans++;
	}
	cout<<ans;

	return 0;
}