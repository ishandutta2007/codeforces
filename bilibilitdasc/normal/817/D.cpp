#include <bits/stdc++.h>
/*????????code*/
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
//ios_base::sync_with_stdio(false);???cin
int n;
ll a[2][1000006];
int p[1000006];
int P[1000006];
int S[1000006];
int cnt[1000006];
void mysort()
{
	rep1(i,n) ++cnt[a[0][i]];
	rep1(i,1000000) cnt[i]+=cnt[i-1];
	per1(i,n) p[cnt[a[0][i]]--]=i;
}
int getp(int x)
{
	return (P[x]==x)?x:(P[x]=getp(P[x]));
}
void make(int x,int y)
{
	x=getp(x);y=getp(y);
	if(x==y) return;
	if(S[x]>S[y]) swap(x,y);
	P[x]=y;S[y]+=S[x];
}
template<int id>
bool cmp(int x,int y)
{
	return a[id][x]<a[id][y];
}
template<int id>
ll summax()
{
	if(id==0) mysort();
	else reverse(p+1,p+1+n);
//	rep1(i,n) cout<<p[i]<<' ';
//	cout<<endl; 
	ll ret=0;
	//   1  2  3  4
	// 1 |  2  | 1| 1
	rep1(i,n+1)
	{
		P[i]=i;S[i]=1; 
	}
	for(int i=1;i<=n;++i)
	{
		ret+=S[getp(p[i])]*1ll*S[getp(p[i]+1)]*a[id][p[i]];
//		cout<<ret<<' '<<p[i]<<" ! "<<S[p[i]]<<' '<<S[p[i]+1]<<' '<<ret<<endl;
		make(p[i],p[i]+1);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	rep1(i,n)
	{
		cin>>a[0][i];a[1][i]=-a[0][i];
	}
//	cout<<(summax<0>())<<' '<<(summax<1>())<<endl;
	
	cout<<summax<0>()+summax<1>()<<endl;
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
2. If contains "not", why not ?????? or few affect?
*/