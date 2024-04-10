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
int t,n;
int to[200005];
vector<int> fr[200005];
int color[200005];
int mxk;
vector<int> answer;
void Make_It_Colored(int u,int C)
{
	color[u]=C;
	if(C==1) mxk=max(mxk,u);
	rep(it,fr[u].size()) Make_It_Colored(fr[u][it],C^1);
}
void Q()
{
	cin>>n;
	rep(i,n+2) fr[i].clear();
	to[n+1]=0;fr[0].pb(n+1);
	rep1(i,n)
	{
		cin>>to[i];fr[to[i]].pb(i);
	}
	mxk=0;
	Make_It_Colored(0,1);
	cout<<mxk<<endl;
	answer.clear();
	answer.pb(0);
	while(int(answer.size())!=n+2)
	{
		int v=answer.back();
		int pretest=-1;
		rep(i,fr[v].size())
		{
			int to=fr[v][i];
			if(fr[to].empty()) answer.push_back(to);
			else pretest=to;
		}
		if(pretest!=-1) answer.push_back(pretest);
	}
	for(int i=2;i<=n+1;++i) cout<<answer[i]<<" \n"[i==n+1];
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