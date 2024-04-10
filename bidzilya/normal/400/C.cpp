#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>
 
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <set>

using namespace std;
 
typedef long long ll;

const int max_p = 1e5 + 100;

int n, m, x, y, z, p;
int xk[max_p], yk[max_p];

void clock_rotate(int& x, int& y) {
    int ny = n - x - 1;
    int nx = y;
    x = nx;
    y = ny;
}

void cnt_clock_rotate(int& x, int& y) {
    int ny = x; 
    int nx = m - y - 1;
    x = nx;
    y = ny;
}

void horiz_reverse(int &x, int &y) {
    y = m - y - 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    while (scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &z, &p) != EOF) {
        for (int i = 0; i < p; ++i) {
            scanf("%d%d", xk + i, yk + i);
            --xk[i];
            --yk[i];
        }
        
        x %= 4;
        y %= 2;
        z %= 4;

        for (int j = 0; j < x; ++j) {
            for (int i = 0; i < p; ++i)
                clock_rotate(xk[i], yk[i]);
            swap(n, m);
        }
        for (int j = 0; j < y; ++j)
            for (int i = 0; i < p; ++i)
                horiz_reverse(xk[i], yk[i]);
        for (int j = 0; j < z; ++j) {
            for (int i = 0; i < p; ++i)
                cnt_clock_rotate(xk[i], yk[i]);
            swap(n, m);
        }
        
        for (int i = 0; i < p; ++i) {
            printf("%d %d\n", xk[i] + 1, yk[i] + 1);
        }
    }

    return 0;
}