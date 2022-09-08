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

const int max_n = 222222, inf = 1111111111;

int n, k, x, y, a[max_n];

void write(int x) {
    if (x == 1) {
        cout << "Stannis" << endl;
    } else {
        cout << "Daenerys" << endl;
    }
    exit(0);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] % 2 == 0) {
            ++x;
        } else {
            ++y;
        }
    }
    int o = n - k;
    int c1 = (o + 1) / 2;
    int c2 = o / 2;
    if (c2 >= y) {
        write(2);
    }
    if (k % 2 == 1) {
        if (c1 >= x) {
            write(1);
        }
    } else {
        if (c2 >= x) {
            write(2);
        }
    }
    if (o == 0) {
        if (y % 2 == 1) {
            write(1);
        }
        write(2);
    }
    if (o % 2 == 0) {
        write(2);
    }
    write(1);
    return 0;
}