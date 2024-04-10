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
int t,n,k;
int a[200005];
int cnt[200005];
int ued[200005];
int clr[200005];
int ttluse;
int p[200005];
bool cmp(int i,int j)
{
	return a[i]<a[j];
}
void Q()
{
	scanf("%d%d",&n,&k);
	rep1(i,n) cnt[i]=ued[i]=0;
	rep(i,n) clr[i]=0,p[i]=i;
	ttluse=0;
	rep(i,n)
	{
		scanf("%d",a+i);
		++cnt[a[i]];
	}
	rep1(i,n)
	{
		if(cnt[i]<k) ttluse+=cnt[i];
	}
	ttluse=ttluse/k*k;
	sort(p,p+n,cmp);
	rep(i,n)
	{
		if(cnt[a[p[i]]]>=k)
		{
			if(ued[a[p[i]]]<k)
			{
				clr[p[i]]=(++ued[a[p[i]]]);
			}
		}
		else
		{
			if(ttluse)
			{
				clr[p[i]]=(ttluse--)%k+1;
			}
		}
	}
	rep(i,n)
	{
		printf("%d%c",clr[i],((i==n-1)?'\n':' '));
	}
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