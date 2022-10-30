#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define N 1000005
int T, n, cur;
ll res;
char s[N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s", s+1);
		res=0, cur=0;
		n=strlen(s+1);
		for(int i=1; i<=n; ++i)
		{
			cur+=s[i]=='+'?1:-1;
			cur<0?res+=i, cur=0:0;
		}
		res+=n;
		printf("%lld\n", res);
	}
	return 0;
}