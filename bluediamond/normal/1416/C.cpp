#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> a;
    a.push_back({});
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.back().push_back(x);
    }
    ll invs = 0;
    int num = 0;
    for (int b = 30; b >= 0; b--)
    {
        ll on = 0, off = 0;
        for (auto &vec : a)
        {
            int ones = 0;
            for (auto &x : vec)
            {
                if (x & (1 << b))
                {
                    ones++;
                }
                else
                {
                    on += ones;
                }
            }
        }
        for (auto &vec : a)
        {
            int ones = 0;
            for (auto &x : vec)
            {
                if (!(x & (1 << b)))
                {
                    ones++;
                }
                else
                {
                    off += ones;
                }
            }
        }
        vector<vector<int>> nw;
        if (off < on)
        {
            invs += off;
            num += (1 << b);
            for (auto &vec : a)
            {
                vector<int> fi, sc;
                for (auto &x : vec)
                {
                    if (x & (1 << b))
                    {
                        fi.push_back(x);
                    }
                    else
                    {
                        sc.push_back(x);
                    }
                }
                if (!fi.empty())
                {
                    nw.push_back(fi);
                }
                if (!sc.empty())
                {
                    nw.push_back(sc);
                }
            }
        }
        else
        {
            invs += on;
            for (auto &vec : a)
            {
                vector<int> fi, sc;
                for (auto &x : vec)
                {
                    if (x & (1 << b))
                    {
                        fi.push_back(x);
                    }
                    else
                    {
                        sc.push_back(x);
                    }
                }
                if (!fi.empty())
                {
                    nw.push_back(fi);
                }
                if (!sc.empty())
                {
                    nw.push_back(sc);
                }
            }
        }
        a = nw;
    }
    cout << invs << " " << num << "\n";
}