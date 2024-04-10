#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int QUERY(int i) {
    cout << "? " << i << endl;
    int ans;
    cin >> ans;
    return ans;
}

void ANSWER(int i) {
    cout << "! " << i << endl;
    exit(0);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    if (N == 1) {
        ANSWER(1);
    }
    if (int A = QUERY(1), B = QUERY(2); A < B) {
        ANSWER(1);
    }
    if (int A = QUERY(N), B = QUERY(N - 1); A < B) {
        ANSWER(N);
    }
    int L = 1, R = N;
    while (R - L > 2) {
        int A = (L + R) / 2;
        int B = A + 1;
        if (QUERY(A) < QUERY(B)) {
            R = B;
        } else {
            L = A;
        }
    }
    int i = (L + R) / 2;
    ANSWER(i);
    return 0;
}