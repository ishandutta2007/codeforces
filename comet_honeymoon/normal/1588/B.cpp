#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
int n;

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        ll X;
        cout << "? " << 1 << ' ' << n << endl;
        cin >> X;
        int L = 1, R = n;
        while (L != R) {
            ll tX;
            int mid = (L + R) >> 1;
            cout << "? " << 1 << ' ' << mid << endl;
            cin >> tX;
            if (X != tX) L = mid + 1;
            else R = mid;
        }
        ll tX1, tX2;
        cout << "? " << 1 << ' ' << L << endl;
        cin >> tX1;
        cout << "? " << 1 << ' ' << L - 1 << endl;
        cin >> tX2;
        int L2 = L - (tX1 - tX2);
        cout << "? " << 1 << ' ' << L2 - 1 << endl;
        cin >> tX1;
        cout << "? " << 1 << ' ' << L2 - 2 << endl;
        cin >> tX2;
        int L3 = L2 - (tX1 - tX2) - 1;
        cout << "! " << L3 << ' ' << L2 << ' ' << L << endl;
    }
}