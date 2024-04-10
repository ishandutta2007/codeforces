#pragma GCC optimize("Ofast")

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
ll a,b,c,d,e,an1,an2,an3,an4,an5;
void func(ll &sum)
{
	an5+=sum/e;sum%=e;
	an4+=sum/d;sum%=d;
	an3+=sum/c;sum%=c;
	an2+=sum/b;sum%=b;
	an1+=sum/a;sum%=a;
	return ;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll n,i;
	cin>>n;
	ll arr[n];
	an1=an2=an3=an4=an5=0;
	for(i=0;i<n;i++)
		cin>>arr[i];
	cin>>a>>b>>c>>d>>e;
	ll sum=0;
	for(i=0;i<n;++i)
	{
		sum+=arr[i];
		func(sum);
	}
	cout<<an1<<" "<<an2<<" "<<an3<<" "<<an4<<" "<<an5<<endl<<sum;
	return 0;
}