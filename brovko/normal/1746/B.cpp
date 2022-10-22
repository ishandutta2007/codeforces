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

        vector <int> s(n);

        for(int i = 0; i < n; i++)
            cin >> s[i];

        int L = 0, R = n - 1;
        int ans = 0;

        while(L < R)
        {
            while(L < n && s[L] == 0)
                L++;

            while(R >= 0 && s[R] == 1)
                R--;

            if(L >= R)
                break;

            ans++;

            L++, R--;
        }

        cout << ans << "\n";
    }
}