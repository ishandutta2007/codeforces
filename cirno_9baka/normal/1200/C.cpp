#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=2520;
int q;
ll n,m,sx,sy,ex,ey,g;
ll gcd(ll a,ll b)
{
	if(!b)
		return a;
	return gcd(b,a%b);
}
int main()
{
	scanf("%lld %lld %d",&n,&m,&q);
	g=gcd(n,m);
	while(q--)
	{
		scanf("%lld %lld %lld %lld",&sx,&ex,&sy,&ey);
		if(sx==1)
			ex=(ex-1)/(n/g);
		else
			ex=(ex-1)/(m/g);
		if(sy==1)
			ey=(ey-1)/(n/g);
		else
			ey=(ey-1)/(m/g);
		if(ex==ey)
			printf("YES\n");
		else
			printf("NO\n");
	}
}