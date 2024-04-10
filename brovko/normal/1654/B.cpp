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

        vector <int> last(26, 1e9);
        int n = s.size();

        for(int i = 0; i < n; i++)
        {
            last[s[i] - 'a'] = i;
        }

        int Min = 1e9;

        for(int i = 0; i < 26; i++)
            Min = min(Min, last[i]);

        for(int i = Min; i < n; i++)
            cout << s[i];

        cout << "\n";
    }
}