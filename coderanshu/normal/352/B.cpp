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
#define pi 3.1415926536

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
	long n,i,dif,temp,num;
	bool ans;
	cin>>n;
	map<long,vector<long>> m;
	rep(i,0,n)
	{
		cin>>num;
		m[num].pb(i);
	}
	vector<pair<long,long>> v;
	for(auto j:m)
	{
		if(j.S.size()==1)
		{
			v.pb({j.F,0});
		}
		else
		{
			ans=true;
			dif=j.S[1]-j.S[0];
			for(temp=2;temp<j.S.size();temp++)
			{
				if(j.S[temp]-j.S[temp-1]!=dif)
				{
					ans=false;break;
				}
			}
			if(ans)
				v.pb({j.F,dif});
		}
	}
	cout<<v.size()<<endl;
	for(auto j:v)
	{
		cout<<j.F<<" "<<j.S<<"\n";
	}
	return 0;
}
// nice map indexing bro