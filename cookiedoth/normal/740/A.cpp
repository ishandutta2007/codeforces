/**********
*         *
*  HELLO  *
*         *
**********/

#include <bits/stdc++.h>

using namespace std;

long long n, a, b, c, r;

int main()
{
    cin >> n >> a >> b >> c;
    r = (n % 4);
    if (r == 0) cout << 0;
    if (r == 1) cout << min(a*3, min(a + b, c));
    if (r == 2) cout << min(a*2, min(b, c*2));
    if (r == 3) cout << min(a, min(b + c, 3*c));
    return 0;
}