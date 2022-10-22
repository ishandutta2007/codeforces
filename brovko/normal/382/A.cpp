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

    string s, t;
    cin >> s >> t;

    int d = 0, F = 1;

    for(auto x:s)
    {
        if(x == '|')
            F = -1;
        else d += F;
    }

    int z = t.size();

    if((z + d) % 2 || z + d < 0 || z - d < 0)
        cout << "Impossible";
    else
    {
        int x = (z - d) / 2;

        for(int i = 0; i < x; i++)
            cout << t[i];

        cout << s;

        for(int i = x; i < z; i++)
            cout << t[i];
    }
}