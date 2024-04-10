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
#define INF 

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
string str;
int func(ll l,ll r,ll &s,ll &f)
{
	if(f>s)
		{
			if((s+1<l || s+1>r) && (s<l || s>r)){str+="R";s++;}
				else
					str+="X";
				
		}
	if(f<s)
		{
				if((s-1<l || s-1>r) && (s<l || s>r)){str+="L";s--;}
				else
					str+="X";
		}
		return 0;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,m,l,r,s,f,i,j,prev,t;
	cin>>n>>m>>s>>f;
	str.clear();
	prev=1;
	for(i=1;i<=m;i++)
	{
		cin>>t>>l>>r;
		if(t==prev)
		{
			if(s!=f)
			func(l,r,s,f);
			prev++;
		}
		else
		{
			for(j=0;j<t-prev;j++)
			{
				if(s!=f)
				func(0,0,s,f);
				else
					break;
			}
			if(s!=f)
			func(l,r,s,f);
			prev=t+1;
		}
	}
	if(f>s)
	{
		while(f>s){str+="R";s++;}
	}
	else if(f<s)
	{
		while(f<s){str+="L";s--;}
	}
	cout<<str;
	return 0;
}