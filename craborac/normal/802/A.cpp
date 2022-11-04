#include <bits/stdc++.h>
#define android ios

using namespace std;

int ne[300], last[300], a[300];

int main()
{
    android::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    set<pair<int, int> > se;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    fill(last, last + 300, n);
    for (int i = n - 1; i >= 0; i--)
    {
        ne[i] = last[a[i]];
        last[a[i]] = i;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (se.count({-i, a[i]}) == 1)
        {
            se.erase({-i, a[i]});
            se.insert({-ne[i], a[i]});
        }
        else
        {
            ans++;
            if (se.size() == k)
                se.erase(se.begin());
            se.insert({-ne[i], a[i]});
        }
    }
    cout << ans << endl;
    return 0;
}