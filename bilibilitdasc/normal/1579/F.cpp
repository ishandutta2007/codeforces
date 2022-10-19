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
int n,d;
int a[1000005];
vector<vector<int> > vec;
vector<int> tp;//to push
bool vis[1000005];
void Push(int i)
{
	vis[i]=1;
	tp.pb(a[i]);
	i+=d;if(i>=n) i-=n;
	if(!vis[i]) Push(i);
}
void Gen_push()
{
	vec.clear();
	rep(i,n)
	if(!vis[i])
	{
		tp.clear();
		Push(i);
		vec.pb(tp);
	}
}
void OutputLine()
{
	rep(i,32) putchar('-');putchar(10);
}
void OutputVec()
{
	OutputLine();
	rep(i,vec.size())
	{
		rep(j,vec[i].size())
		{
			cout<<vec[i][j];
			if(j==vec[i].size()-1)
			cout<<endl;
			else
			cout<<' '; 
		}
	}
	OutputLine();
}
int dp[1000005];
int Calc_one(const vector<int>&v)
{
	int l=v.size();
	int ind=-1;
	rep(i,l)
	{
		if(v[i]==0)
		{
			ind=i;dp[i]=0;
		}
		else
		{
			dp[i]=0x3f3f3f3f;
		}
	}
	if(ind==-1)
	{
		return 0x3f3f3f3f;
	}
	int tl=l;
	while(tl--)
	{
		--ind;
		if(ind<0) ind=l-1;
		dp[ind]=min(dp[ind],dp[(ind+1)%l]+1);
	}
	tl=0;
	rep(i,l) tl=max(tl,dp[i]);
	return tl;
}
int res;
void Q()
{
	cin>>n>>d;res=0;
	rep(i,n) 
	{
		cin>>a[i];vis[i]=0;
	}
	Gen_push();
	//OutputVec();
	rep(i,vec.size())
	{
		res=max(res,Calc_one(vec[i]));
	}
	if(res==0x3f3f3f3f) res=-1;
	cout<<res<<'\n';
}
int t;
int main()
{
	//freopen("test.in","r",stdin);
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