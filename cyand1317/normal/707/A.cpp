#include <cstdio>

int n, m;

int main()
{
    bool is_bw = true;
    scanf("%d%d", &n, &m); getchar();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            switch (getchar()) {
                case 'B': case 'W': case 'G': break;
                default: is_bw = false; break;
            }
            getchar();
        }
    puts(is_bw ? "#Black&White" : "#Color");
    return 0;
}