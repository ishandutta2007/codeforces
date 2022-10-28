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

	ll st,i,di;
	string s,initial("$");
	bool neg=false;
	cin>>s;
	if(s=="0.000")
	{
		cout<<"$0.00";return 0;
	}
	st=0;
	if(s[0]=='-')
	{
		neg=true;st++;
	}
	di=-1;
	for(i=st;s[i];i++)
	{
		if(s[i]=='.')
		{
			di=i;
			break;
		}
		else
			initial+=s[i];
	}
	ll ci=initial.length();
	ci-=4;
	initial+=".";
	
	if(ci>=1)
	{
	for(i=ci;i>=1;i-=3)
	{
		initial.insert(i+1,",");
	}
	}
	if(di!=-1)
	{
		if(di+2<s.length())
		{
			initial+=s[di+1];
			initial+=s[di+2];
		}
		else if(di+1<s.length())
		{
			initial+=s[di+1];initial+="0";
		}
	}
	else
	{
		initial+="00";
	}
	if(neg)cout<<"("<<initial<<")";
	else
		cout<<initial;
		
	return 0;
}