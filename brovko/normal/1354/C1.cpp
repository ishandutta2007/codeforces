#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;
const ld pi=3.14159265358979;

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
        ld a=(ld)(2*n-2)/(2*n)*pi;
        ld R=1/(2*cos(a/2));
        if(n%2)
            cout << setprecision(20) << 2*R << "\n";
        else cout << setprecision(20) << 2*R*sin(a/2) << "\n";
    }
}