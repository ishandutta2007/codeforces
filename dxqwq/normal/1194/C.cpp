// Problem: C. From S To T
// Contest: Codeforces - Educational Codeforces Round 68 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1194/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// zhoukangyang 
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
char s[1000003],t[1000003],p[1000003];
int C[1003],D[1003];
int ans[103][103];
signed main()
{
	for(int T=read();T--;)
	{
		for(int i=1; i<=1000; ++i) C[i]=D[i]=0;
		scanf("%s",s+1);
		scanf("%s",t+1);
		int n=strlen(s+1),m=strlen(t+1);
		scanf("%s",p+1);
		int L=strlen(p+1);
		for(int i=1; i<=L; ++i) ++C[(int)p[i]];
		if(n>m)
		{
			puts("NO");
			continue;
		}
		memset(ans,0,sizeof(ans));
		ans[0][0]=0;
		for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j) if(i+j>0)
		if(s[i]==t[j]) ans[i][j]=ans[i-1][j-1]+1;
		else ans[i][j]=max(ans[i][j-1],ans[i-1][j]);
		if(ans[n][m]==n)
		{
			for(int i=1; i<=n; ++i) --D[(int)s[i]];
			for(int i=1; i<=m; ++i) ++D[(int)t[i]];
			bool f=1;
			for(int i=1; i<=1000; ++i) 
			{
				if(C[i]<D[i]) f=0;
			}
			if(f) puts("YES");
			else puts("NO");
		}
		else
		{
			puts("NO");	
		}
	}
    return 0;
}