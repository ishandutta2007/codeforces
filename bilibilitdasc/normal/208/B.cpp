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
string s[52]={	"2C","2D","2H","2S","3C","3D","3H","3S","4C","4D","4H","4S","5C","5D","5H","5S","6C","6D","6H","6S",
				"7C","7D","7H","7S","8C","8D","8H","8S","9C","9D","9H","9S","TC","TD","TH","TS","JC","JD","JH","JS",
				"QC","QD","QH","QS","KC","KD","KH","KS","AC","AD","AH","AS"};
int n;
int have[55];
bool dp[55][55][55][55];
map<string,int> ind;
string ss;
bool fi(int a,int b)
{
	return ((a&3)==(b&3)||(a>>2)==(b>>2));
}
int main()
{
	ios_base::sync_with_stdio(false);
	rep(i,52) ind[s[i]]=i;
	cin>>n;
	rep(i,n)
	{
		cin>>ss;
		have[i]=ind[ss];
	}
	dp[n][have[n-3]][have[n-2]][have[n-1]]=1;
	for(int i=n;i>=2;i--) rep(j,52) rep(k,52) rep(l,52)
	{
		if(dp[i][j][k][l])
		{
			if(fi(k,l))
			{
				dp[i-1][have[i-4]][j][l]=1;
			}
			if(i>=4&&fi(have[i-4],l))
			{
				dp[i-1][l][j][k]=1;
			}
		}
	}
	rep(j,52) rep(k,52) rep(l,52) if(dp[1][j][k][l])
	{
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}