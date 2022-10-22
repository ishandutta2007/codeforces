#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, a[10005];

int32_t main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            a[i] = -1;

        int x = 0, j = 0;

        for(int i = 0; i < n - 2; i++)
        {
            cout << "? " << i + 1 << ' ' << i + 2 << ' ' << i + 3 << endl;

            int y;
            cin >> y;

            if(i > 0 && x != y)
            {
                a[i - 1] = x;
                a[i + 2] = y;
                j = i;
                break;
            }
            else
            {
                x = y;
            }
        }

        for(int i = 0; i < n; i++)
            if(i != j - 1 && i != j + 2)
            {
                cout << "? " << j << ' ' << j + 3 << ' ' << i + 1 << endl;

                cin >> a[i];
            }

        vector <int> v;

        for(int i = 0; i < n; i++)
            if(a[i] == 0)
                v.push_back(i + 1);

        cout << "! " << v.size() << ' ';

        for(auto x:v)
            cout << x << ' ';

        cout << endl;
    }
}