#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
const ll INF = (ll) 1e18;
int n;
int add;
int rem;
int mov;
int v[N];
ll pre[N];
ll sol = INF;

pair<ll, ll> compute(int point)
{
    int smaller = 0, l = 1, r = n;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (v[m] <= point)
        {
            smaller = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    ll d1 = (ll) point * smaller - pre[smaller];
    ll d2 = pre[n] - pre[smaller] - (ll) point * (n - smaller);
    return {d1, d2};
}

void evaluate(int point) /// it evaluates the following point of interest in logarithmic time
{
    int smaller = 0, l = 1, r = n;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (v[m] <= point)
        {
            smaller = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    ll d1 = (ll) point * smaller - pre[smaller];
    ll d2 = pre[n] - pre[smaller] - (ll) point * (n - smaller);
    sol = min(sol, d1 * add + d2 * rem);
    ll t = min(d1, d2);
    d1 -= t;
    d2 -= t;
    sol = min(sol, t * mov + d1 * add + d2 * rem);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> add >> rem >> mov;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    sort(v + 1, v + n + 1);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        evaluate(v[i]);
    }
    int l = v[1], r = v[n], point = 0;

    while (l <= r)
    {
        int m = (l + r) / 2;
        pair<ll, ll> it = compute(m);
        if (it.first < it.second)
        {
            point = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    for (int d = -1; d <= +1; d++)
    {
        evaluate(point + d);
    }

    cout << sol << "\n";
}