#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector <int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int ans = 1;
    int cur = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i] == v[i - 1])
        {
            cur = 1;
        }
        else
        {
            cur++;
        }
        ans = max(ans, cur);
    }
    cout << ans << "\n";


}