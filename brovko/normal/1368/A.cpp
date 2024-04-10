#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, a, b, n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> a >> b >> n;

        if(a > b)
            swap(a, b);

        int k = 0;
        while(b <= n)
        {
            a += b;
            swap(a, b);
            k++;
        }

        cout << k << "\n";
    }
}