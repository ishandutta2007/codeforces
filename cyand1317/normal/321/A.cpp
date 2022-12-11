#include <cstdio>
typedef long long int64;
static const int MAXN = 105;

int a, b, n = 0;
char s[MAXN];
int dx[MAXN], dy[MAXN];

inline void move(int &x, int &y, char ch) {
    switch (ch) {
        case 'U': ++y; break;
        case 'D': --y; break;
        case 'L': --x; break;
        case 'R': ++x; break;
    }
}

int main()
{
    scanf("%d%d", &a, &b); getchar();
    n = 0; while ((s[n] = getchar()) != '\n') ++n;

    dx[0] = dy[0] = 0;
    for (int i = 0; i < n; ++i) {
        dx[i + 1] = dx[i]; dy[i + 1] = dy[i];
        move(dx[i + 1], dy[i + 1], s[i]);
    }

    for (int i = 0; i < n; ++i) {
        if ((dx[n] == 0 ? (a - dx[i] == 0) : (a - dx[i]) % dx[n] == 0)
            && (dy[n] == 0 ? (b - dy[i] == 0) : (b - dy[i]) % dy[n] == 0)
            && (int64)(a - dx[i]) * dx[n] >= 0
            && (int64)(b - dy[i]) * dy[n] >= 0
            && (int64)(a - dx[i]) * dy[n] == (int64)(b - dy[i]) * dx[n])
        {
            puts("Yes"); return 0;
        }
    }
    puts("No");
    return 0;
}