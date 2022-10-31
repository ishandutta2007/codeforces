#include <iostream>
#include <cstdio>

using namespace std;

int boundxy(int x, int y, int n) {
    return (x >= 0 && y >= 0 && x < n && y < n);
}

int main() {
    int n;
    scanf("%d", &n);
    char grid[n][n];
    for (int i = 0; i < n; ++i) {
        char tmp[110];
        scanf("%s", &tmp);
        for (int j = 0; j < n; ++j) {
            grid[i][j] = tmp[j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {

            int tot = 0;
            if (boundxy(i + 1, j, n)) {
                if (grid[i + 1][j] == 'o')
                    ++tot;
            }
            if (boundxy(i - 1, j, n)) {
                if (grid[i - 1][j] == 'o')
                    ++tot;
            }
            if (boundxy(i, j + 1, n)) {
                if (grid[i][j + 1] == 'o')
                    ++tot;
            }
            if (boundxy(i, j - 1, n)) {
                if (grid[i][j - 1] == 'o')
                    ++tot;
            }

            if (tot % 2 != 0) {
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    return 0;
}