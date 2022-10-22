#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int n, q, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int k1 = 0;

    for(int i = 0; i < n; i++)
        k1 += a[i];

    while(q--)
    {
        int t, x;
        cin >> t >> x;

        if(t == 1)
        {
            x--;

            if(a[x] == 0)
                k1++;
            else k1--;

            a[x] = 1 - a[x];
        }
        else
        {
            if(k1 >= x)
                cout << "1\n";
            else cout << "0\n";
        }
    }
}