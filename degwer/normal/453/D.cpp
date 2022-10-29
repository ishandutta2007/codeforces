#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll> >mat;
ll mod;
mat e;
void makee(int n)
{
	e.clear();
	e.resize(n);
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			e[i].push_back(i == j);
		}
	}
}
mat tim(mat a, mat b)
{
	mat ret;
	ret.resize(a.size());
	for (int i = 0; i<a.size(); i++)ret[i].resize(b[0].size());
	for (int i = 0; i<a.size(); i++)
	{
		for (int j = 0; j<b[0].size(); j++)
		{
			for (int k = 0; k<a[0].size(); k++)
			{
				ret[i][j] += a[i][k] * b[k][j];
				if (k == ((k >> 3) << 3))ret[i][j] %= mod;
			}
			ret[i][j] %= mod;
		}
	}
	return ret;
}
mat po(mat a, ll b)
{
	if (b == 0)return e;
	mat z = po(a, b / 2);
	z = tim(z, z);
	if (b % 2 == 1)z = tim(z, a);
	return z;
}
int popc[1048576];
int dp[2][1048576][21];
int main()
{
	int num;
	ll kai;
	scanf("%d%I64d%I64d", &num, &kai, &mod);
	makee(num + 1);
	mat t;
	t.resize(num + 1);
	for (int i = 0; i <= num; i++)t[i].resize(num + 1);
	vector<ll>dat;
	for (int i = 0; i < (1 << num); i++)
	{
		ll z;
		scanf("%I64d", &z);
		dat.push_back(z);
	}
	vector<ll>vec;
	for (int i = 0; i <= num; i++)
	{
		ll z;
		scanf("%I64d", &z);
		vec.push_back(z);
	}
	for (int i = 0; i < (1 << num); i++)
	{
		for (int j = 0; j < num; j++)if (i&(1 << j))popc[i]++;
	}
	for (int i = 0; i <= num; i++)
	{
		int n = (1 << i) - 1;
		for (int j = 0; j < (1 << num); j++)
		{
			t[i][popc[j]] += vec[popc[n^j]];
			t[i][popc[j]] %= mod;
		}
	}
	t = po(t, kai);
	int cur = 0;
	for (int i = 0; i < (1 << num); i++)dp[0][i][0] = dat[i];
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < (1 << num); j++)
		{
			dp[1 - cur][j][0] = dp[cur][j][0];
			for (int k = 1; k <= num;k++)
			{
				dp[1 - cur][j][k] = (dp[cur][j][k] + dp[cur][j ^ (1 << i)][k - 1]) % mod;
			}
		}
		for (int j = 0; j < (1 << num); j++)
		{
			for (int k = 0; k <= num; k++)
			{
				dp[cur][j][k] = 0;
			}
		}
		cur = 1 - cur;
	}
	for (int i = 0; i < (1 << num); i++)
	{
		ll ans = 0;
		for (int j = 0; j <= num; j++)
		{
			ans += (ll)(dp[cur][i][j]) *t[j][0];
			ans %= mod;
		}
		printf("%I64d\n", ans);
	}
}