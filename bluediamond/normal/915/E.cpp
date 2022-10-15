#include <bits/stdc++.h>

using namespace std;

struct seg
{
    int l;
    int r;
};

bool operator < (seg a, seg b)
{
    if (a.l == b.l)
    {
        return a.r < b.r;
    }
    else
    {
        return a.l < b.l;
    }
}

set<seg> s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans, op;
    cin >> ans >> op;
    s.insert({1, ans});
    while (op--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        auto it = s.lower_bound({l, -1});
        if (it != s.begin())
        {
            it--;
            seg val = *it;
            if (val.r >= l)
            {
                s.erase(val), ans -= (val.r - val.l + 1);
                s.insert({val.l, l - 1}), ans += (l - val.l);
                if (val.r > r)
                {
                    s.insert({r + 1, val.r}), ans += (val.r - r);
                }
            }
        }
        while (1)
        {
            auto it = s.lower_bound({l, -1});
            if (it == s.end())
            {
                break;
            }
            seg val = *it;
            if (val.l > r)
            {
                break;
            }
            s.erase(val), ans -= (val.r - val.l + 1);
            if (val.r > r)
            {
                s.insert({r + 1, val.r}), ans += val.r - r;
            }
        }
        it = s.lower_bound({l, -1});
        if (k == 2)
        {
            s.insert({l, r}), ans += r - l + 1;
        }
        cout << ans << "\n";
    }
}