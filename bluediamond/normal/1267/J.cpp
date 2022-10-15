#include <bits/stdc++.h>

using namespace std;

int cost(int f, int s)
{
    int full = f / s;
    int rem = f % s;
    if (rem == 0)
    {
        return full;
    }
    int need = s - 1 - rem;
    if (need <= full)
    {
        return full + 1;
    }
    else
    {
        return -1;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> f(n);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            x--;
            f[x]++;
        }
        vector<int> fs;
        for (int i = 0; i < n; i++)
        {
            if (f[i])
            {
                fs.push_back(f[i]);
            }
        }
        f = fs;
        sort(f.begin(), f.end());
        int ans = (1 << 30);
        for (int s = 1; s <= f[0] + 1; s++)
        {
            int cur = 0;
            for (auto &x : f)
            {
                int now = cost(x, s);
                if (now == -1)
                {
                    cur = -1;
                    break;
                }
                cur += now;
            }
            if (cur != -1)
            {
                ans = min(ans, cur);
            }
        }
        cout << ans << "\n";
    }

}