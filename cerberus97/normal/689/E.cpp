#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

const int mod = 1e9 + 7;
pair <int, bool> p[400005];
long long fact[200005], invFact[200005];

long long fastModExp(long long x, int e)
{
    long long ans = 1;

    while (e != 0)
    {
        if (e % 2 == 1)
            ans = (ans * x) % mod;

        x = (x * x) % mod;
        e /= 2;
    }

    return ans;
}

void pre()
{
    fact[0] = 1;
    invFact[0] = 1;

    for (int i = 1; i <= 200000; ++i)
    {
        fact[i] = (i * fact[i - 1]) % mod;
        invFact[i] = fastModExp(fact[i], mod - 2);
    }
}

long long nck(int n, int k)
{
    return (((fact[n] * invFact[k]) % mod) * invFact[n-k]) % mod;
}

long long getAns(int l, int r, int cur, int k)
{
    if (cur < k or l > r)
        return 0;

    return ((r - l + 1) * nck(cur - 1, k - 1)) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    pre();

    int n, k, l, r;
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        cin >> l >> r;

        p[i] = make_pair(l, 0);
        p[i+n] = make_pair(r, 1);
    }

    sort(p, p + 2*n);
    stack <int> s;

    long long ans = 0, prev = p[0].first, cur = 1;
    s.push(prev);

    for (int i = 1; i < 2*n; ++i)
    {
        if (!p[i].second)
        {
            ++cur;
            s.push(p[i].first);
        }

        else
        {
            prev = s.top();
            s.pop();

            ans = (ans + getAns(prev, p[i].first, cur, k)) % mod;

            --cur;
        }
    }

    cout << ans;

    return 0;
}