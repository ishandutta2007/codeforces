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
int n;
int a[200005];
int Count[200005];
bool Vis[200005];
int mx;
int mxl,mxr;
vector<int> cnt1;
vector<int> ls;
vector<int> rs;
queue<int> ans1;
stack<int> ans2;
void calc(int l,int r)
{
	if(l>r) return;
	cnt1.clear();
	cnt1.pb(l);
	for(int i=l+1;i<r;++i)
	if(Count[a[i]]==1) cnt1.pb(i);
	cnt1.pb(r);
	for(int i=1,siz=cnt1.size();i<siz;++i)
	{
		if(cnt1[i]-cnt1[i-1]>mx)
		{
			mx=cnt1[i]-cnt1[i-1];
			mxl=cnt1[i-1],mxr=cnt1[i];
		}
	}
}
int main()
{
	scanf("%d",&n);
	rep(i,n)
	{
		scanf("%d",&a[i]);
		++Count[a[i]];
	}
	sort(a,a+n);
	ls.pb(0);
	for(int i=0;i+1<n;++i) if(a[i+1]-a[i]>1)
	{
		ls.pb(i+1);rs.pb(i);
	}
	rs.pb(n-1);
	for(int i=0,siz=ls.size();i<siz;++i)
	{
		calc(ls[i],rs[i]);
	}
	printf("%d\n",++mx);
	for(int i=mxl;i<=mxr;++i)
	{
		if(!Vis[a[i]])
		{
			Vis[a[i]]=1;
			ans1.push(a[i]);
		}
		else
		{
			ans2.push(a[i]);
		}
	}
	while(!ans1.empty())
	{
		printf("%d",ans1.front());
		ans1.pop();
		if(ans1.empty()&&ans2.empty()) printf("\n");
		else printf(" ");
	}
	while(!ans2.empty())
	{
		printf("%d",ans2.top());
		ans2.pop();
		if(ans2.empty()) printf("\n");
		else printf(" ");
	}
	return 0;
}
/* things to check
1.  int overflow or long long memory need
2.  recursion/array/binary search/dp/loop bounds
3.  precision
4.  special cases(n=1,bounds)
5.  delete debug statements or using #ifdef DEBUG
6.  initialize(especially multi-tests)
7.  = or == , n or m ,++ or -- , i or j , > or >= , < or <=
8.  keep it simple and stupid
9.  do not delete, use // instead
10. operator priority
11. is there anything extra to output?
12. ...
*/

/* something to think about
1. greedy? dp? searching? dp with matrix/ segment tree/ binary indexed tree? binary search?
2. If contains "not", why not  or few affect?
*/