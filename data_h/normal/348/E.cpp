#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int N = 111111, M = 18;
const int inf = 1000000005;

int father[N], exist[N], downMan[N], downDis[N], upMan[N], upDis[N], upLCA[N];
int dep[N], n, mark[N];

struct eglist {
    int length[N << 1], other[N << 1], succ[N << 1], last[N << 1], sum;
    void clear() {
        memset(last, -1, sizeof(last));
        sum = 0;
    }
    void addEdge(int a, int b, int c) {
        other[sum] = b, succ[sum] = last[a], last[a] = sum, length[sum++] = c;
        other[sum] = a, succ[sum] = last[b], last[b] = sum, length[sum++] = c;
    }
}e;

inline void update(int &xdis, int &xman, int ydis, int yman, int id) {
    if (ydis > xdis) {
        xdis = ydis;
        xman = yman;
    } else if (ydis == xdis) {
        xman = id;
    }
}

void dfsSon(int x, int fa) {
    father[x] = fa;
    for(int i = e.last[x]; ~i; i = e.succ[i]) {
        int y = e.other[i];
        if (y == fa)
            continue;
        dfsSon(y, x);
        if (downDis[y] >= 0) {
            update(downDis[x], downMan[x], downDis[y] + e.length[i], downMan[y], x);
        }
    }
    if (exist[x]) {
        update(downDis[x], downMan[x], 0, x, x);
    }
}

void dfsFather(int x, int fa) {
    if (exist[x]) {
        if (upDis[x] < 0) {
            upDis[x] = 0;
            upMan[x] = x;
            upLCA[x] = x;
        }
        if (downMan[x] != -1 && downDis[x] > upDis[x]) {
            mark[x]--;
            mark[downMan[x]]++;
        } else if (downDis[x] < upDis[x]) {
            mark[father[upLCA[x]]]--;
            mark[upLCA[x]]--;
            mark[x]++;
            mark[upMan[x]]++;
        }
    }
    vector<pair<int, int> > sons;
    for(int i = e.last[x]; ~i; i = e.succ[i]) {
        int y = e.other[i];
        if (y == fa)
            continue;
        sons.push_back(make_pair(y, e.length[i]));
        upLCA[y] = x;
    }
    int maxDis = -inf, maxMan, maxLCA;
    for(int i = 0; i < (int)sons.size(); i++) {
        int y = sons[i].first, length = sons[i].second;
        update(upDis[y], upMan[y], maxDis + length, maxMan, x);
        update(maxDis, maxMan, downDis[y] + length, downMan[y], x);
    }
    maxDis = -inf, maxMan = x;
    for(int i = (int)sons.size() - 1; i >= 0; i--) {
        int y = sons[i].first, length = sons[i].second;
        update(upDis[y], upMan[y], maxDis + length, maxMan, x);
        update(maxDis, maxMan, downDis[y] + length, downMan[y], x);
    }
    for(int i = e.last[x]; ~i; i = e.succ[i]) {
        int y = e.other[i];
        if (y == fa)
            continue;
        if (upDis[x] + e.length[i] > upDis[y]) {
            upDis[y] = upDis[x] + e.length[i];
            upMan[y] = upMan[x];
            upLCA[y] = upLCA[x];
        } else if (upDis[x] + e.length[i] == upDis[y]) {
            upMan[y] = x;
        }
        dfsFather(y, x);
    }
}

int ans = -1, ansCount;

int dfs(int x, int fa) {
    int tot = mark[x];
    for(int i = e.last[x]; ~i; i = e.succ[i]) {
        int y = e.other[i];
        if (y == fa)
            continue;
        tot += dfs(y, x);
    }
    if (!exist[x]) {
        if (tot > ans) {
            ans = tot;
            ansCount = 1;
        } else if (tot == ans) {
            ansCount++;
        }
    }
    return tot;
}

int show(char buf[], int a, int b) {
    printf("%s %d %d\n", buf, a, b);
}

int main() {
    scanf("%d", &n);
    int pCount;
    scanf("%d", &pCount);
    while(pCount--) {
        int x;
        scanf("%d", &x);
        exist[x] = 1;
    }
    e.clear();
    for(int i = 1; i < n; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        e.addEdge(a, b, c);
    }
    for(int i = 1; i <= n; i++) {
        downDis[i] = upDis[i] = -inf;
    }
    dfsSon(1, 0);
    dfsFather(1, 0);
    dfs(1, 0);
    /*for(int i = 1; i <= n; i++) {
        printf("id = %d:\n", i);
        show("down", downDis[i], downMan[i]);
        show("up", upDis[i], upMan[i]);
    }*/
    printf("%d %d\n", ans, ansCount);
    return 0;
}