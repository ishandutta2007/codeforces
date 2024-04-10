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
	string s;
	int n,z,i,sum,e;
	cin>>n;
	while(n--)
	{
		cin>>s;
		z=sum=e=0;
		if(s=="0")
		{
			cout<<"red\n";
			continue;
		}
		for(i=0;s[i];i++)
		{
			if(s[i]=='0' && z==0)z=1;
			else if(s[i]%2==0)
			{
				sum+=s[i]-48;
				e=1;
			}
			else
				sum+=s[i]-48;
		}
		if(z && e && sum%3==0)
			cout<<"red\n";
		else
			cout<<"cyan\n";

	}
	return 0;
}