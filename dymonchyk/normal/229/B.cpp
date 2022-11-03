#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#pragma comment (linker,"/STACK:128000000")

using namespace std;

vector < vector <int> > g,d,mov;
priority_queue < pair <int,int> > q;
int dist[100005];
bool was[100005];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,a,b,c;
    scanf("%d%d\n",&n,&m);
    g.resize(n); mov.resize(n); d.resize(n);
    for(int i=0;i<m;++i) {
        scanf("%d%d%d",&a,&b,&c);
        --a; --b;
        g[a].push_back(b);
        d[a].push_back(c);
        g[b].push_back(a);
        d[b].push_back(c);
    }
    for(int i=0;i<n;++i) {
        scanf("%d",&a);
        for(int j=0;j<a;++j) {
            scanf("%d",&b);
            mov[i].push_back(b);
        }
    }
    memset(dist,-1,sizeof(dist));
    dist[0]=0;
    q.push(make_pair(0,0));
    while(q.size()) {
        pair <int,int> top=q.top(); q.pop();
        if (dist[top.second]!=-top.first) continue;
        int mom=-top.first;
        if (!was[top.second])
            for(int i=0;i<mov[top.second].size();++i) {
                if (mov[top.second][i]>=mom) {
                    if (mov[top.second][i]>mom) {
                        break;
                    } else ++mom;
                }
            }
        if (mom!=-top.first) {
            q.push(make_pair(-mom,top.second));
            if (top.second!=n-1) dist[top.second]=mom;
            was[top.second]=true;
            continue;
        }
        int v=top.second,dd=-top.first;
        for(int i=0;i<g[v].size();++i) {
            int to=g[v][i];
            if ((dist[to]==-1||dist[to]>dd+d[v][i])&&!was[to]) {
                dist[to]=dd+d[v][i];
                q.push(make_pair(-dist[to],to));
            }
        }
    }
    printf("%d\n",dist[n-1]);
    return 0;
}