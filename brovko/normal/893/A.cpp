#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x = 1;
    int y = 2;

    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];

        if(a[i] != x && a[i] != y)
        {
            cout << "NO";
            return 0;
        }

        int X = a[i];
        int Y = 6 - x - y;

        x = X;
        y = Y;
    }

    cout << "YES";
}