#include <bits/stdc++.h>
 
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define maxN 100005
 
using namespace std;
 
long long t, n, q, x, type, tmp, odd, even, ans;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> t;
    while (t--) {
        cin >> n >> q;
        ans = 0;
        odd = 0;
        even = 0;
        fto(i, 1, n) {
            cin >> tmp;
            if (tmp % 2 == 0) ++even;
            else ++odd;
            ans += tmp;
        }
        fto(i, 1, q) {
            cin >> type >> x;
            if (type == 0) {
                ans += even*x;
                if (x % 2 != 0) {
                    odd += even;
                    even = 0;
                }
            }
            else {
                ans += odd*x;
                if (x % 2 != 0) {
                    even += odd;
                    odd = 0;
                }
            }
            cout << ans << "\n";
        }
    }
 
    return 0;
}