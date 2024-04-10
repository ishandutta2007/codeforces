#include <bits/stdc++.h>
using namespace std;

const int maxn = 201010;
int n;
int h[maxn];

bool check(int x) {
    vector<int> cur_h(h, h + n);
    for (int i = n - 1; i >= 2; --i) {
        if (cur_h[i] < x) return false;
        int d = min(h[i], cur_h[i] - x) / 3;
        cur_h[i - 1] += d;
        cur_h[i - 2] += 2 * d;
        // we don't need to fix cur_h[i] since we are not going back
    }
    return cur_h[0] >= x and cur_h[1] >= x;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> h[i];
        int l = 0, r = *max_element(h, h + n);
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        cout << l << '\n';
    }
    
    return 0;
}