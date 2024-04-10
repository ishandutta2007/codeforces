#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define per1(i,n) for(int i=(n);i>=1;i--)
#define repk(i,a,b) for(int i=(a);i<=(b);i++)
#define perk(i,a,b) for(int i=(a);i>=(b);i--)
#define rep0(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define g(x) cout<<#x<<'='<<x<<endl
#define nextp next_permutation
#define pq priority_queue
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
struct edge{
	int c;
	ll d;
	edge(int a=0,ll b=0)
	{
		c=a;d=b;
	}
};
pq<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
int n,m,x,y,v1,v2,w;
ll t[1005],c[1005];
ll dist[1005][1005];
vector<edge> v[1005];
void dijkstra(int sp)
{
	rep1(i,n) dist[sp][i]=0x3f3f3f3f3f3f3f3fll;
	//cout<<"During dijkstra"<<endl;
	//printf("-----------------------\n");
	dist[sp][sp]=0;
	q.push(mp(0ll,sp));
	while(!q.empty())
	{
		ll di=q.top().first;
		int vt=q.top().second;q.pop();
		//printf("dist:%d vertex:%d\n",di,vt);
		rep(i,v[vt].size())
		{
			int vv=v[vt][i].c;
			if(dist[sp][vv]>dist[sp][vt]+v[vt][i].d)
			{
				//printf("another:%d\n",vv);
				dist[sp][vv]=dist[sp][vt]+v[vt][i].d;
				q.push(mp(dist[sp][vv],vv));
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>x>>y;
	rep(i,m)
	{
		cin>>v1>>v2>>w;
		v[v1].pb(edge(v2,w));
		v[v2].pb(edge(v1,w));
	}
	//rep1(i,n)
	//{
	//	printf("vertex:%d\n",i);
	//	rep(j,v[i].size())
	//	{
	//		printf("connect with %d by a road with length %d\n",v[i][j].c,v[i][j].d);
	//	}
	//}
	rep1(i,n)
	{
		cin>>t[i]>>c[i];
	}
	rep1(i,n)
	{
		dijkstra(i);
	}
	rep1(i,n)
	{
		v[i].clear();
	}
	while(!q.empty()) q.pop();
	//rep1(i,n) rep1(j,n)
	//{
	//	printf("dist[%d][%d]=%d\n",i,j,dist[i][j]);
	//}
	rep1(i,n) rep1(j,n)
	{
		if(i!=j&&dist[i][j]<=t[i])
		{
			v[i].pb(edge(j,c[i]));
		}
	}
	dijkstra(x);
	if(dist[x][y]!=0x3f3f3f3f3f3f3f3fll)
	cout<<dist[x][y]<<endl;
	else
	cout<<-1<<endl;
	return 0;
}