#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

        int t;
        cin >> t;
        while (t--)
        {
                ll n;
                cin >> n;
                ll sum = n * (n + 1) / 2;
                ll last = (1LL << ((int) log2(n)));
                cout << sum - 2 * (2 * last - 1) << "\n";
        }

        return 0;
}