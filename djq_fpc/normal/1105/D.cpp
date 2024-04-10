#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
#include<set>
#include<map>
#define sqr(x) (x)*(x)
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
//#define T_ int
using namespace std;
int n,m,i,j,k,vis[1005][1005],dis[1005][1005],ans[15],s[15];
vector<pair<int,int> > cur[15],nxt[15];
char mp[1005][1005];
queue<int> qx,qy;
void upd(int x,int y,int d,int fr)
{
	if (x<1||x>n||y<1||y>m) return;
	if (mp[x][y]=='#') return;
	if (vis[x][y]||dis[x][y]<=d) return;
	dis[x][y]=d;
	vis[x][y]=1;
	ans[fr]++;
	//cerr<<fr<<' '<<x<<' '<<y<<endl;
	nxt[fr].push_back(make_pair(x,y));
	qx.push(x);qy.push(y);
}
int main()
{
	memset(dis,15,sizeof(dis));
	scanf("%d%d%d",&n,&m,&k);
	fz1(i,k) scanf("%d",&s[i]);
	fz1(i,n)
	{
		scanf(" ");
		fz1(j,m)
		{
			scanf("%c",&mp[i][j]);
			if (isdigit(mp[i][j]))
			{
				ans[mp[i][j]-'0']++;
				cur[mp[i][j]-'0'].push_back(make_pair(i,j));
				vis[i][j]=1;
			}
		}
	}
	for (;;)
	{
		fz1(i,k) nxt[i].clear();
		bool f=0;
		fz1(i,k)
		{
			ff(cur[i],it)
			{
				dis[it->first][it->second]=0;
				f=1;
				qx.push(it->first);
				qy.push(it->second);
			}
			while (!qx.empty())
			{
				int x=qx.front(),y=qy.front();
				qx.pop();qy.pop();
				if (dis[x][y]<s[i])
				{
					upd(x-1,y,dis[x][y]+1,i);
					upd(x+1,y,dis[x][y]+1,i);
					upd(x,y-1,dis[x][y]+1,i);
					upd(x,y+1,dis[x][y]+1,i);
				}
			}
		}
		if (!f) break;
		fz1(i,k) cur[i]=nxt[i];
	}
	fz1(i,k)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}