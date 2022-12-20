#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i, x, y) for(ll i = (x); i <= (y); ++i)
#define FOr(i, x, y) for(ll i = (x); i >= (y); --i)

const ll N = 305;
char s[N],t[N];
ll num[N];
char news[N];
int main()
{
	ll n;
	scanf("%lld",&n);
	For(kase, 1, n)
	{
		scanf("%s%s",s,t);
		ll len = strlen(t);
		For(i, 0, len-1) num[t[i]-65]++;
		len = strlen(s);
		ll now = 0;
		FOr(i, len-1, 0)
		{
			if (num[s[i]-65]) 
			num[s[i]-65]--, news[now++] = s[i];
		}
		if (now!=strlen(t)) puts("No");
		else
		{
			bool ok = 1;
			For(i, 0, now-1)
			{
				ok &= t[i] == news[now-1-i];
			}
			puts(ok?"Yes":"No");
		}
		memset(num, 0, sizeof(num));
		memset(news, 0,sizeof(news));
	}
}