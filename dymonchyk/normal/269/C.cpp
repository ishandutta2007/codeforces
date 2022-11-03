#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;

vector < vector <int> > g,d;
int deg[200005],ans[200005],c[200005];
bool u[200005];
int q[200005],qs=0;

void dfs(int v) {
    for(int i=0;i<g[v].size();++i) {
        int e=d[v][i]/2,type=d[v][i]&1;
        if (ans[e]==-1) {
            ans[e]=type;
            deg[g[v][i]]-=c[e];
            if (deg[g[v][i]]==0) q[qs++]=g[v][i];
        }
    }
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,a,b;
    scanf("%d%d",&n,&m);
    g.resize(n); d.resize(n);
    for(int i=0;i<m;++i) {
        scanf("%d%d%d",&a,&b,&c[i]); --a; --b;
        g[a].push_back(b);
        d[a].push_back(2*i);
        g[b].push_back(a);
        d[b].push_back(2*i+1);
        deg[a]+=c[i]; deg[b]+=c[i];
    }
    for(int i=1;i<n-1;++i) {
        deg[i]/=2;
    }
    deg[0]=0;
    memset(ans,-1,sizeof(ans));
    q[0]=0; qs=1;
    for(int i=0;i<qs;++i)
        dfs(q[i]);
    for(int i=0;i<m;++i)
        if (ans[i]==-1) return -1;
        else printf("%d\n",ans[i]);
    return 0;
}