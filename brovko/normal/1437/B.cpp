#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

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

        int x = 0, y = 0;

        for(int i = 1; i < n; i++)
            if(s[i] == '1' && s[i - 1] == '1')
                x++;

        for(int i = 1; i < n; i++)
            if(s[i] == '0' && s[i - 1] == '0')
                y++;

        cout << max(x, y) << "\n";
    }
}