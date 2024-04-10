#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a, b;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    while(n--)
    {
        cin >> a >> b;
        int c = a * b;

        int L = 0;
        int R = 2e6;

        while(R - L > 1)
        {
            int M = (L + R) / 2;
            if(M * M * M > c)
                R = M;
            else L = M;
        }

        if(L * L * L == c && a % L == 0 && b % L == 0)
            cout << "Yes\n";
        else cout << "No\n";
    }
}