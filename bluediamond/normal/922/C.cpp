#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        ll n, k;
        cin >> n >> k;

        set <ll> s;
        for (ll i = 1; i <= k; i++)
        {
                ll x = n % i;
                if (s.find(x) != s.end())
                {
                        cout << "NO\n";
                        return 0;
                }
                s.insert(x);
        }

        cout << "YES\n";

	return 0;
}