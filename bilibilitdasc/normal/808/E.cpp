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
int n,m,w,c;
vector<ll> W[5];
vector<ll> S[5];
vector<ll> Q[5];
ll C[5];
ll ret;
void Check(int Y,int Z)
{
	if(Y>=0&&Z>=0&&2*Y+Z*3<=m&&Y<=int(W[2].size())&&Z<=int(W[3].size()))
	{
		ret=max(ret,S[1][min(W[1].size(),size_t(m-2*Y-3*Z))]+S[2][Y]+S[3][Z]);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	rep(i,n)
	{
		cin>>w>>c;
		W[w].pb(c);
		rep(_,w)
		Q[w].pb(c*6/w);
	}
	rep1(i,3)
	{
		sort(W[i].begin(),W[i].end(),greater<int>());
		sort(Q[i].begin(),Q[i].end(),greater<int>());
	}
	rep1(i,3)
	{
		S[i].pb(0);
		rep(j,W[i].size())
		{
			S[i].pb(S[i].back()+W[i][j]);
		}
	}
	rep1(i,m)
	{
		if(C[1]<Q[1].size()&&(C[3]==Q[3].size()||Q[1][C[1]]>=Q[3][C[3]])&&(C[2]==Q[2].size()||Q[1][C[1]]>=Q[2][C[2]]))
		{
			++C[1];
		}
		else if (C[2]<Q[2].size()&&(C[3]==Q[3].size()||Q[2][C[2]]>=Q[3][C[3]]))
		{
			++C[2];
		}
		else if(C[3]<Q[3].size())
		{
			++C[3];
		}
	}
	C[2]/=2;C[3]/=3;
	for(int j=-5000;j<=5000;++j) for(int k=-5000;k<=5000;++k)
	Check(C[2]+j,C[3]+k);
	cout<<ret<<endl;
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