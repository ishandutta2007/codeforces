#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    const int mx = 200000;
    int n, a, x[mx], i, d1, d2, m1, m2, a1, a2;
    cin >> n >> a;
    for (i = 0; i<n; i++) {
        cin >> x[i];
    }
    if (n == 1) {
        cout << 0;
        return 0;
    }
    sort(x, x+n);
    if (a<=x[0]) {
        cout << x[n-2]-a;
        return 0;
    }
    if (a>=x[n-1]) {
        cout << a-x[1];
        return 0;
    }
    d1 = x[n-2] - x[0];
    d2 = x[n-1] - x[1];
    m1 = abs(a - x[n-2]);
    m2 = abs(a - x[0]);
    a1 = d1 + min(m1, m2);
    m1 = abs(a - x[1]);
    m2 = abs(a - x[n-1]);
    a2 = d2 + min(m1, m2);
    cout << min(a1,a2);
    return 0;
}