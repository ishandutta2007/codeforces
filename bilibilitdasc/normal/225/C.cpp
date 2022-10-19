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
//cin
int n,m,x,y;
string s;
int b[1005];
int bs[1005];
int w[1005];
int wss[1005];
int dp[1005][2];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>x>>y;
	rep(i,n)
	{
		cin>>s;
		rep(j,m)
		{
			if(s[j]=='#') ++b[j+1];
			else ++w[j+1];
		}
	}
	rep1(i,m) bs[i]=bs[i-1]+b[i];
	rep1(i,m) wss[i]=wss[i-1]+w[i];
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	dp[0][1]=0;
	rep1(i,m)
	{
		repk(j,x,y)
		{
			if(i-j>=0)
			{
				dp[i][0]=min(dp[i][0],dp[i-j][1]+bs[i]-bs[i-j]);
				dp[i][1]=min(dp[i][1],dp[i-j][0]+wss[i]-wss[i-j]);
			}
			else
			{
				break;
			}
		}
	}
	cout<<min(dp[m][0],dp[m][1])<<endl;
	return 0;
}