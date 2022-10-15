#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        int n, q;
        cin >> n;

        vector <int> a(n);
        for (int i = 0; i < n; i++)
        {
                cin >> a[i];
        }

        int invs = 0;
        for (int i = 0; i < n; i++)
        {
                for (int j = i + 1; j < n; j++)
                {
                        if (a[i] > a[j])
                        {
                                invs ^= 1;
                        }
                }
        }

        cin >> q;

        while (q--)
        {
                int l, r;
                cin >> l >> r;
                int ln = r - l + 1;
                ll x = ln * (ll) (ln - 1) / 2;
                if ((x & 1))
                {
                        invs ^= 1;
                }
                if (invs == 0)
                {
                        cout << "even\n";
                }
                else
                {
                        cout << "odd\n";
                }
        }

	return 0;
}