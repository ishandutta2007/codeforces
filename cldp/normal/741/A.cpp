#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000007;
const int MAXN = 210;

int x[MAXN];
int z[MAXN][MAXN];

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

long long lcm(long long a, long long b) {
    long long c = gcd(a, b);
    a /= c;
    b /= c;
    return a * b * c;
}

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= N; ++i) {
        int K = x[i];
        for (int j = 1; j <= 100; ++j) {
            z[i][j] = K;
            K = x[K];
        }
    }
    vector<long long> X;
    for (int i = 1; i <= N; ++i) {
        bool flag = false;
        for (int j = 1; j <= 100; ++j) {
            if (z[z[i][j]][j] == i) {
                X.push_back(j);
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << -1 << endl;
            return 0;
        }
    }
    long long ans = 1;
    for (int i = 0; i < X.size(); ++i) ans = lcm(ans, X[i]);
    cout << ans << endl;
    return 0;
}