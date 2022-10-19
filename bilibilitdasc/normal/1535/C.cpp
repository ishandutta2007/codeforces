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
//ios_base::sync_with_stdio(false);cin
char s[200200];
int t,l;
//parity: (i^a[i])&1
vector<int> p[2];
int ans[200200];
long long res;
inline int parity(int i)
{
	return (i^s[i])&1;
}
void solve()
{
	scanf("%s",s);l=strlen(s);
	memset(ans,0,sizeof(ans));res=0;
	p[0].clear();p[1].clear();
	rep(i,l)
	{
		if(s[i]!='?')
		{
			p[parity(i)].pb(i);
		}
	}
	p[0].pb(l);p[1].pb(l);
	per(i,l)
	{
		if(s[i]=='?')
		{
			ans[i]=ans[i+1]+1;
		}
		else
		{
			ans[i]=(*upper_bound(p[!parity(i)].begin(),p[!parity(i)].end(),i))-i;
		}
		res+=ans[i];
	}
	printf("%lld\n",res);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	solve();
	return 0;
}