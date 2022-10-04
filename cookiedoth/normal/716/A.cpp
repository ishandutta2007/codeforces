/************
*           *
*   HELLO   *
*           *
************/

#include <iostream>

using namespace std;

int main()
{
    long long n, c, ans, i, a, last;
    cin >> n >> c;
    last = -2000000000;
    ans = 0;
    for (i = 0; i<n; i++) {
        cin >> a;
        if ((a - last)<=c) ans++;
        else ans = 1;
        last = a;
    }
    cout << ans;
    return 0;
}