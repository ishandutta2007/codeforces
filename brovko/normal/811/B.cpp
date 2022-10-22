#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, a[10005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    while(m--)
    {
        int l, r, x;
        cin >> l >> r >> x;

        l--;
        r--;
        x--;

        int k = 0;

        for(int i = l; i <= r; i++)
            if(a[i] < a[x])
                k++;

        if(k == x - l)
            cout << "Yes\n";
        else cout << "No\n";
    }
}