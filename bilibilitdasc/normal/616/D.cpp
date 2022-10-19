#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define per1(i,n) for(int i=(n);i>=1;i--)
#define repk(i,a,b) for(int i=(a);i<=(b);i++)
#define perk(i,a,b) for(int i=(a);i>=(b);i--)
#define rep0(i,a,b) for(int i=(a);i<(b);i++)
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
//long long , 
//ios_base::sync_with_stdio(false);cin
int n,k;
int a[500005];
int cnt[1000006],cont;
int ml,mr=-114514,r=1;
inline void inc(int x)
{
	if(!(cnt[x]++)) ++cont;
}
inline void dec(int x)
{
	if(!(--cnt[x])) --cont;
}
int main()
{
	scanf("%d%d",&n,&k);
	rep1(i,n)
	scanf("%d",a+i);
	rep1(l,n)
	{
		while(cont<=k&&r<=n)
		inc(a[r++]);
		if(cont>k)
		dec(a[--r]);
		if(r-l>mr-ml)
		ml=l,mr=r;
		dec(a[l]);
	}
	printf("%d %d\n",ml,mr-1);
	return 0;
}