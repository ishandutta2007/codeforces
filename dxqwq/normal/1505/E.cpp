// Problem: E. Cakewalk
// Contest: Codeforces - April Fools Day Contest 2021
// URL: https://codeforces.com/contest/1505/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int n=read(),m=read();
char s[13][13];
signed main()
{
	for(int i=1; i<=n; i++) scanf("%s",s[i]+1);
	int x=1,y=1,ans=0;
	while(x<n||y<m)
	{
		ans+=(s[x][y]=='*');
		if(x==n) ++y;
		else if(y==m) ++x;
		else
		{
			int X=999,Y=999;
			for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) 
			{
				if(i>=x&&j>y&&s[i][j]=='*') Y=min(Y,i+j-x-y);
				if(i>x&&j>=y&&s[i][j]=='*') X=min(X,i+j-x-y);
			}
			if(X<Y) ++x;
			else ++y;
		}
	}
	if(s[n][m]=='*') ++ans;
	printf("%d\n",ans);
	return 0;
}