#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[1005][1005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    int k = 0;

    for(int i = 0; i < n; i++)
        k ^= a[i][i];

    int q;
    cin >> q;

    while(q--)
    {
        int t;
        cin >> t;

        if(t == 3)
            cout << k;
        else
        {
            int x;
            cin >> x;

            k ^= 1;
        }
    }
}