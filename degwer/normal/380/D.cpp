#include<stdio.h>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
#define SIZE 300000
ll inv[SIZE + 1];
ll kai[SIZE + 1];
ll invkai[SIZE + 1];
typedef pair<int, int>pii;
void invinit()
{
	inv[1] = 1;
	for (int i = 2; i <= SIZE; i++)
	{
		inv[i] = mod - (mod / i)*inv[mod%i] % mod;
	}
	kai[0] = invkai[0] = 1;
	for (int i = 1; i <= SIZE; i++)
	{
		kai[i] = kai[i - 1] * i%mod;
		invkai[i] = invkai[i - 1] * inv[i] % mod;
	}
}
ll com(ll a, ll b)
{
	if (b < 0 || a < b)return 0;
	return (invkai[b] * invkai[a - b]) % mod*kai[a] % mod;
}
ll p2[300001];
int main()
{
	int num;
	scanf("%d", &num);
	p2[0] = 1;
	for (int i = 1; i <= 200000; i++)p2[i] = p2[i - 1] * 2 % mod;
	deque<pii>deq;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		if (z != 0)deq.push_back(make_pair(i, z));
	}
	invinit();
	ll ans = 1;
	int lb = 0, ub = num - 1;
	int now = 1000000000;
	for (;;)
	{
		if (deq.size() == 0)
		{
			ans = ans*p2[ub - lb] % mod;
			break;
		}
		if (now <= max(deq[0].second, deq[deq.size() - 1].second))ans = 0;
		if (deq.size() == 1)
		{
			if (deq[0].second == 1)
			{
				ans = ans*com(ub - lb, deq[0].first - lb) % mod;
			}
			else
			{
				int l = ub - lb + 1;
				ll t = com(l - deq[0].second, deq[0].first - lb)*p2[deq[0].second - 2] + com(l - deq[0].second, ub - deq[0].first)*p2[deq[0].second - 2];
				t %= mod;
				ans = ans*t%mod;
			}
			break;
		}
		else
		{
			if (deq[0].second > deq[deq.size() - 1].second)
			{
				int l = ub - lb + 1;
				ans *= com(l - deq[0].second, deq[0].first - lb);
				ans %= mod;
				ub -= (l - deq[0].second) - (deq[0].first - lb);
				lb = deq[0].first + 1;
				if (ub < deq[deq.size() - 1].first)ans = 0;
				deq.pop_front();
			}
			else
			{
				int l = ub - lb + 1;
				ans *= com(l - deq[deq.size() - 1].second, ub - deq[deq.size() - 1].first);
				ans %= mod;
				lb += (l - deq[deq.size() - 1].second) - (ub - deq[deq.size() - 1].first);
				ub = deq[deq.size() - 1].first - 1;
				if (lb > deq[0].first)ans = 0;
				deq.pop_back();
			}
		}
		//for (int i = 0; i < deq.size(); i++)printf("%d %d   ", deq[i].first, deq[i].second); printf("   %I64d\n", ans);
	}
	printf("%I64d\n", ans);
}