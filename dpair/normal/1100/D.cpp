#include <cstdio>
#include <cstdlib>


struct Rook {
    int x, y;
}a[1005];

int x, y;

bool vis[1005][1005];

inline void move(int dx, int dy) {
    if(vis[x + dx][y + dy]) {
        if(dx == 0) dy = 0;
        else dx = 0;
    }
    printf("%d %d\n", x += dx, y += dy); fflush(stdout);
    int k, u, v; scanf("%d%d%d", &k, &u, &v);
    if(k == -1) exit(0);
    vis[a[k].x][a[k].y] = 0; vis[a[k].x = u][a[k].y = v] = 1;
}

int main() {
    scanf("%d%d", &x, &y);
    for (int i = 1;i <= 666;++ i) {
        scanf("%d%d", &a[i].x, &a[i].y);
        vis[a[i].x][a[i].y] = 1;
    }
    while(x < 500) move(1, 0);
    while(x > 500) move(-1, 0);
    while(y < 500) move(0, 1);
    while(y > 500) move(0, -1);

    int cnt[4] = {0, 0, 0, 0}; 
    for (int i = 1;i <= 666;++ i) ++ cnt[(a[i].x > 500) << 1 | (a[i].y > 500)];
    int id = 0; for (int i = 0;i < 4;++ i) if(cnt[i] <= 166) id = i;
    const int dx = (id >> 1 & 1)? -1 : 1;
    const int dy = (id & 1)? -1 : 1;
    move(dx, dy);
    while(1 <= x && x <= 999 && 1 <= y && y <= 999) move(dx, dy);
}



/*
DPair 
*/