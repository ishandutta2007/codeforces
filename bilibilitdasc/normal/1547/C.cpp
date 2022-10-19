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
int t,k,n,m,s;
int c[205],cc;
int a[105],b[105],ca,cb;
void Q()
{
	scanf("%d%d%d",&k,&n,&m);
	rep(i,n) scanf("%d",a+i);
	rep(i,m) scanf("%d",b+i);
	ca=cb=cc=0;s=n+m;
	while(s--)
	{
		if(a[ca]==0&&ca!=n)
		{
			c[cc++]=0;
			++k;
			++ca;
		}
		else if(b[cb]==0&&cb!=m)
		{
			c[cc++]=0;
			++k;
			++cb;
		}
		else if(a[ca]<=k&&ca!=n)
		{
			c[cc++]=a[ca++];
		}
		else if(b[cb]<=k&&cb!=m)
		{
			c[cc++]=b[cb++];
		}
		else
		{
			printf("-1\n");
			return ;
		}
	}
	rep(i,cc)
	{
		printf("%d%c",c[i],((i==cc-1)?'\n':' '));
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