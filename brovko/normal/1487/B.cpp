#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        if(n % 2 == 0)
        {
            cout << (k - 1) % n + 1 << "\n";
            continue;
        }

        int pa = n - k % n;
        int pb = ((k - 1) % (n / 2)) * 2 + 1;

        cout << (pa + pb) % n + 1 << "\n";
    }
}