#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using namespace std;

int t, n;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> s;

        int x = -1;

        for(int i = 1; i < s.size(); i++)
            if(s[i] != s[i - 1])
            {
                x = i;
            }

        if(x == -1)
            cout << "-1 -1\n";
        else cout << x << ' ' << x + 1 << "\n";
    }
}