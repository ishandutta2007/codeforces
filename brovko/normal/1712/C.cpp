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
            cin >> a[i];

        vector <int> used(n);

        for(int i = 0; i < n; i++)
            a[i]--;

        int x = n - 2;

        while(x >= 0 && a[x] <= a[x + 1])
            x--;

        for(int i = 0; i <= x; i++)
            used[a[i]] = 1;

        vector <int> suf(n);
        int k = 0;

        for(int i = x + 1; i < n; i++)
        {
            suf[a[i]]++;

            if(used[a[i]])
                k++;
        }

//        cout << x << endl;

        while(k)
        {
            x++;

            if(used[a[x]] == 0)
            {
                used[a[x]] = 1;
                k += suf[a[x]];
            }

            k--;

            suf[a[x]]--;
        }

        int ans = 0;

        for(int i = 0; i < n; i++)
            ans += used[i];

        cout << ans << "\n";
    }
}

/*
1
3
3 3 2

*/