#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

typedef vector<int> vi;

const int nn = 1e7+3;

int p[nn];

void solve() {
    int a, n;
    cin >> a >> n;
    long long res = 0;
    if (a == 1) res += 1, ++a, --n;
    
    for (int x = a; x < a + n; ++x) {
        int y = 1;
        int z = x;
        while (z > 1) {
            if (p[z] == p[z/p[z]]) {
                y *= p[z] * p[z];
                z /= p[z] * p[z];
            } else {
                z /= p[z];
            }
        }
        res += x / y;
    }
    
    cout << res << endl;
}

int main() {
    p[1] = 1;
    for (int i = 2; i < nn; i++) if (!p[i]) for (int j = i; j < nn; j += i) p[j] = i;
    solve();
    return 0;
}