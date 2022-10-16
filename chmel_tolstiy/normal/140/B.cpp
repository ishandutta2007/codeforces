#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int a[512][512];
int b[512];
int c[512];

vector<int> solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) c[b[i]] = i;

    vector<int> res;
    for (int i = 0; i < n; i++) {
        int best = n + 1;

        for (int j = 0; j < n; j++) if (a[i][j] != i + 1) {
            int cb = 1;
            for (int k = 0; k < n; k++) {
                if (b[k] != i + 1 && b[k] < a[i][j]) cb = 0;
                if (b[k] == a[i][j]) break;
            }
            if (cb) {
                best = a[i][j];
                break;
            }
        }

        assert(best != n + 1);
        res.push_back(best);
    }
    return res;
}

int main() {

    vector<int> r = solve();
    
    for (int i = 0; i < r.size(); i++) {
        if (i) cout << ' ';
        cout << r[i];
    }
    cout << endl;

    return 0;
}