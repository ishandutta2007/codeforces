#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define ll long long
using namespace std;
inline ll read()
{
	char c=getchar();
	ll kkk=0;
	while(c<'0' || c>'9')
		c=getchar();
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk;
}
ll n;
inline int fun(ll k)
{
	int ans=0;
	while(k>0)
	{
		ans+=k%10;
		k/=10;
	}
	return ans;
}
int main()
{
	n=read();
	ll a=0;
	while(a<=n)
		a=a*10+9;
	a=a/10;
	ll b=n-a;
	cout<<fun(a)+fun(b);
	return 0;
}