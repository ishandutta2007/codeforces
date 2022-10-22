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
        int n;
        cin >> n;

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            a[i] = i + 1;

        for(int i = n - 2; i >= 0; i -= 2)
            swap(a[i], a[i + 1]);

        for(int i = 0; i < n; i++)
            cout << a[i] << ' ';

        cout << "\n";
    }
}