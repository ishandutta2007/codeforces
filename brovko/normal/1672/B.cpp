#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

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

        if(s.back() == 'A')
        {
            cout << "NO\n";
            continue;
        }

        int x = 0;
        bool F = true;

        for(int i = 0; i < n; i++)
        {
            x += (s[i] == 'A' ? 1 : -1);
            F &= (x >= 0);
        }

        cout << (F ? "YES\n" : "NO\n");
    }
}