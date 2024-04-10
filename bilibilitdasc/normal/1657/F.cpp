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
const int N=400005;
const int V=800005;
struct two_sat{
	void init(int n2)
	{
		n=n2;
		vc=n<<1;
		rep1(i,vc)
		{
			to[i].clear();
			fr[i].clear();
		}
		cnt=cnt2=cnt3=0;
		rep1(i,vc) vis[i]=0,scc[i]=-1;
	}
	void link_if(int i,int x,int j,int y)//if i is x , then j is y.
	{
		//cout<<"if "<<i<<" choose "<<x<<" then "<<j<<" choose "<<y<<endl;
		to[i+x*n].pb(j+y*n);
		fr[j+y*n].pb(i+x*n);
		to[j+(y^1)*n].pb(i+(x^1)*n);
		fr[i+(x^1)*n].pb(j+(y^1)*n);
	}
	bool satisfiable()
	{
		before_ask();
	//	cout<<"OK"<<endl;
		rep1(i,n)
		{
			if(scc[i]==scc[i+n]) return false;
		}
		return true;
	}
	void determine(bool* fl)
	{
		rep1(i,n)
		{
		//	cout<<"#"<<i<<" orz"<<endl;
			if(scc[i]<scc[i+n]) fl[i]=1;
			else fl[i]=0;
		//	cout<<fl[i]<<' ';
		//	cout<<"#"<<i<<" sto"<<endl;
		}
		//cout<<endl;
	}
	private:
		int n,vc;
		vector<int> to[V];
		vector<int> fr[V];
		vector<int> g2[V];
		int dfn[V],cnt;
		bool vis[V];
		int deg[V];
		int scc[V],cnt2;
		queue<int> q;
		int idx[V],cnt3;
		void dfs_dfn(int v)
		{
    		vis[v]=1;
    		rep(i,to[v].size())
    		{
    			int u=to[v][i];
    			if(!vis[u]) dfs_dfn(u);
			}
			dfn[cnt++]=v;
		}
		void dfs_scc(int v,int c)
		{
			scc[v]=c;
			rep(i,fr[v].size())
    		{
    			int u=fr[v][i];
    			if(scc[u]==-1) dfs_scc(u,c);
			}
		}
		void calc_scc()
		{
			rep1(i,vc) if(!vis[i]) dfs_dfn(i);
			per(i,cnt) if(scc[dfn[i]]==-1) dfs_scc(dfn[i],++cnt2); 
		}
		void rebuild()
		{
			rep1(i,vc) rep(j,to[i].size())
			{
				int u=to[i][j];
				if(scc[i]!=scc[u])
				{
					g2[scc[i]].pb(scc[u]);
				}
			}
			rep1(i,cnt2)
			{
				deg[i]=0;
				sort(g2[i].begin(),g2[i].end());
				int v=unique(g2[i].begin(),g2[i].end())-g2[i].begin();
				g2[i].resize(v);
			}
			rep1(i,cnt2)
			{
				rep(j,g2[i].size())
				{
					++deg[g2[i][j]];
				}
			}
		}
		void topo_sort()
		{
			rep1(i,cnt2) if(deg[i]==0) q.push(i);
			while(!q.empty())
			{
				int u=q.front();
				idx[u]=cnt3++;
				q.pop();
				rep(i,g2[u].size())
				{
					int v=g2[u][i];
					if(!(--deg[v]))
					{
						q.push(v);
					}
				}
			}
		}
		void before_ask()
		{
		//	cout<<"NEVER"<<endl;
			calc_scc();
		//	cout<<"GONNA"<<endl;
			rebuild();
		//	cout<<"GIVE"<<endl;
			topo_sort();
		//	cout<<"YOU"<<endl;
			rep1(i,vc) scc[i]=idx[scc[i]];
		//	cout<<"UP"<<endl; 
		}
};
two_sat str;
int n,q,u,v;
int x[N],y[N];
string s[N];
vector<int> path[N];
string could[N];
bool vis[N];
vector<int> tr[N];
int dep[N],par[N];
stack<int> xx,yy;
vector<int> choices;
bool ans[N];
void dfs(int x,int p,int d)
{
	dep[x]=d;par[x]=p;
	rep(i,tr[x].size())
	{
		int U=tr[x][i];
		if(U==p) continue;
		dfs(U,x,d+1);
	}
}
void process(int i)
{
	cin>>x[i]>>y[i]>>s[i];
	int dx=dep[x[i]],dy=dep[y[i]];
	int nw=x[i];
	int ld=((dx+dy)-(s[i].size()-1))>>1;
	while(!xx.empty()) xx.pop(); while(!yy.empty()) yy.pop();
	while(dx!=ld)
	{
		xx.push(nw);nw=par[nw];--dx;
	}
	xx.push(nw);
	nw=y[i];
	while(dy!=ld)
	{
		yy.push(nw);nw=par[nw];--dy;
	}
	while(!yy.empty())
	{
		xx.push(yy.top());yy.pop();
	}
	int c=0,ver;char c1,c2;
	while(!xx.empty())
	{
		c1=s[i][c];c2=s[i][s[i].size()-(++c)];ver=xx.top();xx.pop();path[i].pb(ver);
		if(!vis[ver])
		{
			vis[ver]=1;
			if(c1!=c2) 
			{
				could[ver]+=c1;could[ver]+=c2;
			}
			else
			{
				could[ver]+=c1;
			}
		}
		else
		{
			per(j,could[ver].size())
			if(could[ver][j]!=c1&&could[ver][j]!=c2)
			could[ver].erase(j,1);
		}
	}
}
void resolve()
{
	str.init(n);
//	rep1(i,n) cout<<could[i]<<endl;
	rep1(i,n)
	{
		if(vis[i])
		{
			if(could[i].empty())
			{
				cout<<"NO"<<endl;
				exit(0);
			}
			else if(could[i].size()==1)
			{
				if(could[i]=="a") could[i]+='b';
				else could[i]+='a';
				str.link_if(i,1,i,0);
			}
		}
	}
//	rep1(i,n) cout<<could[i]<<endl;
	rep(i,q)
	{
		choices.clear();
		rep(j,s[i].size())
		{
			if(s[i][j]!=s[i][s[i].size()-1-j])
			{
				choices.pb(j);
			}
		}
		rep(j,choices.size())
		{
			int nx=(j+1)%choices.size();
			int x=choices[j],y=choices[nx];
			int vx=path[i][x],vy=path[i][y];
			char x1=s[i][x],x2=s[i][s[i].size()-1-x],y1=s[i][y],y2=s[i][s[i].size()-1-y];
			string ch1=could[vx],ch2=could[vy];
			int idx1=min(size_t(2),ch1.find(x1)),idx2=min(size_t(2),ch1.find(x2)),idy1=min(size_t(2),ch2.find(y1)),idy2=min(size_t(2),ch2.find(y2));
			if(idx1!=2)
			{
				if(idy1==2)
				{
					str.link_if(vx,idx1,vx,!idx1);
				}
				else
				{
					str.link_if(vx,idx1,vy,idy1);
				}
			}
			if(idx2!=2)
			{
				if(idy2==2)
				{
					str.link_if(vx,idx2,vx,!idx2);
				}
				else
				{
					str.link_if(vx,idx2,vy,idy2);
				}
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>q;
	rep(i,n-1)
	{
		cin>>u>>v;
		tr[u].pb(v);
		tr[v].pb(u);
	}
	dfs(1,-1,0);
	//cout<<"/yiw"<<endl;
	rep(i,q)
	{
		process(i);
	}
//	cout<<"/youl"<<endl;
	resolve();
//	cout<<"/bx"<<endl;
	if(!str.satisfiable()) 
	{
		cout<<"NO"<<endl;
	}
	else
	{
		cout<<"YES"<<endl;
		str.determine(ans);
		rep1(i,n) 
		{
			if(vis[i]) cout<<could[i][ans[i]]; else cout<<'a'; 
		}
		cout<<endl;
	}
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