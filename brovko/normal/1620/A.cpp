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

        int k = 0;

        for(auto x:s)
            if(x == 'N')
                k++;

        if(k == 1)
            cout << "NO\n";
        else cout << "YES\n";
    }
}