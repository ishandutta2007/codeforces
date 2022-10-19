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
int dp[105][26][105];
int n,k,l;
string s;
char x,y;
int c[26][26],ans=0xc0c0c0c0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>s>>k>>n;l=s.size();
	while(n--)
	{
		cin>>x>>y;
		cin>>c[x-'a'][y-'a'];
	}
	memset(dp,0xc0,sizeof(dp));
	for(char cc='a';cc<='z';++cc)
	dp[1][cc-'a'][s[0]!=cc]=0;
	for(int i=2;i<=l;++i)
	dp[i][s[i-1]-'a'][0]=c[s[i-2]-'a'][s[i-1]-'a']+dp[i-1][s[i-2]-'a'][0];
	for(int i=2;i<=l;++i)
	for(int r=1;r<=i;++r)
	for(char j='a';j<='z';++j)
	for(char cs='a';cs<='z';++cs)
	dp[i][j-'a'][r]=max(dp[i][j-'a'][r],dp[i-1][cs-'a'][r-(j!=s[i-1])]+c[cs-'a'][j-'a']);
	for(int j=0;j<26;++j) for(int i=0;i<=k;++i)
	ans=max(ans,dp[l][j][i]);
	cout<<ans<<endl;
	return 0;
}
/* things to check
1. int overflow or long long memory need
2. recursion/array/binary search/dp bounds
3. precision
4. forever loop
5. special cases(n=1,bounds)
*/