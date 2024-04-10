#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int k = 1;

        int x = n / 2 - 1;

        while(x >= 0 && s[x] == s[n / 2])
        {
            x--;
            k++;
        }

        x = n / 2 + 1;

        while(x < n && s[x] == s[n / 2])
        {
            x++;
            k++;
        }

        cout << k << "\n";
    }
}