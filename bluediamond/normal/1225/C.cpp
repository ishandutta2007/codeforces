#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n, p, l = 0;

ll bits()
{
        ll aux = n, fff = 0;
        while (aux)
        {
                fff++;
                aux -= aux & (-aux);
        }
        return fff;
}

void nein()
{
        cout << "-1\n";
        exit(0);
}

void ok()
{
        if (n >= l && l >= bits())
        {
                cout << l << "\n";
                exit(0);
        }
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        cin >> n >> p;
        for (ll it = 1; it <= 100; it++)
        {
                ok();
                l++;
                n -= p;
        }
        nein();
}