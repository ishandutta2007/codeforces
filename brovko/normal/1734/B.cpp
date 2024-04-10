#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        for(int i = 1; i <= n; i++, cout << "\n")
            for(int j = 1; j <= i; j++)
                cout << (j == 1 || j == i ? 1 : 0) << ' ';
    }
}