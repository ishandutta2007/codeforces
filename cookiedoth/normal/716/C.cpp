/************
*           *
*   HELLO   *
*           *
************/

#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ll n, i, ans;
    cin >> n;
    cout << 2 << endl;
    for (i = 2; i<n+1; i++) {
        cout << i*(i+1)*(i+1)-(i-1) << endl;
    }
    return 0;
}