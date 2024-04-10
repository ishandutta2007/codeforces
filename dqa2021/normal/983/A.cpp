#include<cstdio>
typedef long long ll;
int n;
ll p,q,b;
ll gcd(ll x,ll y)
{return y?gcd(y,x%y):x;}
int main()
{
	scanf("%d",&n);
	while (n--)
	{
		scanf("%I64d%I64d%I64d",&p,&q,&b);
		q/=gcd(p,q);
		for (b=gcd(b,q);b!=1;b=gcd(b,q)) while (q%b==0) q/=b;
		puts(q==1?"Finite":"Infinite");
	}
	return 0;
}