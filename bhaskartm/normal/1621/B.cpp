#include <bits/stdc++.h>
 
using namespace std;
 
void solve()
{
    int n;
    cin >> n;
 
    const int A = 1e9 + 1;
    int minL = A, costL = A;
    int maxR = 0, costR = A;
    int maxLen = 0, costLen = A;
    for (int i = 0; i < n; i++)
    {
        int l, r, c;
        cin >> l >> r >> c;
 
        if (l < minL)
            minL = l, costL = A;
        if (l == minL)
            costL = min(costL, c);
 
        if (maxR < r)
            maxR = r, costR = A;
        if (maxR == r)
            costR = min(costR, c);
 
        if (maxLen < r - l + 1)
            maxLen = r - l + 1, costLen = A;
        if (maxLen == r - l + 1)
            costLen = min(costLen, c);
 
        int ans = costL + costR;
        if (maxLen == maxR - minL + 1)
            ans = min(ans, costLen);
        cout << ans << "\n";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}