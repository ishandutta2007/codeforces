#include <iostream>
#include <cstdio>
#include <stdio.h>

using namespace std;

int main() {
    int r, c;
    scanf("%d %d", &r, &c);
    bool marked[r][c];
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            marked[i][j] = false;
        }
    }

    bool freer[r];
    fill(freer, freer + r, true);
    bool freec[c];
    fill(freec, freec + c, true);

    for (int i = 0; i < r; ++i) {
        char tmp[60];
        scanf("%s", &tmp[0]);
        for (int j = 0; j < c; ++j) {
            if (tmp[j] == 'S') {
                freer[i] = false;
                freec[j] = false;
            }
        }
    }

    for (int i = 0; i < r; ++i) {
        if (freer[i]) {
            for (int j = 0; j < c; ++j) {
                marked[i][j] = true;
            }
        }
    }

    for (int i = 0; i < c; ++i) {
        if (freec[i]) {
            for (int j = 0; j < r; ++j) {
                marked[j][i] = true;
            }
        }
    }

    int sum = 0;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (marked[i][j]) {
                ++sum;
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}