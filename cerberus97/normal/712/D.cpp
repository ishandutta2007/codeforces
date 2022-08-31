#include <iostream>

using namespace std;

const int T = 105, K = 1005, MS = 200005, mod = 1e9 + 7;

long long s[T][MS] = {0}, rSum[MS] = {0};

long long getRSum(int i, int ms)
{
	if (i+ms < 0)
		return 0;

	if (i > ms)
		i = ms;

	return rSum[i+ms];
}

int main()
{
	int a, b, k, t, ms;
	cin >> a >> b >> k >> t;

	ms = k*t;

	for (int i = -k; i <= k; ++i)
		s[1][i+ms] = 1;

	for (int i = 2; i <= t; ++i)
	{
		long long sum = 0;
		int l = -ms-1, r = -ms-1;

		for (int j = -ms; j <= ms; ++j)
		{
			int x = max(j-k, -ms), y = min(j+k, ms);

			while (r < y)
			{
				++r;
				sum = (sum + s[i-1][r+ms]) % mod;
			}

			while (l < x)
			{
				sum -= s[i-1][l+ms];
				++l;

				if (sum < 0)
					sum += mod;
			}

			s[i][j+ms] = sum;
		}
	}

	rSum[0] = s[t][0];

	for (int i = 1; i <= 2*ms; ++i)
		rSum[i] = (rSum[i-1] + s[t][i]) % mod;

	long long ans = 0, offset = a-b-1, temp;

	/*
	for (int j = -ms; j <= ms; ++j)
	{
		for (int i = 1; i <= t; ++i)
		{
			cout << s[i][j+ms] << ' ';
		}

		cout << endl;
	}
	*/
	
	for (int i = -ms; i <= ms; ++i)
	{
		temp = (getRSum(i + offset, ms) * s[t][i+ms]) % mod;
		ans = (ans + temp) % mod;
	}

	cout << ans;
}