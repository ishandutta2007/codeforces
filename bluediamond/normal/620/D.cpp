#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2000 + 7;
int n;
int m;
ll a[N];
ll b[N];
ll s;

struct sol
{
    ll a;
    vector<pair<int, int>> b;
};

sol oui(sol x, sol y)
{
    if (abs(x.a) < abs(y.a))
    {
        return x;
    }
    else
    {
        return y;
    }
}

struct kek
{
    int i;
    int j;
    ll a;
};

bool operator < (kek x, kek y)
{
    return x.a < y.a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s += a[i];
        a[i] *= 2;
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        s -= b[i];
        b[i] *= 2;
    }
    sol ans;
    ans = {s, {}};
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            sol cur;
            cur.a = s - a[i] + b[j];
            cur.b.push_back({i, j});
            ans = oui(ans, cur);
        }
    }
    vector<kek> x, y;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            x.push_back({i, j, -a[i] - a[j]});
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = i + 1; j <= m; j++)
        {
            y.push_back({i, j, b[i] + b[j]});
        }
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for (auto &it : x)
    {
        int l = 0, r = (int) y.size() - 1, p = (int) y.size();
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (y[mid].a + s + it.a >= 0)
            {
                p = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        for (int j = p - 1; j <= p; j++)
        {
            if (0 <= j && j < (int) y.size())
            {
                sol cur;
                cur.a = s + y[j].a + it.a;
                cur.b.push_back({it.i, y[j].i});
                cur.b.push_back({it.j, y[j].j});
                ans = oui(ans, cur);
            }
        }
    }
    cout << abs(ans.a) << "\n" << (int) ans.b.size() << "\n";
    for (auto &it : ans.b)
    {
        cout << it.first << " " << it.second << "\n";
    }
}