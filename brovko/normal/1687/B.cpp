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

    int n, m;
    cin >> n >> m;

    vector <pair <int, int> > e;

    string s = "";

    for(int i = 0; i < m; i++)
        s += '0';

    for(int i = 0; i < m; i++)
    {
        s[i] = '1';

        cout << "? " << s << endl;

        int w;
        cin >> w;

        s[i] = '0';
        e.pb({w, i});
    }

    sort(e.begin(), e.end());

//    for(auto x:e)
//        cout << x.y << ' ';
//
//    cout << endl;

    int x = 0;
    int ans = 0;

    for(int i = 0; i < m; i++)
    {
        s[e[i].y] = '1';

        cout << "? " << s << endl;

        int y;
        cin >> y;

        if(y - x == e[i].x)
            ans += y - x;

        x = y;
    }

    cout << "! " << ans;
}