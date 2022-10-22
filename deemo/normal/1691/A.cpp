#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te; cin >> te;
    while (te--) {
        int n; cin >> n;
        int c[2] = {0};
        while (n--){
            int x; cin >> x;
            c[x&1]++;
        }
        cout << min(c[0], c[1]) << "\n";
    }
    return 0;
}