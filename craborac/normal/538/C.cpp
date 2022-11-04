#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int d[(int)2e5 + 10], h[(int)2e5 + 10];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> d[i] >> h[i];
    }
    d[0] = 1;
    h[0] = h[1] + d[1] - d[0];
    d[m + 1] = n;
    h[m + 1] = h[m] + d[m + 1] - d[m];
    int ans = -1;
    for (int i = 0; i <= m; i++)
    {
        ans = max(ans, h[i]);
        ans = max(ans, h[i + 1]);
        if (abs(h[i + 1] - h[i]) > d[i + 1] - d[i])
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        int q = abs(h[i + 1] - h[i]);
        ans = max(ans, max(h[i], h[i + 1]) + (d[i + 1] - d[i] - q) / 2);
    }
    cout << ans << endl;
    return 0;
}