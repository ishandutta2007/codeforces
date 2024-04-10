#include <iostream>
using namespace std;

const int N_MAX = 100;
int t, n, a[N_MAX];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        int s = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
            mx = max(mx, a[i]);
        }
        cout << (s%2 == 0 && 2*mx <= s ? "HL" : "T") << "\n";
    }
    return 0;
}