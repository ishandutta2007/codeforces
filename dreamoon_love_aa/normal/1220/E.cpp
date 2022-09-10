#include<bits/stdc++.h>
using namespace std;
long long w[200000];
vector<int>e[200000];
int deg[200000];
bool removed[200000];
long long ma;
void dfs(int x, int from,long long v) {
    ma = max(ma, v);
    for(int y: e[x]) {
        if(y == from || !removed[y]) continue;
        dfs(y, x, v + w[y]);
    }
}
int to[200000];
int find(int x) {
    if(x == to[x]) return x;
    return to[x] = find(to[x]);
}
void connect(int x, int y) {
    x = find(x);
    y = find(y);
    to[x] = y;
}
int main() {
    long long an = 0;
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &w[i]);
        to[i] = i;
    }
    for(int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--;
        y--;
        connect(x, y);
        e[x].push_back(y);
        e[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    int s;
    scanf("%d", &s);
    s--;
    for(int i = 0; i < n; i++) {
        if(find(i) == find(s)) an += w[i];
    }
    queue<int> qe;
    for(int i = 0; i < n; i++) {
        if(i != s && deg[i] == 1 && find(i) == find(s)) {
            qe.push(i);
        }
    }
    while(qe.size()) {
        int x = qe.front();
        removed[x] = 1;
        qe.pop();
        an -= w[x];
        for(int y: e[x]) {
            deg[y]--;
            if(deg[y] == 1 && y != s) {
                qe.push(y);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(!removed[i] && find(i) == find(s)) {
            for(int y: e[i]) {
                if(removed[y]) {
                    dfs(y, y, w[y]);
                }
            }
        }
    }
    printf("%lld\n", an + ma);
    return 0;
}