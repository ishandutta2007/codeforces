#include <bits/stdc++.h>

using namespace std;

const int N = (int) 3e5 + 7;
int n;
int k;
bool is_prime[N];
int cnt[N];
bool act[N];

int times(int i, int p)
{
    if (i % p == 0)
    {
        return 1 + times(i / p, p);
    }
    else
    {
        return 0;
    }
}

void math_snuff()
{
    is_prime[2] = 1;
    for (int i = 3; i <= n; i += 2)
    {
        is_prime[i] = 1;
    }
    for (int i = 3; i * i <= n; i += 2)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += 2 * i)
            {
                is_prime[j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cnt[i] = 1;
    }
    for (int p = 2; p <= n; p++)
    {
        if (is_prime[p])
        {
            for (int i = p; i <= n; i += p)
            {
                cnt[i] *= (times(i, p) + 1);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cnt[i]--;
    }
}

void print()
{
    vector<int> sol;
    for (int i = 1; i <= n; i++)
    {
        if (act[i])
        {
            sol.push_back(i);
        }
    }
    cout << "Yes\n";
    cout << (int) sol.size() << "\n";
    for (auto &x : sol)
    {
        cout << x << " ";
    }
    cout << "\n";
    exit(0);
}

vector<int> dvs[N];

void brute_force(int i, int cnt)
{
    if (cnt > k)
    {
        cout << "error\n";
        exit(0);
    }
    if (cnt == k)
    {
        print();
    }
    if (i > n)
    {
        return;
    }
    int e = 0;
    for (auto &j : dvs[i])
    {
        if (act[j])
        {
            e++;
        }
    }
    if (cnt + e <= k)
    {
        act[i] = 1;
        brute_force(i + 1, cnt + e);
        act[i] = 0;
    }
    brute_force(i + 1, cnt);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    math_snuff();
    int max_possible = 0;
    for (int i = 1; i <= n; i++)
    {
        max_possible += cnt[i];
    }
    if (k > max_possible)
    {
        cout << "No\n";
        return 0;
    }
    int cur = 0, m = 0;
    for (int i = 1; i <= n; i++)
    {
        cur += cnt[i];
        act[i] = 1;
        m = i;
        if (cur >= k)
        {
            break;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (is_prime[i] && 2 * i > m && cur > k)
        {
            cur--;
            act[i] = 0;
        }
    }
    if (cur == k)
    {
        print();
    }
    else
    {
        n = min(n, 140);
        for (int i = 1; i <= n; i++)
        {
            act[i] = 0;
            for (int j = 2 * i; j <= n; j += i)
            {
                dvs[j].push_back(i);
            }
        }
        brute_force(1, 0);
    }
    return 0;
}