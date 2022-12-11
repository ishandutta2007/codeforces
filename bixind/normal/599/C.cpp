#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int n, i;
    cin >> n;
    vector<int> h(n), srt(n), mn(n);
    for (i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    srt = h;
    sort(srt.begin(), srt.end());
    mn[n - 1] = h[n - 1];
    for (i = n - 2; i >= 0; i--)
    {
        mn[i] = min(h[i], mn[i + 1]);
    }
    int ans = 1, mx = -1;
    for (i = 0; i < n - 1; i++)
    {
        mx = max(mx, h[i]);
        if (mn[i + 1] >= mx)
            ans++;
    }
    cout << ans;
    return 0;
}