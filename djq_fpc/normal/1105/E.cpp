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
#include<bitset>
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
map<string,int> mp;
string st;
int n,m,i,j,x,y,op,tt,s=0,t=100150,ttt,g[45][45],ans,seq[45],cnt[45];
bitset<1000005> f[45];
bool dfs(int x,int d)
{
	int i,j;
	fz(i,x+1,m)
	{
		if (cnt[i]+d<=ans) return 0;
		if (!g[x][i])
		{
			fz1(j,d-1) if (g[seq[j]][i]) break;
			if (j<d) continue;
			seq[d+1]=i;
			if (dfs(i,d+1)) return 1;
		}
	}
	if (d>ans)
	{
		ans=d;
		return 1;
	}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	fz1(i,n)
	{
		scanf("%d",&op);
		if (op==1)
		{
			tt++;
		}
		else
		{
			rdst(st,45);
			if (mp.count(st)) x=mp[st];
			else
			{
				x=++ttt;
				mp[st]=x;
			}
			f[x][tt]=1;
		}
	}
	fz1(i,m)
	{
		fz1(j,m)
		{
			if ((f[i]&f[j]).count())
			{
				g[i][j]=1;
			}
		}
	}
	fd1(i,m)
	{
		seq[1]=i;
		dfs(i,1);
		cnt[i]=ans;
	}
	cout<<ans<<endl;
	return 0;
}