#include <cstdio>

int l[4][4];

int main()
{
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) scanf("%d", &l[i][j]);

    for (int i = 0; i < 4; ++i) if (l[i][3] == 1) {
        for (int j = 0; j < 3; ++j) if (l[i][j] == 1) { puts("YES"); return 0; }
        if (l[(i + 3) % 4][2] == 1 || l[(i + 1) % 4][0] == 1 || l[(i + 2) % 4][1] == 1) { puts("YES"); return 0; }
    }

    puts("NO"); return 0;
}