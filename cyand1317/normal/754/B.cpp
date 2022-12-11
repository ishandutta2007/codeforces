#include <cstdio>
static const int N = 4;

char s[N][N];

inline bool check()
{
    for (int i = 0; i < N; ++i) {
        if (s[i][0] == 'x' && s[i][1] == 'x' && s[i][2] == 'x') return true;
        if (s[0][i] == 'x' && s[1][i] == 'x' && s[2][i] == 'x') return true;
        if (s[i][3] == 'x' && s[i][1] == 'x' && s[i][2] == 'x') return true;
        if (s[3][i] == 'x' && s[1][i] == 'x' && s[2][i] == 'x') return true;
    }
    for (int i = 0; i < N - 2; ++i)
        for (int j = 0; j < N - 2; ++j) {
            if (s[i][j] == 'x' && s[i + 1][j + 1] == 'x' && s[i + 2][j + 2] == 'x') return true;
            if (s[i][N - 1 - j] == 'x' && s[i + 1][N - 2 - j] == 'x' && s[i + 2][N - 3 - j] == 'x') return true;
        }
    return false;
}

int main()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j <= N; ++j) s[i][j] = getchar();

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) if (s[i][j] == '.') {
            s[i][j] = 'x';
            if (check()) { puts("YES"); return 0; }
            s[i][j] = '.';
        }

    puts("NO");
    return 0;
}