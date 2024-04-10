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
int n,m,k;
int a[14][14];
int cr[14];
int can[14][14][14];
int ans; 
void dfs(int x,int y,int mx)
{
	if(x==n)
	{
		rep1(i,mx) rep1(j,i-1) if(cr[i]==cr[j]&&cr[i]) return;
		int eij=0,eqe=k;
		rep1(i,mx) if(cr[i]) --eqe; else ++eij;
		int ret=1;
		rep(i,eij) ret=ret*(eqe--);
		ans+=ret;if(ans>=mod2)ans-=mod2;
		return;	
	}
	int X=x,Y=y+1;
	if(Y==m)
	{
		Y=0;++X;
	}
	for(int i=1;i<=mx;++i)
	{
		if(can[x][y][i]==0&&(a[x][y]==0||cr[i]==0||cr[i]==a[x][y]))
		{
		//	cout<<"("<<x<<","<<y<<")"<<' '<<i<<endl;
			for(int _=x;_<n;++_) for(int __=y;__<m;++__) ++can[_][__][i];
			bool fl=a[x][y]&&(cr[i]==0);
			if(fl) cr[i]=a[x][y];
			dfs(X,Y,mx);
			if(fl) cr[i]=0;
			for(int _=x;_<n;++_) for(int __=y;__<m;++__) --can[_][__][i];
		}
	}
	if(mx<k)
	{
		//	cout<<"("<<x<<","<<y<<")"<<' '<<i<<endl;
		for(int _=x;_<n;++_) for(int __=y;__<m;++__) ++can[_][__][mx+1];
		bool fl=a[x][y];
		if(fl) cr[mx+1]=a[x][y];
		dfs(X,Y,mx+1);
		if(fl) cr[mx+1]=0;
		for(int _=x;_<n;++_) for(int __=y;__<m;++__) --can[_][__][mx+1];
	}
	
}
int main()
{
	cin>>n>>m>>k;
	if(n+m-1>k)
	{
		cout<<0<<endl;return 0;
	}
	rep(i,n) rep(j,m) cin>>a[i][j];
	dfs(0,0,0);
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