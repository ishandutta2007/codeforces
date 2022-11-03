#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>
#include <map>

using namespace std;

vector < vector <int> > g;
int d[200002],ans[200002];

int dfs(int v,int par = -1) {
    for(int i=0;i<g[v].size();++i) {
        int to=g[v][i];
        if (abs(to)==par) continue;
        if (to<0) to=-to,d[v]++;
        d[v]+=dfs(to,v);
    }
    return d[v];
}

void dfs2(int v,int val,int par = -1) {
    int ret=d[v];
    for(int i=0;i<g[v].size();++i) {
        int to=g[v][i],add=0;
        if (to<0) to=-to,add=-1;
        else add=1;
        if (to==par) continue;
        ans[to]=val+add;
        dfs2(to,ans[to],v);
    }
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,a,b;
    scanf("%d",&n); g.resize(n+1);
    for(int i=1;i<n;i++) {
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(-a);
    }
    dfs(1); ans[1]=d[1];
    dfs2(1,d[1]);
    int mn=ans[1];
    for(int i=1;i<=n;++i) {
//      cout << ans[i] << endl;
        mn=min(mn,ans[i]);
    }
    printf("%d\n",mn);
    bool f=true;
    for(int i=1;i<=n;++i) {
        if (ans[i]==mn) {
            if (!f) printf(" ");
            f=false;
            printf("%d",i);
        }
    }
    printf("\n");
    return 0;
}