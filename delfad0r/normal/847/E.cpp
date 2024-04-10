#include <bits/stdc++.h>

using namespace std;

int N;
string S;

int main() {
    cin >> N;
    cin >> S;
    int lo = 0, hi = 2 * N;
    while(lo < hi) {
        int t = (lo + hi) / 2;
        int i = 0;
        bool ok = true;
        for(int n = 0; n < N && ok; ++n) {
            while(i < N && S[i] != '*') {
                ++i;
            }
            if(i >= N) {
                break;
            }
            if(S[n] != 'P') {
                continue;
            }
            if(i >= n) {
                i = max(i, n + t + 1);
                continue;
            }
            if(i + t < n) {
                ok = false;
                continue;
            }
            i = max(0, max(t - 2 * (n - i), (t + i - n) / 2)) + n + 1;
        }
        if(ok && i >= N) {
            hi = t;
        } else {
            lo = t + 1;
        }
    }
    cout << lo << '\n';
}