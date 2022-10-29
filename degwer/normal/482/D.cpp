#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll dp[100000][2];
vector<int>ko[100000];
void calc(int node)
{
	for (int i = 0; i < ko[node].size(); i++)calc(ko[node][i]);
	ll n00 = 1, n01 = 0;
	ll n10 = 1, n11 = 0;
	for (int i = 0; i < ko[node].size(); i++)
	{
		ll a = n00 + n00*dp[ko[node][i]][0] + n01*dp[ko[node][i]][1];
		ll b = n01 + n00*dp[ko[node][i]][1] + n01*dp[ko[node][i]][0];
		n00 = a%mod, n01 = b%mod;
	}
	for (int i = int(ko[node].size()) - 1; i >= 0; i--)
	{
		ll a = n10 + n10*dp[ko[node][i]][0] + n11*dp[ko[node][i]][1];
		ll b = n11 + n10*dp[ko[node][i]][1] + n11*dp[ko[node][i]][0];
		n10 = a%mod, n11 = b%mod;
	}
	ll al0 = 1, al10 = 1, al11 = 0;
	for (int i = 0; i < ko[node].size(); i++)
	{
		al0 = al0*(dp[ko[node][i]][0] + 1) % mod;
		ll a = al10 + al11*dp[ko[node][i]][1];
		ll b = al11 + al10*dp[ko[node][i]][1];
		al10 = a%mod, al11 = b%mod;
	}
	dp[node][1] = (n00 + n10 + mod - al0) % mod;
	dp[node][0] = (n01 + n11 + mod - al11) % mod;
	//printf("%d   %I64d %I64d  %I64d %I64d  %I64d  %I64d %I64d    %I64d %I64d\n", node, n00, n01, n10, n11, al0, al10, al11, dp[node][0], dp[node][1]);
}
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 1; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		z--;
		ko[z].push_back(i);
	}
	calc(0);
	printf("%I64d\n", (dp[0][0] + dp[0][1]) % mod);
}