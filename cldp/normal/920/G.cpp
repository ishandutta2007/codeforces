#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);

vector<int> X;

void splita(int a) {
    int b = a;
    for (int i = 2; i * i <= a; ++i) {
        if (b % i == 0) {
            while (b % i == 0) b /= i;
            X.push_back(i);
        }
    }
    if (b != 1) X.push_back(b);
}

int cnt(int a) {
    int N = X.size();
    int ans = 0;
    for (int i = 1; i < (1 << N); ++i) {
        int temp = 1;
        for (int j = 0; j < N; ++j) {
            if (i & (1 << j)) temp *= X[j];
        }
        if (__builtin_popcount(i) & 1) ans += a / temp; else ans -= a / temp;
    }
    return a - ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        X.clear();
        splita(b);
        int aa = cnt(a);
        int L = a, R = 1000000000;
        while (L + 1 < R) {
            int mid = (L + R) / 2;
            int bb = cnt(mid);
            if (bb - aa >= c) R = mid; else L = mid;
        }
        cout << R << endl;
    }
    return 0;
}