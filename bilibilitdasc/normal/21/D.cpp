#include <bits/stdc++.h>
//#define CinCout
#define rep(i,n) for(int i=0,_##i##__end=(n);i<_##i##__end;++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,_##i##__end=(n);i<=_##i##__end;++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define pb push_back
#define mp make_pair
#define debugv(x) cout<<#x<<'='<<x<<",line "<<__LINE__-1<<endl
#define debug cout<<"at line "<<__LINE__-1<<" in function "<<__FUNCTION__<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
#ifdef CinCout
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#else
#define Yes puts("Yes")
#define No puts("No")
#define YES puts("YES")
#define NO puts("NO")
#endif
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int n,m,x,y,w;
int tot;
int st;
int dis[33333];
int d1[16][16];
bool vis[16];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	memset(d1,0x3f,sizeof(d1));
	rep1(i,n)
	{
		d1[i][i]=0;
	}
	rep(i,m)
	{
		cin>>x>>y>>w;
		st^=1<<(x-1);
		st^=1<<(y-1);
		tot+=w;
		d1[x][y]=min(d1[x][y],w);
		d1[y][x]=d1[x][y];
		vis[x]=vis[y]=1;
	}
	rep1(k,n) rep1(i,n) rep1(j,n)
	d1[i][j]=min(d1[i][j],d1[i][k]+d1[k][j]);
	rep1(i,n) rep1(j,n)
	{
		if((vis[i]||i==1)&&vis[j]&&d1[i][j]==0x3f3f3f3f)
		{
			cout<<-1<<endl;return 0;
		}
	}
	memset(dis,0x3f,sizeof(dis));
	dis[0]=tot;
	rep(i,1<<n)
	{
		rep(j,n)
		{
			if((i>>j)&1)
			{
				rep(k,n)
				{
					if(k!=j&&((i>>k)&1))
					{
						dis[i]=min(dis[i],dis[i^(1<<k)^(1<<j)]+d1[j+1][k+1]);
					}
				}
			}
		}
	}
	if(dis[st]==0x3f3f3f3f) dis[st]=-1;
	cout<<dis[st]<<endl;
	return 0;
}
/* things to check
1.  submit on luogu
*/

/* something to think about
1. greedy? dp? searching? dp with matrix/ segment tree? binary search?
2. If contains "not", why not  or few affect?
*/