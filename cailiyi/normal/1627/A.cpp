#include<bits/stdc++.h>
#define N 50
using namespace std;
int T,n,m,r,c;
char a[N+5][N+5];
inline bool all_white()
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(a[i][j]=='B') return 0;
	return 1;
}
inline bool has_black()
{
	for(int i=1;i<=n;++i)
		if(a[i][c]=='B') return 1;
	for(int i=1;i<=m;++i)
		if(a[r][i]=='B') return 1;
	return 0;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d %d",&n,&m,&r,&c);
		for(int i=1;i<=n;++i) scanf("%s",a[i]+1);
		if(all_white()) puts("-1");
		else if(a[r][c]=='B') puts("0");
		else if(has_black()) puts("1");
		else puts("2");
	}
	return 0;
}