#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
#include <sstream>

using namespace std;

vector <vector <int> > g;
bool u[202];

void dfs(int v) {
    u[v]=true;
    for(int i=0;i<g[v].size();++i)
        if (!u[g[v][i]]) dfs(g[v][i]);
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,k,a;
    scanf("%d%d",&n,&m);
    g.resize(n+m);
    bool was=false;
    for(int i=0;i<n;++i) {
        scanf("%d",&k);
        was=was||(k>0);
        for(int j=0;j<k;++j) {
            scanf("%d",&a); --a;
            g[i].push_back(n+a);
            g[n+a].push_back(i);
        }
    }
    int cnt=0;
    for(int i=0;i<n;++i)
        if (!u[i]) ++cnt,dfs(i);
    cout << cnt-(was) << endl;
    return 0;
}