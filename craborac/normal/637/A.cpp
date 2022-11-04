#include <bits/stdc++.h>

using namespace std;

int a[(int)1e6 + 10];

int main()
{
    int ans = 0;
    for (int i = 0; i <= (int)1e6; i++)
        a[i] = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int q;
        cin >> q;
        a[q]++;
        if (a[q] > a[ans])
            ans = q;
    }
    cout << ans << endl;
    return 0;
}