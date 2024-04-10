#include <bits/stdc++.h>
using namespace std;

inline int GetBit(int mask, int num)
{
    return (mask >> num) & 1;
}

inline int GetAmountOfBits(int mask)
{
    int r = 0;
    while (mask) {
        r += (mask & 1);
        mask >>= 1;
    }
    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int ans = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        if (GetAmountOfBits(mask) < 2) {
            continue;
        }
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (GetBit(mask, i)) {
                sum += a[i];
            }
        }
        int mn = -1;
        int mx = -1;
        for (int i = 0; i < n; ++i) {
            if (GetBit(mask, i)) {
                if (mn == -1 || a[i] < mn) {
                    mn = a[i];
                }
                if (mx == -1 || a[i] > mx) {
                    mx = a[i];
                }
            }
        }
        if (sum >= l && sum <= r && mx - mn >= x) {
            ++ans;
        }
    }
    cout << ans << endl;
    
    return 0;
}