#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = (int) 1e9 + 7;

int add(int a, int b)
{
    a += b;
    if (a >= MOD)
    {
        return a - MOD;
    }
    if (a < 0)
    {
        return a + MOD;
    }
    return a;
}

int mul(int a, int b)
{
    return a * (ll) b % MOD;
}

const int N = (int) 1e6 + 7;
int p;
int k;
bool u[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> p >> k;
    int ans = 1;
    if (k == 1)
    {
        ans = p;
    }
    for (int i = 1; i < p; i++)
    {
        if (u[i] == 0)
        {
            ans = mul(ans, p);
            int j = i;
            while (u[j] == 0)
            {
                u[j] = 1;
                j = j * (ll) k % p;
            }
        }
    }
    cout << ans << "\n";
}