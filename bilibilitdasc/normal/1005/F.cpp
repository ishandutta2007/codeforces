#include <bits/stdc++.h>
#define rep(i,n) for(int i=0,_##i##__end=(n);i<_##i##__end;++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,_##i##__end=(n);i<=_##i##__end;++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define repk(i,a,b) for(int i=(a),_##i##__end=(b);i<=_##i##__end;++i)
#define perk(i,a,b) for(int i=(a),_##i##__end=(b);i>=_##i##__end;++i)
#define rep0(i,a,b) for(int i=(a),_##i##__end=(b);i<_##i##__end;++i)
#define pb push_back
#define mp make_pair
#define debug(x) cout<<#x<<'='<<x<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int n,m,k,u,v;
int read()
{
	int res=0;char c=getchar();
	while(c<48||c>57) c=getchar();
	while(48<=c&&c<=57)
	{
		res=res*10+(c^48);
		c=getchar();
	}
	return res;
}
struct edge{
	int id;
	int to;
	edge(int x=0,int y=0)
	{
		id=x,to=y;
	}
};
vector<edge> con[200005];
vector<vector<int> > decide;
vector<int> Decide;
int dist[200005];
int p[200005];
queue<int> q;
void bfs()
{
	memset(dist,0x3f,sizeof(dist));
	dist[1]=0;
	q.push(1);
	while(!q.empty())
	{
		v=q.front();q.pop();
		for(int i=0,siz=con[v].size();i<siz;++i)
		{
			u=con[v][i].to;
			if(dist[u]>dist[v]+1)
			{
				dist[u]=dist[v]+1;
				q.push(u);
			}
		}
	}
}
bool cmp(const int&x,const int&y)
{
	return dist[x]<dist[y];
}
void pp()//PrePare
{
	n=read();m=read();k=read();
	rep(i,m)
	{
		u=read();v=read();
		con[u].pb(edge(i,v));
		con[v].pb(edge(i,u));
	}
	bfs();
	rep1(i,n) p[i]=i;
	sort(p+1,p+1+n,cmp);
}
bool Choose[200005];
int cnt,SIZ;
void calc()
{
	for(int i=2;i<=n;++i)
	{
		v=p[i];
		Decide.clear();
		for(int j=0,siz=con[v].size();j<siz;++j)
		{
			u=con[v][j].to;
			if(dist[u]==dist[v]-1)
			{
				Decide.pb(con[v][j].id);
			}
		}
		decide.pb(Decide);
	}
	SIZ=decide.size();
}
void check()
{
	long long res=1;
	for(int i=0;i<SIZ;++i)
	{
		if(res*(ll(decide[i].size()))<=k)
		res*=ll(decide[i].size());
		else
		{
			printf("%d\n",k);
			return;
		}
	}
	printf("%d\n",int(res));
}
void dfs(int i)
{
	if(i==SIZ)
	{
		if(cnt==k) exit(0);
		++cnt;
		for(int i=0;i<m;++i)
		putchar(Choose[i]^48);
		putchar(10); 
	}
	else
	{
		for(int j=0,siz=decide[i].size();j<siz;++j)
		{
			Choose[decide[i][j]]=1;
			dfs(i+1);
			Choose[decide[i][j]]=0;
		}
	}
}
int main()
{
	pp();calc();check();dfs(0);return 0;
}
/* things to check
1.  int overflow or long long memory need
2.  recursion/array/binary search/dp/loop bounds
3.  precision
4.  special cases(n=1,bounds)
5.  delete debug statements
6.  initialize(especially multi-tests)
7.  = or == , n or m ,++ or -- , i or j , > or >= , < or <=
8.  keep it simple and stupid
9.  do not delete, use // instead
10. operator priority
11. is there anything extra to output?
12. ...
*/

/* something to think about
1. greedy? dp? searching? dp with matrix/ segment tree/ binary indexed tree? binary search?
2. If contains "not", why not  or few affect?
*/