#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
int v[1010][1010];
int ax,ay,bx,by,cx,cy,tx,ty;
int n;
using namespace std;
void dfs(int x,int y)
{
	if (x==0 || y==0 || x>n || y>n)return;
	if (v[x][y]!=0)return;
	v[x][y]=2;
	dfs(x+1,y);
	dfs(x,y+1);
	dfs(x-1,y);
	dfs(x,y-1);
	dfs(x+1,y+1);
	dfs(x-1,y-1);
	dfs(x+1,y-1);
	dfs(x-1,y+1);

}
int main()
{
	cin>>n;
	cin>>ax>>ay;
	cin>>bx>>by;
	cin>>cx>>cy;
	rep(i,n)v[ax][i]=v[i][ay]=1;
	tx=ax,ty=ay; while (tx && ty){ v[tx][ty]=1; tx--; ty--; }
	tx=ax,ty=ay; while (tx<=n && ty<=n){ v[tx][ty]=1; tx++; ty++; }
	dfs(bx,by);
	//rep(i,n)rep(j,n)printf("%d%c",v[i][j],j==n?'\n':'\0');
	if (v[cx][cy]==2)puts("YES"); else puts("NO");
	return 0;
}