#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

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
int dis[100005],n,m,s,visit[100005],a,b,x[100005],y[100005],id[100005];
vector <edge> v[100005];
priority_queue <node> q;
bool cmp1(int a,int b){
    return x[a]<x[b];
}
bool cmp2(int a,int b){
    return y[a]<y[b];
}
void init() {
    scanf("%d%d", &n, &m);
    s=0;
    for (int i = 0; i <= m+1; i++) dis[i] = INT_MAX;
    scanf("%d%d",&x[0],&y[0]);
    scanf("%d%d",&x[m+1],&y[m+1]);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &x[i], &y[i]);
        id[i]=i;
    }
    for(int i=1;i<=m;i++){
        v[i].push_back(edge{0,min(abs(x[i]-x[0]),abs(y[i]-y[0]))});
        v[0].push_back(edge{i,min(abs(x[i]-x[0]),abs(y[i]-y[0]))});
        v[i].push_back(edge{m+1,abs(x[i]-x[m+1])+abs(y[i]-y[m+1])});
        v[m+1].push_back(edge{i,abs(x[i]-x[m+1])+abs(y[i]-y[m+1])});
    }
    v[0].push_back(edge{m+1,abs(x[0]-x[m+1])+abs(y[0]-y[m+1])});
    sort(id+1,id+m+1,cmp1);
    for(int i=1;i<m;i++){
        v[id[i]].push_back(edge{id[i+1],abs(x[id[i+1]]-x[id[i]])});
        v[id[i+1]].push_back(edge{id[i],abs(x[id[i+1]]-x[id[i]])});
    }
    sort(id+1,id+m+1,cmp2);
    for(int i=1;i<m;i++){
        v[id[i]].push_back(edge{id[i+1],abs(y[id[i+1]]-y[id[i]])});
        v[id[i+1]].push_back(edge{id[i],abs(y[id[i+1]]-y[id[i]])});
    }
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
    init();
    dij();
    cout<<dis[m+1]<<endl;
    return 0;
}