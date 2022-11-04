#include <bits/stdc++.h>
#define android ios

using namespace std;

int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

vector<int> v[(int)2e5 + 10];
int used[(int)2e5 + 10];
int dp[(int)2e5 + 10], from[(int)2e5 + 10];
int lol;
long long m;

long long poww(long long a, int b)
{
    long long c = a;
    long long ans = 1;
    for (int i = 0; i < 20; i++)
    {
        if (b & (1 << i))
            ans = (ans * c) % m;
        c = (c * c) % m;
    }
    return ans;
}

int kek(int a, int b)
{
    int t = gcd(m, b);
    a /= t;
    b /= t;
    return (a * poww(b, lol - 1)) % m;
}

int main()
{
    android::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n >> m;
    if (m == 1)
    {
        cout << 1 << endl << 0 << endl;
        return 0;
    }
    fill(used, used + m, 1);
    lol = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        used[a] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        if (gcd(m, i) == 1)
            lol++;
        if (used[i])
        {
            v[gcd(m, i)].push_back(i);
        }
    }
    fill(dp, dp + m, 0);
    fill(from, from + m, -1);
    int t = 1;
    for (int i = 1; i < m; i++)
    {
        dp[i] += v[i].size();
        if (dp[i] > dp[t])
            t = i;
        for (int j = 2; i * j < m; j++)
        {
            if (dp[i] > dp[i * j])
            {
                dp[i * j] = dp[i];
                from[i * j] = i;
            }
        }
    }
    vector<int> a1, a2;
    if (used[0])
        a1.push_back(0);
    while (t >= 0)
    {
        for (int j: v[t])
            a1.push_back(j);
        t = from[t];
    }
    a1.push_back(1);
    for (int i = a1.size() - 2; i >= 0; i--)
    {
        a2.push_back(kek(a1[i], a1[i + 1]));
    }
    cout << a2.size() << endl;
    for (int i: a2)
        cout << i << " ";
    cout << endl;
    return 0;
}