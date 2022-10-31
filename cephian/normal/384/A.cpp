#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    char grid[n][n];
    int amt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i + j) % 2 == 0) {
                grid[i][j] = 'C';
                ++amt;
            } else
                grid[i][j] = '.';
        }
    }
    printf("%d\n", amt);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    return 0;
}