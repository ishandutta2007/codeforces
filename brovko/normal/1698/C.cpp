#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
//        int n = rand() % 10 + 3;
        int n;
        cin >> n;

//        cout << n << "\n";

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

//        for(int i = 0; i < n; i++)
//            cout << a[i] << ' ';
//
//        cout << "\n";

        int k = 0;

        for(int i = 0; i < n; i++)
            if(a[i] != 0)
                k++;

        map <int, int> m;
        int ans = (n < 10);

        for(int i = 0; i < n; i++)
            m[a[i]]++;

        if(n < 10)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++)
                for(int k = 0; k < j; k++)
                    if(!m[a[i] + a[j] + a[k]])
                        ans = 0;

        sort(a.begin(), a.end());

        if(n == 3 && (a[0] + a[1] + a[2] == a[0] || a[0] + a[1] + a[2] == a[1] || a[0] + a[1] + a[2] == a[2]) || k <= 1 || k == 2 && a[0] == -a[n - 1] || ans)
        {
            cout << "YES\n";

//            if(ans == 0)
//                return 0;
        }
        else
        {
            cout << "NO\n";

//            if(ans == 1)
//                return 0;
        }
    }
}