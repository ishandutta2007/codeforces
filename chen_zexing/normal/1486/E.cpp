#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
struct edge {
    int ed, l;
    friend bool operator <(edge a,edge b){
        return a.l<b.l;
    }
};
struct node {
    int num,d;
    friend bool operator<(node a, node b) {
        return a.d > b.d;
    }
};
int dis[5100005],n,m,s,visit[5100005];
vector <edge> v[5100005];
priority_queue <node> q;
void init() {
    scanf("%d%d", &n, &m);
    s=1;
    int x, y, z;
    for (int i = 1; i <= 51*n; i++) dis[i] = INT_MAX;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        v[x].push_back(edge{y+z*n,0});
        for(int j=1;j<=50;j++) v[y+j*n].push_back(edge{x,(j+z)*(j+z)});
        v[y].push_back(edge{x+z*n,0});
        for(int j=1;j<=50;j++) v[x+j*n].push_back(edge{y,(j+z)*(j+z)});
    }
    dis[s] = 0;
    node p;
    p.num = s;
    p.d = 0;
    q.push(p);
}
void dij() {
    while (!q.empty()) {
        long long x = q.top().num;
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
void output() {
    for (int i = 1; i <= n; i++){
        if(dis[i]<INT_MAX) printf("%d ",dis[i]);
        else printf("-1 ");
    }
}
int main() {
    init();
    dij();
    output();
    return 0;
}