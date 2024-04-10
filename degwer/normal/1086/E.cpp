#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 2048
typedef long long ll;
ll mod = 998244353;
class BIT
{
public:
	int bit[SIZE + 1];
	void init()
	{
		fill(bit, bit + SIZE + 1, 0);
	}
	void add(int a, int b)
	{
		a++;
		for (;;)
		{
			bit[a] += b;
			a += a&-a;
			if (a > SIZE)return;
		}
	}
	int get(int a)
	{
		a++;
		int ret = 0;
		for (;;)
		{
			ret += bit[a];
			a -= a&-a;
			if (a == 0)return ret;
		}
	}
};
BIT bi1, bi2;
int m[2020][2020];
ll dp[2020][2020];
int d1[2020];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)for (int j = 0; j < num; j++)scanf("%d", &m[i][j]);
	dp[0][0] = 1;
	for (int i = 1; i <= num + 10; i++)dp[i][0] = dp[i - 1][0] * i%mod;
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j >= 2)dp[i][j] += dp[i - 1][j - 2] * (j - 1);
			dp[i][j] += dp[i - 1][j - 1] * (i - j);
			dp[i][j] %= mod;
		}
		//for (int j = 0; j <= i; j++)printf("%I64d ", dp[i][j]);
		//printf("\n");
	}
	ll tim = 1, ans = 0;
	for (int i = num - 2; i >= 0; i--)
	{
		bi1.init(), bi2.init();
		fill(d1, d1 + num + 10, 0);
		ll sum = 0;
		int cnt = 0;
		for (int j = num - 1; j >= 0; j--)
		{
			d1[m[i + 1][j]]++;
			if (d1[m[i + 1][j]] == 2)cnt++, bi1.add(m[i + 1][j], 1);
			bi2.add(m[i + 1][j], 1);
			int t2 = bi2.get(m[i + 1][j] - 1), t1 = bi1.get(m[i + 1][j] - 1);
			if (bi2.get(m[i][j]) != bi2.get(m[i][j] - 1) && m[i][j] < m[i + 1][j])t2--;
			sum += dp[num - j - 1][cnt] * (t2 - t1);
			if (cnt > 0)sum += dp[num - j - 1][cnt - 1] * t1;
			sum %= mod;
			d1[m[i][j]]++;
			if (d1[m[i][j]] == 2)cnt++, bi1.add(m[i][j], 1);
		}
		//printf("\n");
		//printf("%I64d\n", sum);
		ans += tim*sum;
		ans %= mod;
		tim *= dp[num][num];
		tim %= mod;
	}
	ll ad = 0, ztim = 1;
	fill(d1, d1 + num + 10, 0);
	for (int i = num - 1; i >= 0; i--)
	{
		ll c = 0;
		for (int j = 1; j < m[0][i]; j++)c += d1[j];
		ad = (ad + c*ztim) % mod;
		d1[m[0][i]] = 1;
		ztim = ztim*(num - i) % mod;
	}
	printf("%I64d\n", (ad*tim + ans) % mod);
}