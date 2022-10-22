#include<cstdio>
#include<cstring>
#define N 2000010
#define ll long long
using namespace std;
char a[N],b[N];
ll _a,_b,_c,c;
int len;
ll GetPhi(ll x)
{
	ll X=x;
	for(ll i=2;i*i<=x;++i) 
		if(!(x%i))
		{
		    X=X*(i-1)/i;
			while(!(x%i)) x/=i;
		}
    if(x!=1) X=X*(x-1)/x;
    return X;
}
ll fastpow(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%c;
		a=a*a%c;
		b=b/2;
	}
	return ans;
}
int main()
{
	scanf("%s%s%lld",a,b,&c);
	_c=GetPhi(c),len=strlen(a);
	for(int i=0;i<len;i++)
	{
		_a=_a*10+a[i]-'0';
		_a=_a%c;
	}
	len=strlen(b);
	bool pd=0;
	for(int i=0;i<len;i++)
	{
		_b=_b*10+b[i]-'0';
		if(_b>=_c) pd=1;
		_b=_b%_c;
	}
	_b=(_b-1+_c)%_c;
	if(pd) _b+=_c;
	ll ans=((_a-1)*fastpow(_a,_b)%c+c)%c;
	if(ans) printf("%lld",ans);
	else printf("%lld",c);
	return 0; 
}