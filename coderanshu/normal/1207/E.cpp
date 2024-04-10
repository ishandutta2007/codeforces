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
ll fact[300005],n;
void form()
{
	fact[0]=fact[1]=1;
	for(auto i=2;i<=n+2;i++)
		fact[i]=fact[i-1]*i%MM;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll num1,num2,i,k,ans;
	cout<<"?";
	for(i=1;i<=100;i++)cout<<" "<<i;
	cout<<endl;
	cout<<flush;
	cin>>num1;
	cout<<"?";
	for(i=1;i<=100;i++)
	{
		cout<<" "<<(i<<7);
	}
	cout<<endl;
	cout<<flush;
	cin>>num2;
	ans=0;
	for(k=7;k<=13;k++)
	{
		if(num1&(1<<k))
			ans+=power(2,k);
	}
	for(k=0;k<=6;k++)
	{
		if(num2&(1<<k))
			ans+=power(2,k);
	}
	cout<<"! "<<ans;
	
	return 0;
}