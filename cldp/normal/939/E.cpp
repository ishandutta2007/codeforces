#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);



int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<long long> x, y;
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        long long b;
        cin >> a;
        if (a == 1) {
            cin >> b;
            x.push_back(b);
            sum += b;
            y.push_back(sum);
            continue;
        }

        int L = 0, R = x.size();
        while (L + 1 < R) {
            int mid = (L + R) / 2;
            if (1.0 * (y[mid] + x.back()) / (mid + 2) >= x[mid]) L = mid; else R = mid;
        }

        cout << fixed << setprecision(8) << x.back() - 1.0 * (y[L] + x.back()) / (L + 2) << endl;
    }
    return 0;
}