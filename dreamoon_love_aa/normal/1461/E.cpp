#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
void Yes() {
    puts("Yes");
    exit(0);
}
void No() {
    puts("No");
    exit(0);
}
const int SIZE = 1 << 24;
bitset<SIZE> used;
void solve() {
    long long k, l, r, t, x, y;
    cin >> k >> l >> r >> t >> x >> y;
    if(y <= x) {
        for(int i = 0; i < 10000000; i++){
            if(t > 0) {
                if(k + y <= r) {
                    k += y;
                }
                k -= x;
                t--;
                if(k < l) {
                    No();
                }
            }
        }
        if(k - (__int128_t)t * (x - y) >= l) {
            Yes();
        } else {
            No();
        }
    }
    if(x + y <= r - l) {
        Yes();
    }
    long long AA = r - y;
    while(t > 0) {
        if(k + y <= r) {
            k += y;
        }
        long long cc = 1;
        if(k >= AA) {
            cc = (k - AA) / x;
        }
        if(k - cc * x > AA || !cc) {
            cc++;
        }
        if(t < cc) {
            if(k - t * x >= l) {
                Yes();
            } else {
                No();
            }
        }
        t -= cc;
        k -= cc * x;
        if(k < l) {
            No();
        }
        if(used[k - l]) {
            Yes();
        }
        if(t <= 0) {
            Yes();
        }
        used[k - l] = 1;
    }

}
int main() {
    solve();
    return 0;
}