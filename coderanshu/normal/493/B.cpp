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
int compare(vector<ll> fw,vector<ll> sw)
{
	ll k=min(fw.size(),sw.size());
	for(auto i=0;i<k;i++)
	{
		if(fw[i]>sw[i])
			return 1;
		else if(fw[i]<sw[i])
			return -1;
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,num,i,f=0,s=0,result;
	vector<ll> fw,sw;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>num;
		if(num>0)
		{
			f+=num;
			fw.pb(num);
		}
		else
		{
			s+=abs(num);
			sw.pb(abs(num));
		}
	}
	if(f>s)
		cout<<"first";
	else if(s>f)
		cout<<"second";
	else
	{
		result=compare(fw,sw);
		if(result==1)
		{
			cout<<"first";
		}
		else if(result==-1)
		{
			cout<<"second";
		}
		else
		{
			if(num>0)cout<<"first";
			else cout<<"second";
		}
	}
	return 0;
}