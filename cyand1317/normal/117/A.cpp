#include <cstdio>

int n, m, s, f, t;

inline int next_pass(int time, int floor, bool is_up)
{
    int full_cyc = m * 2 - 2, half_cyc = m - 1;
    int rq_offset = (is_up ? floor - 1 : half_cyc + m - floor);
    int tm_offset = time % full_cyc;
    return time + (rq_offset - tm_offset + full_cyc) % full_cyc;
}

inline int calc(int s, int f, int t)
{
    if (s == f) return t;
    bool up = (f > s);
    int board = next_pass(t, s, up);
    int reach = next_pass(board, f, up);
    return reach;
}

int main()
{
    scanf("%d%d", &n, &m);
    do {
        scanf("%d%d%d", &s, &f, &t);
        printf("%d\n", calc(s, f, t));
    } while (--n);
    return 0;
}