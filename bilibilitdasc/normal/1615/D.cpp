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
#define debugv(x) cout<<#x<<'='<<x<<",line "<<__LINE__-1<<endl
#define debug cout<<"at line "<<__LINE__-1<<" in function "<<__FUNCTION__<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int t,n,q;
int u[200005],v[200005],w[200005];
int u2,v2,w2;
int p[400005];
int siz[400005];
int f[200005];
namespace dsu{
	#define zero (n+1)
	#define one (n*2+2)
	void init()
	{
		for(int i=1;i<=n*2+2;++i)//n+1 - zero , n*2+2 - one
		{
			p[i]=i;
			siz[i]=1;
		}
	}
	int getp(int x)
	{
		if(p[x]==x) return x; return p[x]=getp(p[x]);
	}
	void merge(int x,int y)
	{
		x=getp(x);y=getp(y);
		if(x==y) return;
		if(siz[x]>siz[y]) swap(x,y);
		siz[y]+=siz[x];
		p[x]=y;
	}
	bool same(int x,int y)
	{
		return getp(x)==getp(y);
	}
	void merge(int x,int y,int state)//0 means same
	{
		merge(x,y+state*(n+1));
		merge(x+n+1,y+(state^1)*(n+1));
	}
	bool sat_able()
	{
		for(int i=1;i<=n;++i) if(same(i,i+n+1)) return 0;
		return 1;
	}
	void answer(int *arr)
	{
		for(int i=1;i<=n;++i)
		{
			if(same(i,zero)) arr[i]=0;
			else if(same(i,one)) arr[i]=1;
			else
			{
				merge(i,zero,0);
				arr[i]=0;
			}
		}
	}
	#undef zero
	#undef one
}
using namespace dsu;
vector<pair<int,int> > con[200005];//this is in popcount(0,1,-1)
int popcnt(int x)
{
	int res=0;
	while(x)
	{
		x&=(x-1);res^=1;
	}
	return res;
}
void dfs(int x,int p,int val)
{
	if(val!=-1) merge(x,p,val);
	rep(i,con[x].size())
	{
		int u=con[x][i].first;
		if(u!=p) dfs(u,x,con[x][i].second);
	}
}
void Q()
{
	cin>>n>>q;
	rep1(i,n) con[i].clear();
	rep(i,n-1)
	{
		#define u u[i]
		#define v v[i]
		#define w w[i]
		cin>>u>>v>>w;
		con[u].pb(mp(v,(w!=-1)?popcnt(w):w));
		con[v].pb(mp(u,(w!=-1)?popcnt(w):w));
		#undef u
		#undef v
		#undef w
	}
	init();
	dfs(1,-1,-1);
	merge(1,n+1,0);
	while(q--)
	{
		cin>>u2>>v2>>w2;
		merge(u2,v2,w2);
	}
	if(!sat_able())
	{
		cout<<"NO"<<endl;
		return;
	}
	cout<<"YES"<<endl;
	answer(f);
	rep(i,n-1)
	{
		cout<<u[i]<<' '<<v[i]<<' ';
		if(w[i]!=-1) cout<<w[i]<<endl;
		else cout<<(f[u[i]]^f[v[i]])<<endl;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>t;
	while(t--)
	Q();
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