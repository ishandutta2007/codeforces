#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second

using namespace std;

int t, n, a, b;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> a >> b >> s;

        int k = 1;

        for(int i = 1; i < n; i++)
        {
            if(s[i] != s[i - 1])
                k++;
        }

        cout << a * n + max(b * n, b * (k / 2 + 1)) << "\n";
    }
}