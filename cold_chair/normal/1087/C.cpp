#include<cstdio>
#include<algorithm>
#define abs(a) ((a) > 0 ? (a) : -(a))
#define fo(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;

int x[3], y[3];
int x0, y0, ans;

int dis(int u, int v) {
    int s = 0;
    fo(i, 0, 2) s += abs(x[i] - u) + abs(y[i] - v);
    return s;
}

int bz[1001][1001];
int co(int x, int y, int u, int v) {
    if(x > u) swap(x, u), swap(y, v);
    while(x < u) bz[x][y] = 1, x ++;
    while(y < v) bz[x][y] = 1, y ++;
    while(y > v) bz[x][y] = 1, y --;
    bz[u][v] = 1;
}

int main() {
    ans = 1e9;
    fo(i, 0, 2) {
        scanf("%d %d", &x[i], &y[i]);
    }
    fo(i, 0, 1000) fo(j, 0, 1000) {
        int z = dis(i, j);
        if(z < ans) ans = z, x0 = i, y0 = j;
    }
    // printf("%d %d\n", x0, y0);
    fo(i, 0, 2) co(x0, y0, x[i],  y[i]);
    ans = 0;
    fo(i, 0, 1000) fo(j, 0, 1000) ans += bz[i][j];
    printf("%d\n", ans);
    fo(i, 0, 1000) fo(j, 0, 1000)
        if(bz[i][j]) printf("%d %d\n", i, j);
}