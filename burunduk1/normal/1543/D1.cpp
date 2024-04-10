#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

// E = 1 + p1*E1 + p2*E2 + p3*E3

int main() {
    int t;
    cin >> t;
    while (t--) {
        // (x ^ last) xor z = y
        // z = y ^ last ^ x
        int n, k, last = 0, res; //  : x ^ last
        cin >> n >> k;
        forn(x, n) {
            cout << (x ^ last) << endl;
            last = x;
            cin >> res;
            if (res)
                break;
        }
    }
}