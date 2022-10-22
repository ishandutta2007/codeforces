#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int n;

int f(int x)
{
    if(x <= 0 || x > n)
        return 1e18;

    int ans;
    cout << "? " << x << endl;

    cin >> ans;
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int L = 0, R = n + 1;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        if(f(M) > f(M + 1))
            L = M;
        else R = M;
    }

    cout << "! " << R << endl;
}