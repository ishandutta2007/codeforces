// Problem: B. Blocks
// Contest: Codeforces - Codeforces Round #608 (Div. 2)
// URL: https://codeforces.com/contest/1271/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
char s[1000003];
int a[1000003];
int ans[1000003],cnt=0;
signed main()
{
	int n=read();
	scanf("%s",s+1);
	int A=0,B=0;
	for(int i=1; i<=n; i++) if(s[i]=='B') ++A;
	else ++B,a[i]=1;
	if(B%2==0)//all 0
	{
		for(int i=1; i<n; i++) if(a[i]==1) a[i]^=1,a[i+1]^=1,ans[++cnt]=i;
		printf("%lld\n",cnt);
		for(int i=1; i<=cnt; i++) printf("%lld ",ans[i]);
		return 0;
	}
	else if(A%2==0)//all 1
	{
		for(int i=1; i<n; i++) if(a[i]==0) a[i]^=1,a[i+1]^=1,ans[++cnt]=i;
		printf("%lld\n",cnt);
		for(int i=1; i<=cnt; i++) printf("%lld ",ans[i]);
		return 0;
	}
	else
	{
		puts("-1");
	}
    return 0;
}