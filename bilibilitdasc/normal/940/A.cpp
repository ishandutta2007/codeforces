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
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int n,d;
int x[105];
int ans=0x3f3f3f3f;
int main()
{
	scanf("%d%d",&n,&d);
	for(int i=0;i<n;i++) scanf("%d",&x[i]);
	sort(x,x+n);
	for(int i=0;i<n;i++) for(int j=0;j<=i;j++)
	{
		if(x[i]-x[j]<=d)
		{
			ans=min(ans,n-i+j-1);
			continue;
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
3 1
2 1 4

3 0
7 7 7

6 3
1 3 4 6 9 10

5 4
1 2 3 4 5

5 3
1 5 9 13 17


*/