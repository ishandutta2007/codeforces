#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, mn = (int) 1e9;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        mn = min(mn, r - l + 1);
    }

    cout << mn << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << i % mn << " ";
    }
    cout << "\n";

}