#include <bits/stdc++.h>

using namespace std;

int solve(int bit, vector<int> a)
{
    if (bit == -1)
    {
        return 0;
    }
    int have = 0, not_have = 0;
    for (auto &x : a)
    {
        if (x & (1 << bit))
        {
            have++;
        }
        else
        {
            not_have++;
        }
    }
    if (have == 0 || not_have == 0)
    {
        return solve(bit - 1, a);
    }
    vector<int> b, c;
    for (auto &x : a)
    {
        if (x & (1 << bit))
        {
            b.push_back(x);
        }
        else
        {
            c.push_back(x);
        }
    }
    return (1 << bit) + min(solve(bit - 1, b), solve(bit - 1, c));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << solve(30, a) << "\n";
}