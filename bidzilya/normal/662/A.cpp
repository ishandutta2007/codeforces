#include <vector>
#include <iostream>
#include <string>
using namespace std;

const int MAX_K = 62;

inline int GetBit(long long sum, int num) {
    return (sum >> num) & 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    long long sum = 0;
    vector<long long> c(n);
    for (int i = 0; i < n; ++i) {
        long long a, b;
        cin >> a >> b;

        c[i] = a ^ b;
        sum ^= a;
    }

    int count = 0;
    for (int k = MAX_K - 1; k >= 0; --k) {
        int id = -1;
        for (int i = 0; i < n; ++i) {
            if (GetBit(c[i], k)) {
                id = i;
                break;
            }
        }
        if (id == -1) {
            continue;
        }
        ++count;
        long long val = c[id];
        for (int i = 0; i < n; ++i) {
            if (GetBit(c[i], k)) {
                c[i] ^= val;
            }
        }
        if (GetBit(sum, k)) {
            sum ^= val;
        }
    }

    if (sum != 0) {
        cout << "1/1" << endl;
    } else {
        cout << (1LL << count) - 1 << "/" << (1LL << count) << endl;
    }

    return 0;
}