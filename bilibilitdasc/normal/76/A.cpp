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
int n,m,G,S;
struct edge{
	int u,v;
	ll g,s;
	void input()
	{
		cin>>u>>v>>g>>s;
		g*=G;s*=S;
	}
};
bool cmp1(const edge&a,const edge&b)
{
	return a.g<b.g;
}
bool cmp2(const edge&a,const edge&b)
{
	return a.s<b.s;
}
int f[205],siz[205];
void init()
{
	rep1(i,n) f[i]=i,siz[i]=1;
}
int getp(int x)
{
	return f[x]==x?x:f[x]=getp(f[x]);
}
bool mer(int x,int y)
{
	x=getp(x);y=getp(y);
	if(x==y) return 0;
	if(siz[x]>siz[y]) swap(x,y);
	siz[y]+=siz[x];f[x]=y;
	return 1;
}
edge e[50005];
edge edges[205];int cnt1;
edge edge2[205];int cnt2;
int cnt;
ll ans=0x3f3f3f3f3f3f3f3fll;
bool k()
{
	init();
	int ind=cnt1-1;
	while(ind&&cmp2(edges[ind],edges[ind-1]))
	{
		swap(edges[ind],edges[ind-1]);
		--ind;
	}
	cnt=cnt2=0;
	rep(i,cnt1)
	{
		if(mer(edges[i].u,edges[i].v))
		{
			++cnt;
		//	printf("%d<->%d %lld g %lld s\n",edges[i].u,edges[i].v,edges[i].g,edges[i].s);
			edge2[cnt2++]=edges[i];
		}
	}
	rep(i,max(cnt1,cnt2)) swap(edges[i],edge2[i]);
	swap(cnt1,cnt2);
	//printf("\n");
	return cnt==n-1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>G>>S;
	rep(i,m) e[i].input();
	sort(e,e+m,cmp1);
	for(int i=0;i<m;++i)
	{
		edges[cnt1++]=e[i];
		if(k())
		{
			ans=min(ans,edges[cnt1-1].s+e[i].g);
		}
	}
	if(ans==0x3f3f3f3f3f3f3f3fll) ans=-1;
	cout<<ans<<endl;
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