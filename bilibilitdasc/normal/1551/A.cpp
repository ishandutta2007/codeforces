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
int t,n;
void Q()
{
	scanf("%d",&n);
	if(n%3==0)
	{
		printf("%d %d\n",n/3,n/3);
	}
	else if(n%3==1)
	{
		printf("%d %d\n",n/3+1,n/3);
	}
	else
	{
		printf("%d %d\n",n/3,n/3+1);
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