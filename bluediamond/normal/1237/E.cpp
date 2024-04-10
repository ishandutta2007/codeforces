#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 998244353;

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
int n;
map<vector<int>, int> tab;

int compute(int l, int r, int first)
{
    if (l > r)
    {
        return 1;
    }
    if (l == r)
    {
        if (l % 2 == first)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int pare = r / 2 - (l - 1) / 2;
    int impare = r - l + 1 - pare;
    if (tab.count({l % 2, pare, impare, first}))
    {
        return tab[{l % 2, pare, impare, first}];
    }
    int sol = 0;
    if ((r - l + 1) % 2 == 1)
    {
        int node = (l + r) / 2;
        if (node % 2 == first)
        {
            sol = add(sol, mul(compute(l, node - 1, first ^ 1), compute(node + 1, r, first)));
        }
    }
    else
    {
        for (int node = (l + r) / 2; node <= (l + r) / 2 + 1; node++)
        {
            if (node % 2 == first)
            {
                sol = add(sol, mul(compute(l, node - 1, first ^ 1), compute(node + 1, r, first)));
            }
        }
    }
    tab[{l % 2, pare, impare, first}] = sol;
    return sol;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cout << add(compute(1, n, 0), compute(1, n, 1)) << "\n";
}