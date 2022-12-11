#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <list>
using std::min;
static const int INF = 0x7fffffff;
static const int MAXN = 100014;
static const int MAXK = 100014;
// Directions: TR=0, BR=1, TL=2, BL=3
static const int mov[4][2] = {{+1, +1}, {+1, -1}, {-1, +1}, {-1, -1}};

int n, m, k;
int x[MAXK], y[MAXK];
long long timestamp[MAXK];
// Diagonal and reversed diagonal
std::list<int> dg[MAXN * 2], dgr[MAXN * 2];
int qsz;
std::list<int>::iterator q[MAXK];

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        dg[x[i] - y[i] + MAXN].push_back(i);
        dgr[x[i] + y[i]].push_back(i);
        timestamp[i] = -1;
    }

    int cx = 0, cy = 0, dir = 0;
    long long time = 0;
    do {
        // Move
        int steps = INF, cur;
        cur = (n - cx) / mov[dir][0]; if (cur > 0) steps = min(steps, cur);
        cur = -cx / mov[dir][0]; if (cur > 0) steps = min(steps, cur);
        cur = (m - cy) / mov[dir][1]; if (cur > 0) steps = min(steps, cur);
        cur = -cy / mov[dir][1]; if (cur > 0) steps = min(steps, cur);
        // Update
        qsz = 0;
        if (dir == 0 || dir == 3) { // dg
            for (std::list<int>::iterator i = dg[cx - cy + MAXN].begin(); i != dg[cx - cy + MAXN].end(); ++i)
                if (timestamp[*i] == -1) {
                    timestamp[*i] = time + std::abs(cy - y[*i]);
                    q[qsz++] = i;
                }
                for (int i = 0; i < qsz; ++i) dg[cx - cy + MAXN].erase(q[i]);
        } else {    // dgr
            for (std::list<int>::iterator i = dgr[cx + cy].begin(); i != dgr[cx + cy].end(); ++i)
                if (timestamp[*i] == -1) {
                    timestamp[*i] = time + std::abs(cy - y[*i]);
                    q[qsz++] = i;
                }
                for (int i = 0; i < qsz; ++i) dgr[cx + cy].erase(q[i]);
        }
        cx += mov[dir][0] * steps;
        cy += mov[dir][1] * steps;
        time += steps;
        // Reflect
        if ((cx == 0 || cx == n) && (cy == 0 || cy == m)) break;
        if (cx == 0 || cx == n) dir ^= 2;
        else if (cy == 0 || cy == m) dir ^= 1;
        else puts("What???");
    } while (true);

    for (int i = 0; i < k; ++i) printf("%I64d\n", timestamp[i]);

    return 0;
}