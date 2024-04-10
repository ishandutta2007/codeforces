#include <cstdio>
#include <cstring>
#include <queue>
static const int MAXN = 1024;
template <typename T>
inline void upd_min(T &var, const T val) { if (var > val) var = val; }

static const short UP = 1 << 0;
static const short RIGHT = 1 << 1;
static const short DOWN = 1 << 2;
static const short LEFT = 1 << 3;
static const int move[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
short char_map[128] = { 0 };
inline short door_rot(const short x, const int times) {
    switch (times) {
        case 1: return ((x << 1) | ((x >> 3) & 1)) & 15;
        case 2: return ((x << 2) | ((x >> 2) & 3)) & 15;
        case 3: return ((x << 3) | ((x >> 1) & 7)) & 15;
        default: return x;
    }
}
struct dp_state {
    short row, col, rot;
    dp_state() : row(-1), col(-1), rot(-1) { }
    dp_state(int row, int col, int rot)
        : row(row), col(col), rot(rot) { }
};

int n, m;
int xt, yt, xm, ym;
short a[MAXN][MAXN];
int f[MAXN][MAXN][4];

void init_char_map(void);
int main()
{
    init_char_map();

    scanf("%d%d", &n, &m); getchar();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= m; ++j) a[i][j] = char_map[getchar()];
    scanf("%d%d%d%d", &xt, &yt, &xm, &ym);
    --xt; --yt; --xm; --ym;

    memset(f, -1, sizeof f);
    f[xt][yt][0] = 0;
    std::queue<dp_state> q;
    q.push(dp_state(xt, yt, 0));
    while (!q.empty()) {
        dp_state r = q.front(); q.pop();
        for (int dir = 0; dir < 4; ++dir) if (door_rot(a[r.row][r.col], r.rot) & (1 << dir)) {
            int rr = r.row + move[dir][0],
                cc = r.col + move[dir][1];
            if (rr >= 0 && rr < n && cc >= 0 && cc < m
                && (door_rot(a[rr][cc], r.rot) & (1 << ((dir + 2) % 4))))
            {
                if (f[rr][cc][r.rot] == -1) {
                    f[rr][cc][r.rot] = f[r.row][r.col][r.rot] + 1;
                    q.push(dp_state(rr, cc, r.rot));
                } else {
                    upd_min(f[rr][cc][r.rot], f[r.row][r.col][r.rot] + 1);
                }
            }
        }
        if (f[r.row][r.col][(r.rot + 1) % 4] == -1) {
            f[r.row][r.col][(r.rot + 1) % 4] = f[r.row][r.col][r.rot] + 1;
            q.push(dp_state(r.row, r.col, (r.rot + 1) % 4));
        } else {
            upd_min(f[r.row][r.col][(r.rot + 1) % 4], f[r.row][r.col][r.rot] + 1);
        }
    }

    int ans = 0x7fffffff;
    for (int i = 0; i < 4; ++i) upd_min(ans, f[xm][ym][i]);
    printf("%d\n", ans);
    return 0;
}

void init_char_map()
{
    char_map['+'] = UP | DOWN | LEFT | RIGHT;
    char_map['-'] = LEFT | RIGHT;
    char_map['|'] = UP | DOWN;
    char_map['^'] = UP;
    char_map['>'] = RIGHT;
    char_map['<'] = LEFT;
    char_map['v'] = DOWN;
    char_map['L'] = UP | DOWN | RIGHT;
    char_map['R'] = UP | DOWN | LEFT;
    char_map['U'] = LEFT | RIGHT | DOWN;
    char_map['D'] = LEFT | RIGHT | UP;
    char_map['*'] = 0;
}