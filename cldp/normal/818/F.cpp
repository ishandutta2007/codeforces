#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        long long a, b;
        cin >> a;
        b = a - 1;
        long long L = 1, R = a - 1; 
        while (L + 1 < R) {
            long long mid = (L + R) / 2;
            if (mid * (mid + 1) / 2 <= a - 1 - mid) L = mid; else R = mid;
        }
        if (L > 1) {
            b = max(b, a - 1 - L + L * (L + 1) / 2);
            b = max(b, (a - 1 - L - 1) * 2);
        }
        cout << b << endl;
    }
    return 0;
}