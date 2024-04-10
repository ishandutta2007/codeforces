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

	ll t,t1,t2,n,x,m1,m2;
	cin>>t;
	while(t--)
	{
		cin>>n>>x;
		cin>>t1>>t2;
		m1=t1-t2;
		m2=t1;
		n--;
		while(n--)
		{
			cin>>t1>>t2;
			m1=max(t1-t2,m1);
			m2=max(m2,t1);
		}
		if(m2<x && m1<=0)
		{
			cout<<"-1\n";continue;
		}
		if(m2>=x)
		{
			cout<<"1\n";
			continue;
		}
		x-=m2;
		if(x%m1==0)
			cout<<x/m1+1<<endl;
		else
			cout<<x/m1+2<<endl;
		
	}
	return 0;
}