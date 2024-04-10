#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int QUERY(int n) {
    cout << "? " << n + 1 << endl;
    int ans;
    cin >> ans;
    return ans;
}

void ANSWER(int n) {
    cout << "! " << (n == -1 ? -1 : n + 1) << endl;
    exit(0);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    if (N % 4 == 2) {
        ANSWER(-1);
    }
    int K = N / 4;
    int a = 0;
    int b = 2 * K;
    int c = 2 * K;
    int d = 4 * K;
    int va = QUERY(a % N);
    int vb = QUERY(b % N);
    int vc = QUERY(c % N);
    int vd = QUERY(d % N);
    if (va == vb) {
        ANSWER(a % N);
    }
    while (true) {
        int x = (a + b) / 2;
        int y = (c + d) / 2;
        assert(a < x && x < b && c < y && y < d);
        int vx = QUERY(x);
        int vy = QUERY(y);
        if (vx == vy) {
            ANSWER(x % N);
        } else if (vx < vy) {
            if (vb > vd) {
                tie(a, va) = make_pair(x, vx);
                tie(c, vc) = make_pair(y, vy);
            } else if (va > vc) {
                tie(b, vb) = make_pair(x, vx);
                tie(d, vd) = make_pair(y, vy);
            } else {
                assert(false);
            }
        } else if (vx > vy) {
            if (vb < vd) {
                tie(a, va) = make_pair(x, vx);
                tie(c, vc) = make_pair(y, vy);
            } else if (va < vc) {
                tie(b, vb) = make_pair(x, vx);
                tie(d, vd) = make_pair(y, vy);
            } else {
                assert(false);
            }
        }
    }
    return 0;
}