#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1;i<=(n);++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define repk(i,a,b) for(int i=(a);i<=(b);++i)
#define perk(i,a,b) for(int i=(a);i>=(b);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define pb push_back
#define mp make_pair
#define g(x) cout<<#x<<'='<<x<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int t,n,k,x,y,cnt;
int itw[205];
vector<int> nv;
bool itsct(int as,int ae,int bs,int be)
{
	if(as<ae&&bs<be&&as<bs)
	{
		if(bs<ae&&ae<be)
		{
			return 1;
		}
	}
	return 0;
}
void Q()
{
	scanf("%d%d",&n,&k);nv.clear();memset(itw,0,sizeof(itw));cnt=0;
	rep(i,k)
	{
		scanf("%d%d",&x,&y);
		itw[x]=y;itw[y]=x;
	}
	for(int i=1,l=(n<<1);i<=l;++i)
	{
		if(!itw[i]) nv.pb(i);
	}
	for(int i=0,l=(n-k);i<l;++i)
	{
		itw[nv[i]]=nv[i+n-k];
		itw[nv[i+n-k]]=nv[i];
	}
	for(int i=1,l=(n<<1);i<=l;++i) for(int j=1;j<=l;++j)
	{
		if(itsct(i,itw[i],j,itw[j]))
		++cnt;
	}
	printf("%d\n",cnt);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	Q();
	return 0;
}
/* things to check
1. int overflow or long long memory need
2. recursion/array/binary search/dp bounds
3. precision
4. forever loop
5. special cases(n=1,bounds)
*/