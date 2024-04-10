#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int grid[n][n];
    int x = 0;
    int y = 0;
    for (int i = 0; i < n * n; ++i) {
        grid[x][y] = i + 1;
        if (y % 2 == 0) {
            ++x;
            if (x == n) {
                x = n - 1;
                ++y;
            }
        } else {
            --x;
            if (x == -1) {
                x = 0;
                ++y;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d", grid[i][j]);
            if (j == n - 1)
                printf("\n");
            else
                printf(" ");
        }
    }
}