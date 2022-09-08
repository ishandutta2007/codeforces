#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 1001, inf = 111111111;

int k, ans[max_n][max_n];;
vector <int> d;

bool get_bit(int x, int poz) {
    return (bool) (x & (1 << poz));
}

void update(int u, int v) {
    ans[u][v] = 1;
    ans[v][u] = 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> k;
    if (k == 1) {
        cout << 2 << endl << "NY" << endl << "YN" << endl;
        return 0;
    }
    for (int i = 0; i < 32; ++i) {
        if (get_bit(k, i)) {
            d.push_back(i);
        }
    }
    int l = 3, f1 = 1;
    for (int i = d.size() - 1; i >= 0; --i) {
        int x = 1;
        if (i + 1 < d.size()) {
            x = f1;
            for (int j = d[i]; j < d[i + 1]; ++j) {
                update(x, l);
                x = l;
                ++l;
            }
            f1 = x;
        }
        if (d[i] == 0) {
            update(x, 2);
        } else {
            update(x, l);
            update(x, l + 1);
            x = l;
            l += 2;
            for (int j = 1; j < d[i]; ++j) {
                update(x, l);
                update(x, l + 1);
                update(x + 1, l);
                update(x + 1, l + 1);
                x = l;
                l += 2;
            }
            update(x, 2);
            update(x + 1, 2);
        }
    }
    cout << max_n - 1 << endl;
    for (int i = 1; i < max_n; ++i) {
        for (int j = 1; j < max_n; ++j) {
            if (ans[i][j] == 1) {
                cout << 'Y';
                //cout << i << ' ' << j << endl;
            } else {
                cout << 'N';
            }
        }
        cout << endl;
    }
    return 0;
}