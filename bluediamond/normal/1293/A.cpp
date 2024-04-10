#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, s, k;
        cin >> n >> s >> k;
        set<int> all;
        for (int i = 1; i <= k; i++)
        {
            int x;
            cin >> x;
            all.insert(x);
        }
        int l = s, r = s, ans = n;
        while (l - 1 >= 1 && all.count(l)) l--;
        while (r + 1 <= n && all.count(r)) r++;
        if (all.count(l) == 0) ans = min(ans, s - l);
        if (all.count(r) == 0) ans = min(ans, r - s);
        cout << ans << "\n";
    }
}