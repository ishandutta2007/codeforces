#include<cstdio>
#include<cstring>
#include<algorithm>
#define MaxN 1123
using std::max;
char s[MaxN];
int n,T;
inline void Solve()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int res=0,bg;
	for(bg=1;s[bg]=='P';++bg);
	for(int i=bg+1,cnt=0;i<=n;++i)
	if(s[i]=='P')res=max(res,++cnt);
	else cnt=0;
	printf("%d\n",res);
}
int main()
{
	scanf("%d",&T);
	while(T--)Solve();
	return 0;
}