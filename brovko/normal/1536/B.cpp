#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    vector <string> a;
    string alf = "abcdefghijklmnopqrstuvwxyz";

    for(int i = 'a'; i <= 'z'; i++)
        a.pb(alf.substr(i - 'a', 1));

    for(int i = 'a'; i <= 'z'; i++)
        for(int j = 'a'; j <= 'z'; j++)
            a.pb(alf.substr(i - 'a', 1) + alf.substr(j - 'a', 1));

    for(int i = 'a'; i <= 'z'; i++)
        for(int j = 'a'; j <= 'z'; j++)
            for(int k = 'a'; k <= 'z'; k++)
                a.pb(alf.substr(i - 'a', 1) + alf.substr(j - 'a', 1) + alf.substr(k - 'a', 1));

    while(t--)
    {
        cin >> n >> s;

        map <string, int> m;

        for(int i = 0; i < n; i++)
            for(int j = i; j < min(n, i + 5); j++)
                m[s.substr(i, j - i + 1)]++;

        int x = 0;

        while(m[a[x]] > 0)
            x++;

        cout << a[x] << "\n";
    }
}