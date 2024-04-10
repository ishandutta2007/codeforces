#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
long long p;
vector<long long> a;
vector<long long> b;

long long GetSum(const vector<long long>& a) {
    long long result = 0;
    for (long long x : a) {
        result += x;
    }
    return result;
}

bool Check(double t) {
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += max(0.0, a[i] - 1.0 * b[i] / t);
    }
    return sum <= p;
}

void Solve() {
    const long long sa = GetSum(a);

    if (p >= sa) {
        cout << -1 << endl;
        return;
    }

    double bl = 0.0;
    double br = 1e10 + 100.0;
    for (int itr = 0; itr < 100; ++itr) {
        double bm = (bl + br) / 2.0;

        if (Check(bm)) {
            bl = bm;
        } else {
            br = bm;
        }
    }

    cout << fixed << setprecision(15) << bl << endl;
}

bool Read() {
    if (!(cin >> n >> p)) {
        return false;
    }
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}