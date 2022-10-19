#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define prt(n) cout<<(n)<<endl
#define elif else if
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
bool prime(ll a)
{
	if(a==1) return false;
	for(int i=2;i*i<=a;i++)
	{
		if(a%i==0)
		return false;
	}
	return true;
}
ll ans(ll b)
{
	ll div=1;
	div+=b;
	for(;!prime(div);div++);
	ll diiv=div;
	diiv+=b;
	for(;!prime(diiv);diiv++);
	return div*diiv;
}
int a;
ll b;
int main()
{
	ios::sync_with_stdio(false);
	cin>>a;
	rep(i,a)
	{
		cin>>b;
		prt(ans(b));
	}
	return 0;
}