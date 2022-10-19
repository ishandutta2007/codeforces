#include <bits/stdc++.h>
//#define CinCout
#define rep(i,n) for(int i=0,_##i##__end=(n);i<_##i##__end;++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,_##i##__end=(n);i<=_##i##__end;++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define repk(i,a,b) for(int i=(a),_##i##__end=(b);i<=_##i##__end;++i)
#define perk(i,a,b) for(int i=(a),_##i##__end=(b);i>=_##i##__end;++i)
#define rep0(i,a,b) for(int i=(a),_##i##__end=(b);i<_##i##__end;++i)
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
int n,k,p,x,y,cnt,c2;
vector<int> g[300005];
vector<int> to[300005];
vector<int> g2[300005];
int deg[300005];
queue<int> deg0;
int f[300005],s[300005],l[300005];
int R[300005];
void init()
{
	rep1(i,n) f[i]=l[i]=i,s[i]=1;
}
int getp(int x)
{
	return f[x]==x?x:f[x]=getp(f[x]);
}
bool sam(int x,int y)
{
	return getp(x)==getp(y);
}
void mer(int x,int y)
{
    x=getp(x),y=getp(y);
    l[y]=l[x];
    if(x==y) return ;
	if(s[x]>s[y]) swap(x,y);
	s[y]+=s[x];f[x]=y;
}
vector<int> res;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	init();
	rep1(i,n)
	{
		cin>>p;
		if(p)
		{
			g[p].pb(i);
			to[p].pb(i);++deg[i];
		}
	}
	rep1(i,k)
	{
		cin>>x>>y;
		mer(x,y);
		to[x].pb(y);++deg[y];
		R[x]=y;
	}
	rep1(i,n) if(deg[i]==0) deg0.push(i);
	while(!deg0.empty())
	{
		int v=deg0.front();deg0.pop();++cnt;
		rep(i,to[v].size())
		{
			int u=to[v][i];
			if((--deg[u])==0)
			deg0.push(u);
		}
	}
	if(cnt!=n)
	{
		cout<<0<<endl;return 0;
	}
	cnt=0;memset(deg,0,sizeof(deg));
	rep1(i,n)
	{
		if(f[i]==i) ++c2;
		rep(j,g[i].size())
		{
			if(!sam(i,g[i][j]))
			{
				g2[getp(i)].pb(getp(g[i][j]));
				++deg[getp(g[i][j])];
			}
		}
	}
	rep1(i,n) if(deg[i]==0&&f[i]==i) deg0.push(i);
	while(!deg0.empty())
	{
		int v=deg0.front();deg0.pop();++cnt;
		rep(i,g2[v].size())
		{
			int u=g2[v][i];
			if((--deg[u])==0)
			deg0.push(u);
		}
		res.pb(v);
	}
	if(cnt!=c2)
	{
		cout<<0<<endl;return 0;
	}
	rep(i,res.size())
	{
		int nw=l[res[i]];
		while(R[nw])
		{
			cout<<nw<<' ';
			nw=R[nw];
		}
		cout<<nw<<' ';
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