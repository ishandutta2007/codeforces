#include <bits/stdc++.h>
//#define int long long
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
        int n;
        cin >> n;

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        if(n % 2)
        {
            cout << "Mike\n";
            continue;
        }

        int m1 = 0, m2 = 1;

        for(int i = 0; i < n; i += 2)
            if(a[i] < a[m1])
                m1 = i;

        for(int i = 1; i < n; i += 2)
            if(a[i] < a[m2])
                m2 = i;

        if(make_pair(a[m1], m1) < make_pair(a[m2], m2))
            cout << "Joe\n";
        else cout << "Mike\n";
    }
}