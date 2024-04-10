#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>ko[200000];
typedef long long ll;
ll mod = 1000000007;
ll dp1[200000];
ll dp2[200000];
void calc1(int node)
{
	ll t = 1;
	for (int i = 0; i < ko[node].size(); i++)
	{
		calc1(ko[node][i]);
		t *= dp1[ko[node][i]];
		t %= mod;
	}
	dp1[node] = (t + 1) % mod;
}
void calc2(int node)
{
	vector<ll>v;
	for (int i = 0; i < ko[node].size(); i++)
	{
		v.push_back(dp1[ko[node][i]]);
	}
	vector<ll>r1, r2;
	r1.resize(v.size() + 1);
	r2.resize(v.size() + 1);
	r1[0] = r2[v.size()] = 1;
	for (int i = 0; i < v.size(); i++)r1[i + 1] = (r1[i] * v[i]) % mod;
	for (int i = int(v.size() - 1); i >= 0; i--)r2[i] = (r2[i + 1] * v[i]) % mod;
	for (int i = 0; i < ko[node].size(); i++)
	{
		dp2[ko[node][i]] = (dp2[node] * (r1[i] * r2[i + 1] % mod) + 1) % mod;
	}
	for (int i = 0; i < ko[node].size(); i++)calc2(ko[node][i]);
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
	calc1(0);
	dp2[0] = 1;
	calc2(0);
	for (int i = 0; i < num; i++)
	{
		if (i != 0)printf(" ");
		ll t = 1;
		for (int j = 0; j < ko[i].size(); j++)
		{
			t *= dp1[ko[i][j]];
			t %= mod;
		}
		printf("%I64d", (t*dp2[i]) % mod);
	}
	printf("\n");
}