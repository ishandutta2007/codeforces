#include <bits/stdc++.h>
//#define int long long
#define pb push_back

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

    int n, m;
    cin >> n >> m;

    vector <int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i], a[i]--;

    string s;

    for(int i = 0; i < m; i++)
        s += 'B';

    for(int i = 0; i < n; i++)
    {
        a[i] = min(a[i], m - 1 - a[i]);

        if(s[a[i]] == 'A')
            s[m - 1 - a[i]] = 'A';
        else s[a[i]] = 'A';
    }

    cout << s << "\n";

    }
}