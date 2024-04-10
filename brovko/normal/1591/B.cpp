#include <bits/stdc++.h>

using namespace std;

int n, a[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int Max = a[n - 1], ans = 0;

        for(int i = n - 1; i >= 0; i--)
            if(a[i] > Max)
            {
                Max = a[i];
                ans++;
            }

        cout << ans << "\n";
    }
}