#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

string s;
int m, d[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> m;
    int n = s.size();

    for(int i = 0; i < m; i++)
    {
        int a;
        cin >> a;

        a--;

        d[a]++;
        d[n - a]--;
    }

    int x = 0;

    for(int i = 0; i < n; i++)
    {
        x += d[i];

        if(x % 2 == 0)
            cout << s[i];
        else cout << s[n - 1 - i];
    }
}