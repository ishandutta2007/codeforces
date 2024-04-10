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
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,i,num;
	cin>>n;
	vector<ll> zero,div3,rem1,rem2;
	for(i=0;i<n;i++)
	{
		cin>>num;
		if(num==0)
			zero.pb(num);
		else if(num%3==0)
			div3.pb(num);
		else if(num%3==1)
			rem1.pb(num);
		else rem2.pb(num);
	}
	if(zero.empty())
	{
		cout<<-1;return 0;
	}
	if(div3.empty()&&rem1.empty() && rem2.empty())
	{
		cout<<0;return 0;
	}
	sort(all(rem1));sort(all(rem2));
	ll temp=rem1.size()+2*rem2.size();temp%=3;
	if(temp==1)
	{
		if(rem1.empty())
		{
			if(rem2.size()<=2)rem2.clear();
			else
			{
				auto it=rem2.begin();
				rem2.erase(it);it++;rem2.erase(it);
			}
		}
		else rem1.erase(rem1.begin());
	}
	if(temp==2)
	{
		if(rem2.empty())
		{
			if(rem1.size()<=2)rem1.clear();
			else
			{
				auto it=rem1.begin();
				rem1.erase(it);it++;rem1.erase(it);
			}
		}
		else
			rem2.erase(rem2.begin());
	}
	if(div3.empty() && rem1.empty() && rem2.empty())
	{
		cout<<0;return 0;
	}
	for(auto j:rem1)zero.pb(j);
	for(auto j:rem2)zero.pb(j);
	for(auto j:div3)zero.pb(j);
		sort(all(zero),greater<ll>());
	for(auto j:zero)cout<<j;
	return 0;
}