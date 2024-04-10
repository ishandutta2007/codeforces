#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e6 + 7;
int n, k, l, sir[N];
string s;
pair<ll, ll> din[N];

void fadin(ll c)
{
        for (int i = 1; i <= n; i++)
        {
                pair<ll, ll> unu, doi;

                unu = {din[i - 1].first + sir[i], din[i - 1].second};

                int j = max(0, i - l);
                doi = {din[j].first + c, din[j].second + 1};

                din[i] = min(unu, doi);
        }
}

ll proc()
{
        ll l = 0, r = (ll) 1e9, sol;
        while (l <= r)
        {
                ll mid = (l + r) / 2;
                fadin(mid);
                if (din[n].second <= k)
                {
                        sol = din[n].first - mid * k;
                        r = mid - 1;
                }
                else
                        l = mid + 1;
        }
        return sol;
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        cin >> n >> k >> l >> s;
        if (k * (ll) l >= n)
        {
                cout << "0\n";
                return 0;
        }
        for (int i = 1; i <= n; i++)
                if ('a' <= s[i - 1] && s[i - 1] <= 'z')
                        sir[i] = 1;
        ll sol = proc();
        for (int i = 1; i <= n; i++)
                sir[i] ^= 1;
        sol = min(sol, proc());
        cout << sol << "\n";
}