#include <bits/stdc++.h>

using namespace std;

int n, d, e, sol;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        cin >> n >> d >> e;
        sol = n;
        e *= 5;
        if (d < e)
                swap(d, e);
        for (int td = 0; td * d <= n; td++)
                sol = min(sol, (n - td * d) % e);
        cout << sol << "\n";
}