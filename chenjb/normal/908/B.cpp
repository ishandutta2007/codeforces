#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
bool distinct(int a,int b,int c,int d)
{
	int tmp[6];
	tmp[1]=a; tmp[2]=b; tmp[3]=c; tmp[4]=d;
	sort(tmp+1,tmp+4+1);
	if (tmp[1]==1 && tmp[2]==2 && tmp[3]==3 && tmp[4]==4)return 1;
	return 0;
}
int n,m;
char g[60][60];
char a[500];
int way[6];
bool check()
{
	int x,y;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if (g[i][j]=='S')x=i,y=j;
	int len=strlen(a+1);
	for(int i=1;i<=len;i++)
	{
		if (way[a[i]-'0'+1]==1)x++;
		if (way[a[i]-'0'+1]==2)y++;
		if (way[a[i]-'0'+1]==3)x--;
		if (way[a[i]-'0'+1]==4)y--;
		if (x<1 || x>n || y<1 || y>m)return 0;
		if (g[x][y]=='#')return 0;
		if (g[x][y]=='E')return 1;
	}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",g[i]+1);
	scanf("%s",a+1);
	int ans=0;
	for(way[1]=1;way[1]<=4;way[1]++)
		for(way[2]=1;way[2]<=4;way[2]++)
			for(way[3]=1;way[3]<=4;way[3]++)
				for(way[4]=1;way[4]<=4;way[4]++)
					if (distinct(way[1],way[2],way[3],way[4]))
					{
						if (check())ans++;
					}
	cout<<ans<<endl;
}