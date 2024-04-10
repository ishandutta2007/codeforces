#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool Check(long long result, const vector<long long>& a, const vector<long long>& b, long long k) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        if (a[i] * result >= b[i]) {
            k -= (a[i] * result - b[i]);
        }
        if (k < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    long long bl = 0;
    long long br = 2e9;
    long long ba = 0;
    while (bl <= br) {
        long long bm = (bl + br) >> 1;

        if (Check(bm, a, b, k)) {
            ba = bm;
            bl = bm + 1;
        } else {
            br = bm - 1;
        }
    }

    cout << ba << endl;

    return 0;
}