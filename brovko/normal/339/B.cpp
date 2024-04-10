#include <bits/stdc++.h>
#define li long long

using namespace std;

main()
{
    int n, m;
    cin >> n >> m;

    vector <int> a(m);

    for(int i = 0; i < m; i++)
        cin >> a[i];

    li ans = 0;
    int x = 1;

    for(int i = 0; i < m; i++)
    {
        ans += (a[i] - x + n) % n;
        x = a[i];
    }

    cout << ans;
}