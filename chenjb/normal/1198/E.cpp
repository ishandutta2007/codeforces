#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
using namespace std;
#define N 1100
#define M 610000
const long long inf = 2147483647ll*1000000ll;
struct EDGE { int adj, next; long long w; } edge[M];
int top, gh[N], nrl[N],S,T;
void addedge(int x, int y, long long w) {
    edge[++top].adj = y;
    edge[top].w = w;
    edge[top].next = gh[x];
    gh[x] = top;
    edge[++top].adj = x;
    edge[top].w = 0;
    edge[top].next = gh[y];
    gh[y] = top;
}
int dist[N], q[N];
int bfs() {
    memset(dist, 0, sizeof(dist));
    q[1] = S; int head = 0, tail = 1; dist[S] = 1;
    while (head != tail) {
        int x = q[++head];
        for (int p=gh[x]; p; p=edge[p].next)
            if (edge[p].w && !dist[edge[p].adj]) {
                dist[edge[p].adj] = dist[x] + 1;
                q[++tail] = edge[p].adj;
            }
    }
    return dist[T];
}
long long dinic(int x, long long delta) {
    if (x==T) return delta;
    for (int& p=nrl[x]; p && delta; p=edge[p].next)
        if (edge[p].w && dist[x]+1 == dist[edge[p].adj]) {
            long long dd = dinic(edge[p].adj, min(delta, edge[p].w));
            if (!dd) continue;
            edge[p].w -= dd;
            edge[p^1].w += dd;
            return dd;
        }
    return 0;
}
long long work() {
    long long ans = 0;
    while (bfs()) {
        memcpy(nrl, gh, sizeof(gh));
        long long t; while (t = dinic(S, inf)) ans += t;
    }
    return ans;
}
struct node
{
    int x0,y0,x1,y1;
    void read()
    {
        scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
        x1++; y1++;
    }
}a[1100];
int n,m;
vector<int> q1,q2;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)a[i].read();
    top=1; 
    for(int i=1;i<=m;i++)q1.pb(a[i].x0),q1.pb(a[i].x1);
    for(int i=1;i<=m;i++)q2.pb(a[i].y0),q2.pb(a[i].y1); 
    sort(q1.begin(),q1.end());
    sort(q2.begin(),q2.end());
    q1.resize(unique(q1.begin(),q1.end())-q1.begin());
    q2.resize(unique(q2.begin(),q2.end())-q2.begin());
    S=0;
    T=N-1;
    int l=q1.size();
    int r=q2.size();
    for(int i=0;i<l-1;i++)
        for(int j=0;j<r-1;j++)
            for(int k=1;k<=m;k++)
                if(a[k].x0<=q1[i]&&q1[i+1]<=a[k].x1&&a[k].y0<=q2[j]&&q2[j+1]<=a[k].y1)addedge(i+1,l+j+1,inf);
    for(int i=0;i<l-1;i++)addedge(S,i+1,q1[i+1]-q1[i]);
    for(int i=0;i<r-1;i++)addedge(l+i+1,T,q2[i+1]-q2[i]);
    cout<<work()<<endl;
    return 0;
}