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
set<int> sqr;
int n;
#define kill(a) cout<<((a)?("YES"):("NO"))<<endl;return
void Q()
{
	cin>>n;
	if(n&1)
	{
		kill(0);
	}
	if(sqr.count(n>>1))
	{
		kill(1);
	}
	if(n&2)
	{
		kill(0);
	}
	if(sqr.count(n>>2))
	{
		kill(1);
	}
	kill(0);
}
int main()
{
	ios_base::sync_with_stdio(false);
	for(int i=1;i*i<=1000000000;i++)
	{
		sqr.insert(i*i);
	}
	int T;
	cin>>T;
	while(T--) Q();
	return 0;
}