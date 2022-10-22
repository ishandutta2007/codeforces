#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        int n, m;
        cin >> n >> m;

        if(n == 1 && m == 1)
            cout << "0\n";
        else
        if(n == 1 || m == 1)
            cout << "1\n";
        else cout << "2\n";
    }
}