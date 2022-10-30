#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 105
int T, n, a, b;
char s[N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s", s+1);
		a=b=0;
		n=strlen(s+1);
		for(int i=1; i<=n; ++i) s[i]=='0'?++a:++b;
		puts((std::min(a, b)&1)?"DA":"NET");
	}
	return 0;
}