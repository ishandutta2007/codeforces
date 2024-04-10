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
vector<int> g[100005];//Graph
vector<int> b[100005];//Back
vector<int> s1[100005];//scc inside g
vector<int> t2[100005];//transition b
vector<int> ver[100005];
vector<int> dfn;
int n,m,d,u,v;
int cnt;
bool vis[100005];
int scc[100005];
int maj[100005];
unsigned long long c[100005];
int dp[100005][55];
bool reachable[100005][55];
int tot[100005][55];
unsigned long long Reach[100005];
vector<pair<int,int> > func[100005];
queue<pair<int,int> > q;
void dfs1(int v)
{
	vis[v]=1;
	rep(i,g[v].size())
	{
		int u=g[v][i];
		if(!vis[u])
		dfs1(u);
	}
	dfn.pb(v);
}
void dfs2(int v,int c)
{
	scc[v]=c;
	rep(i,b[v].size())
	{
		int u=b[v][i];
		if(scc[u]==-1)
		dfs2(u,c);
	}
}
unsigned long long read()
{
	unsigned long long ret=0;char c;
	rep(i,d)
	{
		c=getchar();
		while((c>>1)!=24) c=getchar();
		if(c&1) ret|=1ull<<i;
	}
	return ret;
}
int EndWith(int Scc,int MajorModulo)
{
	if(dp[Scc][MajorModulo]!=-1) return dp[Scc][MajorModulo];
	int&x=dp[Scc][MajorModulo];
	x=-1145141919;
	if(Scc==scc[1]) return reachable[1][MajorModulo]?(x=tot[Scc][MajorModulo]):x; 
	rep(i,func[Scc].size())
	{
		x=max(x,EndWith(func[Scc][i].fi,(func[Scc][i].se+MajorModulo)%d)+tot[Scc][MajorModulo]);
	}
	return x;
}
int perfect;
int main()
{
	scanf("%d%d%d",&n,&m,&d);
	rep(i,m)
	{
		scanf("%d%d",&u,&v);
		g[u].pb(v);b[v].pb(u);
	}
	rep1(i,n)
	{
		c[i]=read();
	}
	rep1(i,n) if(!vis[i]) dfs1(i);
	memset(scc,-1,sizeof(scc));
	per(i,n) if(scc[dfn[i]]==-1) dfs2(dfn[i],cnt++);
	per1(i,n)
	{
		rep(j,g[i].size())
		{
			v=g[i][j];
			if(scc[i]==scc[v])
			{
				s1[i].pb(v);
			}
			else
			{
			    t2[v].pb(i);
			}
			ver[scc[i]].pb(i);
		}
		maj[scc[i]]=i;
	}
	rep(i,cnt)
	{
		int v=maj[i];
		reachable[v][0]=1;
		q.push(mp(v,0));
		while(!q.empty())
		{
			int vari=q.front().fi,able=q.front().se;q.pop();
		//	cout<<vari<<','<<able<<endl;
			able=(able+1)%d;
			rep(i,s1[vari].size())
			{
				int nxt=s1[vari][i];
				if(!reachable[nxt][able])
				{
					reachable[nxt][able]=1;
					q.push(mp(nxt,able));
				}
			}
		}
	}
	rep1(i,n)
	{
	//	cout<<"SCC "<<i<<"!"<<scc[i]<<endl;
		rep(j,d)
		{
			if(reachable[i][j])
			{
				Reach[i]|=1ull<<j;
			}
		}
	//	cout<<"!"<<Reach[i]<<endl;
		rep(k,d)
		{
			if(c[i]&(Reach[i]>>k)|(c[i]>>(d-k))&Reach[i])
			{
		//		cout<<i<<'!'<<k<<endl;
				++tot[scc[i]][k];
			}
		//	cout<<"!!!"<<(c[i]&(Reach[i]>>k))<<endl;
		}
	}
	rep1(i,n)
	{
		rep(j,t2[i].size())
		{
			rep(k,d)
			{
				int v=(k+d-1)%d;
			//	cout<<"!";cout<<i<<"---"<<t2[i][j];
				if((Reach[i]>>(d-v))&Reach[t2[i][j]]|Reach[i]&(Reach[t2[i][j]]>>v))
				{
					func[scc[i]].pb(mp(scc[t2[i][j]],k));
				//	cout<<"---"<<k;
				}
			//	cout<<endl;
			//	cout<<"(Add:"<<Reach[i]<<","<<Reach[t2[i][j]]<<")"<<endl;
			}
		}
	}
//	cout<<tot[0][0]<<endl;
	memset(dp,-1,sizeof(dp));
	rep(i,cnt)
	rep(j,d)
	{
		perfect=max(perfect,EndWith(i,j));
	//	cout<<"?("<<i<<","<<j<<")"<<EndWith(i,j)<<endl;
	}
	cout<<perfect<<endl;
	return 0;
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
1. greedy? dp? searching? dp with matrix/ segment tree? binary search?
2. If contains "not", why not  or few affect?
*/