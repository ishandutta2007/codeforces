#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

int n, w, sum, a[max_n];
int mn = inf, mx = -inf;

int intersect(int l1, int r1, int l2, int r2) {
    if (l1 > l2) {
        swap(l1, l2);
        swap(r1, r2);
    }
    return max(0, min(r1, r2) - l2 + 1);
}

int main() {
    cin >> n >> w;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        mn = min(mn, sum);
        mx = max(mx, sum);
    }
    cout << intersect(-mn, w - mx, 0, w) << endl;
    return 0;
}