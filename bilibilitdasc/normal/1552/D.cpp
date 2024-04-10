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
int t,n,mx;
int a[20];
int s[2000];
void Q()
{
	scanf("%d",&n);
	memset(s,0,sizeof(s));
	rep(i,n)
	{
		scanf("%d",a+i);
		a[i]=abs(a[i]);
	}
	mx=(1<<n);
	rep(i,mx)
	{
		rep(j,n)
		{
			if((i>>j)&1)
			{
				s[i]+=a[j];
			}
		}
	}
	sort(s,s+mx);
	for(int i=1;i<mx;++i)
	{
		if(s[i]==s[i-1])
		{
			printf("YES\n",s[i]);
			return ;
		}
	}
	printf("NO\n");
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