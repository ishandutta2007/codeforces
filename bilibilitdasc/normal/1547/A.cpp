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
int a,b,c,d,e,f,g,h;
void Q()
{
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	g=abs(a-c)+abs(b-d);
	if(a==e&&c==e)
	{
		if(min(d,b)<f&&f<max(b,d))
		{
			++++g;
		}
	}
	if(b==f&&d==f)
	{
		if(min(a,c)<e&&e<max(a,c))
		{
			++++g;
		}
	}
	printf("%d\n",g);
}
int main()
{
	scanf("%d",&h);
	while(h--)
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