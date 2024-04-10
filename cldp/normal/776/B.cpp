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
const int MAXN = 100010;

int f[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    memset(f, -1, sizeof(f));
    for (int i = 2; i <= N + 1; ++i) {
        if (f[i] != -1) continue;
        f[i] = 1;
        for (long long j = 1LL * i * i; j <= N + 1; j += i) {
            f[j] = 2;
        }
    }
    if (N < 3) {
        cout << 1 << endl;
        for (int i = 2; i <= N + 1; ++i) cout << f[i] << " ";
        cout << endl;
    } else {
        cout << 2 << endl;
        for (int i = 2; i <= N + 1; ++i) cout << f[i] << " ";
        cout << endl;
    }
    return 0;
}