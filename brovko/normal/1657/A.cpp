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
        int x, y;
        cin >> x >> y;

        int q = x * x + y * y;

        int root = round(sqrt(q));

        if(q == 0)
            cout << "0\n";
        else
        if(root * root == q)
            cout << "1\n";
        else cout << "2\n";
    }
}