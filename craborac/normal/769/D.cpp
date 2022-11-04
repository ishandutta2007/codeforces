#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n], b[(int)2e4 + 10], c[(int)2e4 + 10];
    fill(b, b + (int)2e4, 0);
    c[0] = 0;
    for (int i = 1; i <= (int)2e4; i++)
        c[i] = c[i / 2] + i % 2;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[a[i]]++;
    }
    long long ans = 0;
    for (int i = 0; i <= (int)1e4; i++)
        if (k == 0)
            ans += (long long)b[i] * (b[i] - 1) / 2;
    for (int i = 0; i < (int)1e4; i++)
        for (int j = i + 1; j <= (int)1e4; j++)
            if (c[i ^ j] == k)
                ans += (long long)b[i] * b[j];
    cout << ans << endl;
    return 0;
}