// Problem: E. Roma and Poker
// Contest: Codeforces - Educational Codeforces Round 20
// URL: https://codeforces.com/contest/803/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// zhoukangyang 
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
char s[1000003];
bool f[1003][3003];
#define dxno {puts("NO");return 0;}
void dfs(int n,int k)
{
	//printf("%d %d\n",n,k);
	if(n<1) return ;
		if(s[n]=='L') dfs(n-1,k+1),printf("L");
		if(s[n]=='W') dfs(n-1,k-1),printf("W");
		if(s[n]=='D') dfs(n-1,k),printf("D");
		if(s[n]=='?')
		if(f[n-1][k-1]) dfs(n-1,k-1),printf("W");
		else if(f[n-1][k+1]) dfs(n-1,k+1),printf("L");
		else dfs(n-1,k),printf("D");
}
signed main()
{
	int n=read(),k=read();
	scanf("%s",s+1);
	f[0][1100]=1;
	for(int i=1; i<=n;i++) 
	{
		if(s[i]=='L')
		for(int j=1100-k+1; j<1100+k; ++j)
		if(f[i-1][j+1]) f[i][j]=1;
		if(s[i]=='D')
		for(int j=1100-k+1; j<1100+k; ++j)
		if(f[i-1][j]) f[i][j]=1;
		if(s[i]=='W')
		for(int j=1100-k+1; j<1100+k; ++j)
		if(f[i-1][j-1]) f[i][j]=1;
		if(s[i]=='?')
		for(int j=1100-k+1; j<1100+k; ++j)
		if(f[i-1][j-1]||f[i-1][j]||f[i-1][j+1]) f[i][j]=1;
	}
	int K=1100+k;
		if(s[n]=='L')
		if(!f[n-1][1100-k+1]) dxno
		else K=1100-k;
		if(s[n]=='W')
		if(!f[n-1][1100+k-1]) dxno
		if(s[n]=='D') dxno
		if(s[n]=='?')
		if(!f[n-1][1100-k+1]&&!f[n-1][1100+k-1]) dxno
		else if(f[n-1][1100-k+1]) K=1100-k;
		dfs(n,K);
		puts("");
    return 0;
}