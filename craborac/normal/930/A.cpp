#include <bits/stdc++.h>

using namespace std;

int a[(int)1e5 + 10];
int h[(int)1e5 + 10];

int main()
{
    srand(3228);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    h[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        x--;
        h[i] = h[x] + 1;
        a[h[i]] ^= 1;
    }
    a[0] ^= 1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}