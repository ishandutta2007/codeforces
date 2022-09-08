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

const int max_n = 111, inf = 111111111;

int n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int min1 = inf;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int k = 0;
    while (min1 != k) {
        int poz;
        k = min1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    int x = a[i] % a[j];
                    if (x == 0) {
                        x += a[j];
                    }
                    if (min1 > x) {
                        min1 = x;
                        poz = i;
                    }
                }
            }
        }
        a[poz] = min1;
    }
    cout << min1 * n << endl;
    return 0;
}