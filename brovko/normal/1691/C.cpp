#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second

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
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int Min = 1e9, Max = -1e9, c = 0;

        for(int i = 0; i < n; i++)
            if(s[i] == '1')
            {
                c++;

                Min = min(Min, i);
                Max = max(Max, i);
            }

        if(c == 0)
            cout << "0\n";

        else if(c > 1 && k >= n - 1 - Max + Min)
            cout << c * 11 - 11 << "\n";

        else if(k >= n - 1 - Max)
            cout << c * 11 - 10 << "\n";

        else if(k >= Min)
            cout << c * 11 - 1 << "\n";

        else cout << c * 11 << "\n";
    }
}