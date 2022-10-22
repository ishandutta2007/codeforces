#include <bits/stdc++.h>
//#define int long long
#define ld long double
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
        string s;
        cin >> s;

        int n = s.size();

        int x = 0;

        for(int i = 0; i < n; i++)
            x += s[i] - 'a' + 1;

        int y = 0;

        if(n % 2)
            y = min(s[0], s[n - 1]) - 'a' + 1;

        x -= y;

        cout << (x > y ? "Alice" : "Bob") << ' ' << abs(x - y) << "\n";
    }
}