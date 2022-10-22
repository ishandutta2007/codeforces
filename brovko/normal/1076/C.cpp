#include <bits/stdc++.h>
#define int long double
#define ld long double

using namespace std;

int t, d;

int f(int x)
{
    return (d+sqrt(d*d-4*d))/2;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> d;
        if(d<4 && d)
            cout << "N\n";
        else cout << "Y " << setprecision(10) << f(d) << ' ' << d-f(d) << endl;
    }
}