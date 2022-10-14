// Problem: One-Four Overload
// Contest: Codeforces
// URL: https://m2.codeforces.com/contest/1567/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
char s[503][503];
int ans[503][503];
int cnt=0;
int id[503][503];
void dfs(int x,int y,int t)
{
	id[x][y]=t;
	if(s[x-1][y]=='.'&&!id[x-1][y]) dfs(x-1,y,t);
	if(s[x+1][y]=='.'&&!id[x+1][y]) dfs(x+1,y,t);
	if(s[x][y-1]=='.'&&!id[x][y-1]) dfs(x,y-1,t);
	if(s[x][y+1]=='.'&&!id[x][y+1]) dfs(x,y+1,t);
	return ;
}
vector<int> e[300003],ee[300003];
int col[300003];
void dfs2(int x,int y)
{
	if(col[id[x][y]]==1) if(x&1) ans[x][y]=1;
	else ans[x][y]=4;
	else if(x&1) ans[x][y]=4;
	else ans[x][y]=1;
	if(s[x-1][y]=='.'&&!ans[x-1][y]) dfs2(x-1,y);
	if(s[x+1][y]=='.'&&!ans[x+1][y]) dfs2(x+1,y);
	if(s[x][y-1]=='.'&&!ans[x][y-1]) dfs2(x,y-1);
	if(s[x][y+1]=='.'&&!ans[x][y+1]) dfs2(x,y+1);
	return ;
}
void dfs1(int x)
{
	for(int y:e[x]) if(!col[y]) col[y]=col[x]^2,dfs1(y);
	else if((col[x]^2)!=col[y]) puts("NO"),exit(0);
	for(int y:ee[x]) if(!col[y]) col[y]=col[x],dfs1(y);
	else if(col[x]!=col[y]) puts("NO"),exit(0);
	return ;
}
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; ++i) scanf("%s",s[i]+1),reverse(s[i]+1,s[i]+m+1);
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) if(s[i][j]=='X')
	{
		int c=0;
		c+=s[i][j-1]=='.';
		c+=s[i][j+1]=='.';
		c+=s[i-1][j]=='.';
		c+=s[i+1][j]=='.';
		if(c&1) puts("NO"),exit(0);
	}
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) 
	if(s[i][j]=='.'&&!id[i][j]) dfs(i,j,++cnt);
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) if(s[i][j]=='X')
	{
		int c=0,cc=0;
		vector<int> v;
		if(s[i][j-1]=='.') ++c,v.push_back(id[i][j-1]);
		if(s[i][j+1]=='.') ++c,v.push_back(id[i][j+1]);
		if(s[i-1][j]=='.') ++c,++cc,v.push_back(id[i-1][j]);
		if(s[i+1][j]=='.') ++c,++cc,v.push_back(id[i+1][j]);
		if(c==4)
		{
			sort(v.begin(),v.end());
			if(v[0]==v[1]&&v[2]==v[3]) continue;
			if(v[0]==v[1]) ee[v[2]].push_back(v[3]),ee[v[3]].push_back(v[2]);
			else if(v[2]==v[3]) ee[v[0]].push_back(v[1]),ee[v[1]].push_back(v[0]);
		}
		if(c==2&&v[0]!=v[1]) if(cc==2||cc==0)
		e[v[0]].push_back(v[1]),e[v[1]].push_back(v[0]);
		else ee[v[0]].push_back(v[1]),ee[v[1]].push_back(v[0]);
	}
	for(int i=1; i<=cnt; ++i) if(!col[i]) col[i]=1,dfs1(i);
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) 
	if(s[i][j]=='.'&&!ans[i][j]) dfs2(i,j);
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) if(s[i][j]=='X')
	{
		int c=0;
		if(s[i][j-1]=='.') c+=ans[i][j-1];
		if(s[i][j+1]=='.') c+=ans[i][j+1];
		if(s[i-1][j]=='.') c+=ans[i-1][j];
		if(s[i+1][j]=='.') c+=ans[i+1][j];
		if(c%5) puts("NO?"),exit(0);
		ans[i][j]=c;
	}
	puts("YES");
	for(int i=1; i<=n; ++i,puts("")) for(int j=m; j>=1; --j) 
	printf("%d ",ans[i][j]); 
	return 0;
}