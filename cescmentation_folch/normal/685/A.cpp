#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a = n, b = m;
    --n;
    --m;
    int kn = 0;
    while (n > 0) {
        n /= 7;
        ++kn;
    }
    kn = max(kn, 1);
    int km = 0;
    while (m > 0) {
        m /= 7;
        ++km;
    }
    km = max(km, 1);
    if (kn + km > 7) {
        cout << 0 << endl;
        return 0;
    }
    int res = 0;
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            int k[7] = {0,0,0,0,0,0,0};
            int s = 1;
            int aa = i;
            int ttt = kn;
            while (ttt--) {
                int tt = aa%7;
                if (k[tt]) s = 0;
                else k[tt] = 1;
                aa /= 7;
            }
            ttt = km;
            aa = j;
            while (ttt--) {
                int tt = aa%7;
                if (k[tt]) s = 0;
                else k[tt] = 1;
                aa /= 7;
            }
            res += s;
        }
    }
    cout << res << endl;
}