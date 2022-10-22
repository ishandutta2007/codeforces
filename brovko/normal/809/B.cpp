#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    int L = 0;
    int R = n;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        cout << 1 << ' ' << M << ' ' << M + 1 << endl;
        string s;
        cin >> s;

        if(s == "TAK")
            R = M;
        else L = M;
    }

    int l = 0;
    int r = R;

    while(r - l > 1)
    {
        int m = (l + r) / 2;

        cout << 1 <<  ' ' << m << ' ' << m + 1 << endl;

        string s;
        cin >> s;

        if(s == "TAK")
            r = m;
        else l = m;
    }

    if(r != R)
    {
        cout << 2 << ' ' << r << ' ' << R;
        return 0;
    }

    l = R + 1;
    r = n + 1;

    while(r - l > 1)
    {
        int m = (l + r + 1) / 2;

        cout << 1 << ' ' << m << ' ' << m - 1 << endl;

        string s;
        cin >> s;

        if(s == "TAK")
            l = m;
        else r = m;
    }

    cout << 2 << ' ' << R << ' ' << l;
}