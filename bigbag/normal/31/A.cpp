#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 111111111;

int n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (i != j && i != k && j != k) {
                    if (a[i] == a[j] + a[k]) {
                        cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "-1" << endl;
    return 0;
}