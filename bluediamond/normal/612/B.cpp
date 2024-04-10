#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x--;
        b[x] = i;
    }
    ll ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans += abs(b[i] - b[i - 1]);
    }
    cout << ans << "\n";
}