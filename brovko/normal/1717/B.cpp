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
        int n, k, r, c;
        cin >> n >> k >> r >> c;

        r--;
        c--;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                if((i + j) % k == (r + c) % k)
                    cout << "X";
                else cout << ".";

            cout << "\n";
        }
    }
}