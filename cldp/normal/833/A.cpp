#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int j = 0; j < N; ++j) {
        int a, b;
        cin >> a >> b;
        long long K = 1LL * a * b;
        long long L = 1, R = 1000001;
        while (L + 1 < R) {
            long long mid = (L + R) / 2;
            if (mid * mid * mid > K) R = mid; else L = mid;
        }
        if (L * L * L != K || a % L != 0 || b % L != 0) {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;

    }
    return 0;
}