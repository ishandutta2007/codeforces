#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct company
{
    int x;
    int l;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector <company> v(n);
    for (int i = 0; i < n; i++)
    {
        int l;
        cin >> l;
        int mx = 0;
        for (int i = 0; i < l; i++)
        {
            int x;
            cin >> x;
            mx = max(mx, x);
        }
        v[i] = {mx, l};
    }
    ll ans = 0LL;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, v[i].x);
    }
    for (int i = 0; i < n; i++)
    {
        ll dif = mx - v[i].x;
        ll cnt = v[i].l;
        ans += dif * cnt;
    }
    cout << ans << "\n";

}