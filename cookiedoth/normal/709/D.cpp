#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const long long mf = 100000, mx = 100000;
const string im = "Impossible";
long long a00, a01, a10, a11, a = -1, b = -1, i, c, m[mx], k;

void pl(bool bb) {
    if (bb) cout << 1;
    else cout << 0;
}

int main()
{
    cin >> a00 >> a01 >> a10 >> a11;
    if ((a00 == 0)&&(a01 == 0)&&(a10 == 0)&&(a11 == 0)) {
        cout << "0";
        return 0;
    }
    if ((a00 == 0)&&(a11 == 0)) {
        if ((a01 > 0)&&(a10 > 0)) {
            cout << im;
            return 0;
        }
        if ((a01 > 1)||(a10 > 1)) {
            cout << im;
            return 0;
        }
        if (a01 > 0) cout << "01";
        if (a10 > 0) cout << "10";
        return 0;
    }
    for (i = 0; i<=mf; i++) {
        if ((i*(i-1)/2) == a00) a = i;
        if ((i*(i-1)/2) == a11) b = i;
        if ((a>-1)&&(b>-1)) break;
    }
    if ((a == -1)||(b == -1)) {
        cout << im;
        return 0;
    }
    if ((a00 == 0)&&(a01 == 0)&&(a10 == 0)) {
        for (i = 0; i<b; i++) pl(1);
        return 0;
    }
    if ((a11 == 0)&&(a01 == 0)&&(a10 == 0)) {
        for (i = 0; i<a; i++) pl(0);
        return 0;
    }
    c = (a+b)*(a+b-1)/2;
    if ((a00 + a01 + a10 + a11) != c) {
        cout << im;
        return 0;
    }
    if ((a01>a*b)||(a10>a*b)) {
        cout << im;
        return 0;
    }
    for (i = 0; i<mx; i++) {
        m[i] = 0;
    }
    k = 0;
    if (a>0) {
        while (a01 >= a) {
            m[k] = a;
            k++;
            a01 -= a;
        }
    }
    m[k] = a01;
    sort(m, m+b);
    k = 0;
    for (i = 0; i<b; i++) {
        while (k < m[i]) {
            k++;
            pl(0);
        }
        pl(1);
    }
    for (i = k; i < a; i++) {
        pl(0);
    }
    return 0;
}