#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int vals[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &vals[i]);
    }
    int i1 = 0;
    int i2 = 0;
    int max = 1 - 2 * vals[0];

    int i1_tmp = 0;
    int max_tmp = max;
    for (int i = 1; i < n; ++i) {
        int tmp = 1 - 2 * vals[i];
        if (tmp > max_tmp + tmp) {
            max_tmp = tmp;
            i1_tmp = i;
        } else
            max_tmp += tmp;
        if (max_tmp > max) {
            max = max_tmp;
            i1 = i1_tmp;
            i2 = i;
        }
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (i >= i1 && i <= i2) {
            sum += 1 - vals[i];
        } else
            sum += vals[i];
    }
    cout << sum << endl;
    return 0;
}