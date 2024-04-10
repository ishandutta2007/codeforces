#include <map>
#include <set>
#include <stack>
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

int a[3], b[3];

bool check() {
    return a[0] >= max(a[1], a[2]) && b[0] >= b[1] + b[2];
}

int main() {
    cin >> a[0] >> b[0] >> a[1] >> b[1] >> a[2] >> b[2];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                if (check()) {
                    cout << "YES" << endl;
                    return 0;
                }
                swap(a[2], b[2]);
            }
            swap(a[1], b[1]);
        }
        swap(a[0], b[0]);
    }
    cout << "NO" << endl;
    return 0;
}