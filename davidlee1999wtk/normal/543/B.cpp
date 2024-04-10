#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 100000000
#define fi first
#define se second
#define N 3005
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int n;
int go[N][N];
int d[N][N],c[N];
bool vis[N];
void get(int *d,int s)
{
	memset(vis,0,sizeof(vis));
	queue<int> q;
	q.push(s);
	d[s]=0;
	vis[s]=1;
	int i,x,v;
	while(!q.empty())
	{
		x=q.front(),q.pop();
		for(i=1;i<=c[x];i++)
		{
			v=go[x][i];
			if(!vis[v])
			{
				vis[v]=1;
				d[v]=d[x]+1;
				q.push(v);
			}
		}
	}
}
int main()
{
	int i,m,a,b,s1,t1,l1,s2,t2,l2,ans,k1,k2,j,tm;
	cin>>n>>m;
	tm=m;
	while(m--)
	{
		scanf("%d%d",&a,&b);
		go[a][++c[a]]=b;
		go[b][++c[b]]=a;
	}
	cin>>s1>>t1>>l1>>s2>>t2>>l2;
	for(i=1;i<=n;i++)
		get(d[i],i);
	if(d[s1][t1]>l1||d[s2][t2]>l2)
	{
		printf("-1\n");
		return 0;
	}
	ans=d[s1][t1]+d[s2][t2];
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
		{
			k1=min(d[s1][i]+d[t1][j],d[s1][j]+d[t1][i])+d[i][j];
			k2=min(d[s2][i]+d[t2][j],d[s2][j]+d[t2][i])+d[i][j];
			if(k1<=l1&&k2<=l2)
				ans=min(ans,k1+k2-d[i][j]);
		}
	cout<<tm-ans<<endl;
	return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")