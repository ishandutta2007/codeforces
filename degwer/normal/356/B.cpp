#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
	for(;;)
	{
		if(a<b)
		{
			swap(a,b);
		}
		a%=b;
		if(a==0)
		{
			return b;
		}
	}
}
char sa[1000001],sb[1000001];
int main()
{
	ll a,b;
	scanf("%I64d%I64d",&a,&b);
	scanf("%s%s",sa,sb);
	ll la=strlen(sa),lb=strlen(sb);
	ll tim=gcd(a,b);
	a/=tim;
	b/=tim;
	ll g=gcd(la,lb);
	ll ans=0;
	for(int i=0;i<g;i++)
	{
		int dat[26];
		fill(dat,dat+26,0);
		for(ll j=i;j<lb;j+=g)
		{
			dat[sb[j]-'a']++;
		}
		for(ll j=i;j<la;j+=g)
		{
			ans+=lb/g-dat[sa[j]-'a'];
		}
	}
	printf("%I64d\n",ans*tim);
}