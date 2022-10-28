#include<bits/stdc++.h>
using namespace std ;

#define modulo 1000000007
#define ll long long 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define mem0(a) memset(a,0,sizeof(a))
#define rep(i,a,b) for(i=a;i<b;i++)

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

	int n,num,z=0,p=0,i,l;
	cin>>n;
	l=(n/2)+(n%2==1);
	rep(i,0,n)
	{
		cin>>num;
		if(num>0)p++;
		if(num==0)z++;
	}
	if(p>=l)cout<<1;
	else
	{
		if(n-z-p>=l)cout<<-1;
		else cout<<0;
	}
	return 0;
}