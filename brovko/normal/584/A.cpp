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

    int n, t;
    cin >> n >> t;

    if(t == 10 && n == 1)
        cout << -1;
    else
    if(t == 10)
    {
        cout << 1;

        for(int i = 0; i < n - 1; i++)
            cout << 0;
    }
    else
    {
        for(int i = 0; i < n; i++)
            cout << t;
    }
}