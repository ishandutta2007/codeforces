#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 998244353;

int add(int a, int b)
{
    a += b;
    if (a >= M)
    {
        return a - M;
    }
    if (a < 0)
    {
        return a + M;
    }
    return a;
}

int mul(int a, int b)
{
    return a * (ll) b % M;
}

int pw(int a, int b)
{
    int r = 1;
    while (b)
    {
        if (b & 1)
        {
            r = mul(r, a);
        }
        a = mul(a, a);
        b /= 2;
    }
    return r;
}

int dv(int a, int b)
{
    return mul(a, pw(b, M - 2));
}

const int N = (int) 1e6;
int f[N];
int sol;
multiset<int> s;

int c(int n, int k)
{
    return dv(f[n], mul(f[k], f[n - k]));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    f[0] = 1;
    for (int i = 1; i < N; i++)
    {
        f[i] = mul(f[i - 1], i);
    }
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        s.insert(v[i].second);
        while (!s.empty() && *s.begin() < v[i].first)
        {
            s.erase(s.begin());
        }
        int cnt = (int) s.size();
        if (cnt >= k)
        {
            sol = add(sol, c(cnt - 1, k - 1));
        }
    }
    cout << sol << "\n";
}