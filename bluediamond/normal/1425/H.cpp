/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;

int a, b, c, d;

string ans[] = {"Tidak", "Ya"};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c >> d;
        int sgn = +1;
        if(a & 1)
            sgn *= -1;
        if(b & 1)
            sgn *= -1;
        bool A = true, B = true, C = true, D = true;
        if(sgn == -1)
            C = D = false;
        else
            A = B = false;
        if(a + d == 0)
            A = D = false;
        if(b + c == 0)
            B = C = false;
        cout << ans[A] << " " << ans[B] << " " << ans[C] << " " << ans[D] << "\n";
    }
    return 0;
}