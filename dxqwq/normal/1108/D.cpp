// Problem: D. Diverse Garland
// Contest: Codeforces - Codeforces Round #535 (Div. 3)
// URL: https://codeforces.com/contest/1108/problem/D
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
}//eternal_loveti
char s[1000003];
int a[1000003];
int f[1000003][4];
stack<int> q;
void dfs(int x,int t)
{
	q.push(t);
	if(x==1) return ;
	if(t==0) if(f[x-1][1]+(a[x]!=0)==f[x][0]) dfs(x-1,1);
	else dfs(x-1,2);
	if(t==1) if(f[x-1][0]+(a[x]!=1)==f[x][1]) dfs(x-1,0);
	else dfs(x-1,2);
	if(t==2) if(f[x-1][0]+(a[x]!=2)==f[x][2]) dfs(x-1,0);
	else dfs(x-1,1);
	return ;
}
signed main()
{
	int n=read();
	scanf("%s",s+1);
	for(int i=1; i<=n; i++) if(s[i]=='R') a[i]=0;
	else if(s[i]=='B') a[i]=1;
	else a[i]=2;
	for(int i=1; i<=n; i++) 
	{
		f[i][0]=min(f[i-1][1],f[i-1][2])+(a[i]!=0);
		f[i][1]=min(f[i-1][0],f[i-1][2])+(a[i]!=1);
		f[i][2]=min(f[i-1][1],f[i-1][0])+(a[i]!=2);
	}
	int S=min(f[n][1],f[n][2]);
	S=min(f[n][0],S);
	printf("%lld\n",S);
	if(f[n][0]==S) dfs(n,0);
	else if(f[n][1]==S) dfs(n,1);
	else dfs(n,2);
	while(!q.empty()){
	if(q.top()==0) printf("R");
	else if(q.top()==1) printf("B");
	else printf("G"); q.pop();}
    return 0;
}