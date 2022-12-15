#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
using namespace std;
struct edge {
    int ed, l;
};
struct node {
    int num,d;
    friend bool operator<(node a, node b) {
        return a.d > b.d;
    }
};
int dis[1005],n,m,s,visit[1005],k,st[1005],ed[1005],ss[1005],ee[1005];
int mn[1005][1005];
vector <edge> v[1005];
priority_queue <node> q;
void input() {
    scanf("%d%d%d", &n, &m, &k);
    int x, y, z;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        ss[i] = x, ee[i] = y;
        edge t;
        t.ed = y;
        t.l = z;
        v[x].push_back(t);
        //e.push_back(t);
        t.ed = x;
        v[y].push_back(t);
        //e.push_back(t);
    }
    for (int i = 1; i <= k; i++) scanf("%d%d", &st[i], &ed[i]);
}
void init(int st) {
    while (!q.empty()) q.pop();
    for (int i = 1; i <= n; i++) dis[i] = INT_MAX, visit[i] = 0;
    s = st;
    dis[s] = 0;
    node p;
    p.num = s;
    p.d = 0;
    q.push(p);
}
void dij() {
    while (!q.empty()) {
        int x = q.top().num;
        q.pop();
        if (visit[x]) continue;
        visit[x] = 1;
        for (int i = 0; i < v[x].size(); i++) {
            if (visit[v[x][i].ed]) continue;
            if(dis[v[x][i].ed]>dis[x]+v[x][i].l) {
                dis[v[x][i].ed] = dis[x] + v[x][i].l;
                node p;
                p.num = v[x][i].ed;
                p.d = dis[v[x][i].ed];
                q.push(p);
            }
        }
    }
}
int main() {
    input();
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        init(i);
        dij();
        for (int j = 1; j <= n; j++) mn[i][j] = dis[j];
    }
    for (int i = 1; i <= m; i++) {
        int cnt = 0;
        for (int j = 1; j <= k; j++) {
            cnt += min(min(mn[st[j]][ed[j]], mn[st[j]][ss[i]] + mn[ee[i]][ed[j]]), mn[st[j]][ee[i]] + mn[ss[i]][ed[j]]);
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}