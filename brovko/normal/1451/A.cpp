#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        if(n <= 3)
            cout << n - 1;

        else if(n % 2 == 0)
            cout << 2;

        else cout << 3;

        cout << "\n";
    }
}