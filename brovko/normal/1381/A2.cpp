#include <bits/stdc++.h>
#define int long long
#define ld lond double
#define y1 eohfweoifhew

using namespace std;

int t, n, a[100005], b[100005];
char c;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            {
                cin >> c;
                a[i] = c - '0';
            }

        for(int i = 0; i < n; i++)
            {
                cin >> c;
                b[i] = c - '0';
            }

        int x = 0, y = 0;
        vector <int> v;

        for(int i = n - 1; i >= 0; i--)
        {
            if(a[x] ^ y == b[i])
                v.push_back(1);

            v.push_back(i + 1);

            if(y == 0)
                x += i;
            else x -= i;

            y ^= 1;
        }

        cout << v.size() << ' ';

        for(auto to:v)
            cout << to << ' ';

        cout << "\n";
    }
}