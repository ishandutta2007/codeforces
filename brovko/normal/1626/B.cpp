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

        int F = 0;

        for(int i = n - 2; i >= 0; i--)
            if(F == 0 && (i == 0 || s[i] - '0' + s[i + 1] - '0' >= 10))
            {
                cout << s.substr(0, i);
                cout << s[i] - '0' + s[i + 1] - '0';
                cout << s.substr(i + 2, n - i - 2);

                cout << "\n";
                F = 1;
            }
    }
}