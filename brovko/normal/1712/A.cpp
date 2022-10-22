#include <bits/stdc++.h>

using namespace std;


main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, k;
        cin >> n >> k;

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int ans = 0;

        for(int i = 0; i < k; i++)
            ans += (a[i] > k);

        cout << ans << "\n";
    }
}