#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll calc(ll x)
{
        ll ans = 0;
        for(ll i = 1; i * i <= x; i++)
                if(x % i == 0)
                        ans = i;
        return ans;
}

bool ok(ll a, ll b, ll c, ll d)
{
        ll sum = a + b + c + d + 4;
        ll mx = (ll)1e5;
        return (sum <= mx);
}

string s;

string get(ll a, ll b, ll c, ll d)
{
        string s;
        for (ll i = 1; i <= a; i++)
                s += "1";
        s += "33";
        for (ll i = 1; i <= b; i++)
                s += "7";
        for (ll i = 1; i <= c; i++)
                s += "1";
        s += "33";
        for (ll i = 1; i <= d; i++)
                s += "7";
        return s;
}

string solve(ll n)
{
        ll c = 1;
        ll d = 0;
        while (1)
        {
                ll lft = n - c * d;
                if(lft < 0)
                        break;
                ll sum = calc(lft);
                ll b = sum - 6 * d;
                if (b < 0)
                {
                        if (c < d)
                                c++;
                        else
                                d++;
                        continue;
                }
                ll a = lft / sum;
                if (ok(a, b, c, d))
                {
                        ll f = a * (b + d) + c * d;
                        return get(a, b, c, d);
                }
                else if (c < d)
                        c++;
                else
                        d++;
        }
        return "";
}


int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        ll t;
        cin >> t;
        while(t--)
        {
                ll n;
                cin >> n;
                string s = solve(n);
                cout << s << "\n";
        }


        return 0;
}