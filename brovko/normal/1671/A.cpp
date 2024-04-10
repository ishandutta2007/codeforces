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

        int F = 1;

        if(n == 1 || s[0] != s[1] || s[n - 1] != s[n - 2])
            F = 0;

        for(int i = 0; i < n - 2; i++)
            if(s.substr(i, 3) == "bab" || s.substr(i, 3) == "aba")
                F = 0;

        cout << (F ? "YES\n" : "NO\n");
    }
}