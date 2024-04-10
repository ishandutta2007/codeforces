#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

struct Data
{
    int big;
    int when;
};

bool operator < (Data a, Data b)
{
    return a.when < b.when;
}

const int N = (int) 2e5 + 7;
int n, lim, a, b, total_a, total_b, cur_a, cur_b, sol;
Data v[N];

void upd(int when)
{
    int dur = a * cur_a + b * cur_b;
    if (dur > when)
    {
        return;
    }
    int finit = sol;
    dur = when - dur;
    sol = cur_a + cur_b;
    int t = min(total_a - cur_a, dur / a);
    dur -= a * t;
    sol += t;
    t = min(total_b - cur_b, dur / b);
    sol += t;
    sol = max(sol, finit);
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        total_a = total_b = cur_a = cur_b = sol = 0;
        cin >> n >> lim >> a >> b;
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i].big;
            total_b += v[i].big;
            total_a += 1 - v[i].big;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i].when;
        }
        sort(v + 1, v + n + 1);
        upd(v[1].when - 1);
        for (int i = 1; i < n; i++)
        {
            cur_b += v[i].big;
            cur_a += 1 - v[i].big;
            upd(v[i + 1].when - 1);
        }
        cur_a = total_a;
        cur_b = total_b;
        upd(lim);
        cout << sol << "\n";
    }

}