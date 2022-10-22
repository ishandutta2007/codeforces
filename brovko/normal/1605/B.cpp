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
        int n;
        cin >> n;

        string s;
        cin >> s;

        int k = 0, F = 0;

        for(int i = 0; i < n; i++)
        {
            if(i > 0 && s[i] < s[i - 1])
                F = 1;

            if(s[i] == '0')
                k++;
        }

        if(F == 0)
        {
            cout << "0\n";
            continue;
        }

        cout << "1\n";

        vector <int> v;

        for(int i = 0; i < n; i++)
        {
            if(i < k && s[i] == '1' || i >= k && s[i] == '0')
                v.pb(i + 1);
        }

        cout << v.size() << ' ';

        for(auto x:v)
            cout << x << ' ';

        cout << "\n";
    }
}