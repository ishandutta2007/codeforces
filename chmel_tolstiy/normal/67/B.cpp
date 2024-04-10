#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;


const int nn = 1<<10;
int n, k;
int b[nn];
int c[nn];

void push(int v, int p) {
    for (int i = n; i >= p; i--) c[i+1] = c[i];
    c[p] = v;
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = n; i > 0; i--) {
        int p = 0;
        while (b[i]) {
            if (c[p] >= i + k) b[i]--;
            p++;
        }
        push(i, p);
    }
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << c[i];
    }
    cout << endl;
}

int main() {
    solve();
    return 0;
}