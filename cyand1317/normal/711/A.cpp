#include <cstdio>
static const int MAXN = 1024;

int n;
int seat[MAXN][2];
const char *seat_str[] = { "XX", "XO", "OX", "OO", "++" };

int main()
{
    scanf("%d", &n); getchar();
    int row = -1, col = -1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 2; ++j) {
            seat[i][j] = (getchar() == 'O') << 1;
            seat[i][j] |= (getchar() == 'O');
            if (seat[i][j] == 3) { row = i; col = j; }
            getchar();
        }

    if (row == -1) puts("NO");
    else {
        puts("YES");
        seat[row][col] = 4;
        for (int i = 0; i < n; ++i) {
            printf("%s|%s\n", seat_str[seat[i][0]], seat_str[seat[i][1]]);
        }
    }

    return 0;
}