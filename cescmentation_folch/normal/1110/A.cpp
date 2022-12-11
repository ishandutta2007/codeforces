#include<bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int b, k;
    cin >> b >> k;

    bool even = true;
    if (b%2) {
        for (int i = 0; i < k; ++i) {
            int x;
            cin >> x;
            if (x%2) {
                even = (!even);
            }
        }
    }
    else {
        for (int i = 0; i < k-1; ++i) {
            int x; cin >> x;
        }
        int x;
        cin >> x;
        if (x%2) even = false;
    }

    if (even) cout << "even\n";
    else cout << "odd\n";
}