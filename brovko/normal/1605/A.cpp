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
        int a, b, c;
        cin >> a >> b >> c;

        if((a + b + c) % 3 == 0)
            cout << 0;
        else cout << 1;

        cout << "\n";
    }
}