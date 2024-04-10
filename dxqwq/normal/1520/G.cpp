// Problem: G. To Go Or Not To Go?
// Contest: Codeforces - Codeforces Round #719 (Div. 3)
// URL: https://codeforces.com/contest/1520/problem/G
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
int A[2003][2003];
int MN;
bool f[2003][2003];
int n,m,w;
int c[2003][2003];
queue<pair<int,int> > q;
#define mp make_pair
bool check(int x,int y)
{
	if(x<1||x>n||y<1||y>m||A[x][y]==-1||f[x][y]) return 0;
	return 1;
}
void qwq(int x,int y)
{
	if(A[x][y]>0) MN=min(MN,A[x][y]+c[x][y]);
	if(check(x-1,y))q.push(mp(x-1,y)),f[x-1][y]=1,c[x-1][y]=c[x][y]+w;
	if(check(x+1,y))q.push(mp(x+1,y)),f[x+1][y]=1,c[x+1][y]=c[x][y]+w;
	if(check(x,y-1))q.push(mp(x,y-1)),f[x][y-1]=1,c[x][y-1]=c[x][y]+w;
	if(check(x,y+1))q.push(mp(x,y+1)),f[x][y+1]=1,c[x][y+1]=c[x][y]+w;
	return;
}
void Bfs(int x,int y)
{
	f[x][y]=1;
	q.push(mp(x,y));
	while(!q.empty())
	{
		int A=q.front().first,B=q.front().second;
		qwq(A,B);
		q.pop();
	}
	return ;
}
signed main()
{
    n=read(),m=read(),w=read();
    for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j) A[i][j]=read();
    MN=1e18;
    Bfs(1,1);
    int ANS=1e18;
    if(f[n][m])
    {
    	ANS=c[n][m];
    }
    if(MN>1e17&&!f[n][m])
    {
    	puts("-1");
    	return 0;
    }
    memset(f,0,sizeof(f));
    memset(c,0,sizeof(c));
    int ans=MN;
    MN=1e18;
    Bfs(n,m);
    ANS=min(ANS,ans+MN);
    if(ANS<=1e17) printf("%lld\n",ANS);
    else puts("-1");
	return 0;
}