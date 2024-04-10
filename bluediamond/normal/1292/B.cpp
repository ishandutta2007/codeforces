#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<pair<ll, ll>> p;
ll ax;
ll ay;
ll bx;
ll by;

const ll INF = (ll) 1e18;

ll add(ll a, ll b)
{
    if (a == INF || b == INF)
    {
        return INF;
    }
    return min(INF, a + b);
}

ll mul(ll a, ll b)
{
    if (a == 0 || b == 0)
    {
        return 0;
    }
    if (a == INF || b == INF)
    {
        return INF;
    }
    ll p = a * b;
    if (p % a == 0 && p / a == b)
    {
        return min(p, INF);
    }
    else
    {
        return INF;
    }
}

ll dd(ll x3, ll y3, ll x4, ll y4)
{
    ll dx = abs(x3 - x4);
    ll dy = abs(y3 - y4);
    return min(dx + dy, INF);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll x0, y0;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    p.push_back({x0, y0});
    while (x0 < INF && y0 < INF)
    {
        x0 = add(bx, mul(ax, x0));
        y0 = add(by, mul(ay, y0));
        p.push_back({x0, y0});
    }
    ll n = (ll) p.size(), ans = 0;
    ll x, y, t;
    cin >> x >> y >> t;
    for (ll re = 0; re <= 1; re++)
    {
        for (ll l = 0; l < n; l++)
        {
            for (ll r = l; r < n; r++)
            {
                ll cnt = r - l + 1;
                ll dist = 0;
                ll cx = x, cy = y;
                if (re)
                {
                    for (ll i = l; i <= r; i++)
                    {
                        dist += dd(cx, cy, p[i].first, p[i].second);
                        cx = p[i].first;
                        cy = p[i].second;
                    }
                }
                else
                {
                    for (ll i = r; i >= l; i--)
                    {
                        dist += dd(cx, cy, p[i].first, p[i].second);
                        cx = p[i].first;
                        cy = p[i].second;
                    }
                }
                if (dist <= t) ans = max(ans, cnt);
            }
        }
    }
    for (ll re1 = 0; re1 <= 1; re1++) for (ll re2 = 1; re2 <= 1; re2++)
    {
        for (ll l1 = 0; l1 < n; l1++) for (ll r1 = l1; r1 < n; r1++)
        {
            for (ll l2 = r1 + 1; l2 < n; l2++) for (ll r2 = l2; r2 < n; r2++)
            {
                ll cnt = r1 - l1 + 1 + r2 - l2 + 1;
                ll dist = 0;
                ll cx = x, cy = y;
                if (re1)
                {
                    for (ll i = l1; i <= r1; i++)
                    {
                        dist += dd(cx, cy, p[i].first, p[i].second);
                        cx = p[i].first;
                        cy = p[i].second;
                    }
                }
                else
                {
                    for (ll i = r1; i >= l1; i--)
                    {
                        dist += dd(cx, cy, p[i].first, p[i].second);
                        cx = p[i].first;
                        cy = p[i].second;
                    }
                }
                if (re2)
                {
                    for (ll i = l2; i <= r2; i++)
                    {
                        dist += dd(cx, cy, p[i].first, p[i].second);
                        cx = p[i].first;
                        cy = p[i].second;
                    }
                }
                else
                {
                    for (ll i = r2; i >= l2; i--)
                    {
                        dist += dd(cx, cy, p[i].first, p[i].second);
                        cx = p[i].first;
                        cy = p[i].second;
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}