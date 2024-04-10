#include <bits/stdc++.h>

using namespace std;

long long k;

int solve(long long k) {
    long long cnt = 9, st = 1;
    for (int len = 1; ; ++len) {
        if (cnt * len >= k) {
            --k;
            long long num = st + k / len;
            stringstream s;
            s << num;
            return s.str()[k % len] - '0';
        } else {
            k -= cnt * len;
        }
        st *= 10;
        cnt *= 10;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> k;
    cout << solve(k) << endl;
    return 0;
}