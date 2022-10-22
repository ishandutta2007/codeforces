#include <bits/stdc++.h>
//#define int long long
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

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if(a == c || b == d)
        cout << "1 ";
    else cout << "2 ";

    if(a + b == c + d || a - c == b - d)
        cout << "1 ";
    else if((a + b + c + d) % 2 == 0)
        cout << "2 ";
    else cout << "0 ";

    cout << max(abs(a - c), abs(b - d));
}