#include <bits/stdc++.h>
//#define int long long
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
        int n;
        cin >> n;

        string s;
        cin >> s;

        int k;
        cin >> k;

        vector <char> a(k);

        for(int i = 0; i < k; i++)
            cin >> a[i];

        vector <int> used(128);

        for(int i = 0; i < k; i++)
            used[a[i]] = 1;

        int ans = 0, t = 0;

        for(int i = 0; i < n; i++)
        {
//            cout << s[i] << ' ' << used[s[i]] << ' ' << t << endl;

            if(used[s[i]])
            {
                ans = max(ans, t);
                t = 1;
            }
            else t++;
        }

        cout << ans << "\n";
    }
}