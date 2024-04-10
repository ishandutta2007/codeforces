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
int res,t,n;
int r[50005][5];
bool first_greater_than_second(int i,int j)
{
	int cnt=0;
	rep(a,5)
	{
		if(r[i][a]<r[j][a]) ++cnt;
	}
	return (cnt>=3);
}
void Q()
{
	scanf("%d",&n);
	rep(i,n)
	{
		scanf("%d%d%d%d%d",&r[i][0],&r[i][1],&r[i][2],&r[i][3],&r[i][4]);
	}
	res=0;
	for(int i=1;i<n;++i)
	{
		if(first_greater_than_second(i,res))
		{
			res=i;
		}
	}
	for(int i=0;i<n;++i)
	{
		if(first_greater_than_second(i,res))
		{
			printf("-1\n");
			return;
		}
	}
	printf("%d\n",++res);
}
int main()
{
	cin>>t;
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