#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int n;
int l[512], c[512];

unsigned t[312];

long long dp[1 << 14];

long long getDP(int ma)
{
    if (ma == 0)
        return 0;
    if (dp[ma] != -1)
    {
        return dp[ma];
    }
    long long bsol = (1LL << 60);
    for (int i = 0; i < n; ++i)
    {
        if (((unsigned) ma & t[i]) != (unsigned) ma)
        {
            bsol = min(bsol, getDP(ma & (t[i])) + c[i]);
        }
    }
    return (dp[ma] = bsol);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &l[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &c[i]);
	}

    long long bsol = (1LL << 60);
	for (int i = 0; i < n; i++)
	{
		vector<int> d;
		int j = 2;
		int x = l[i];
		while (j * j <= x)
		{
			if (x % j == 0)
			{
				d.push_back(j);
				while (x % j == 0)
				{
					x /= j;
				}
			}
			++j;
		}
        if (x > 1)
        {
            d.push_back(x);
        }
        memset(t, -1, sizeof(t));
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < (int) d.size(); ++k)
            {
                if (l[j] % d[k] != 0)
                {
                    t[j] -= (1 << k);
                }
            }
        }

        memset(dp, -1, sizeof(dp));
        
        bsol = std::min(bsol, c[i] + getDP((1 << d.size()) - 1));
	}

    if (bsol < (1LL << 60))
        printf("%lld\n", bsol);
    else
        printf("-1\n");
	

	return 0;
}