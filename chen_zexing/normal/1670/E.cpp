#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
using namespace std;
vector <int> v[200005];
int dep[200005],x[200005],y[200005];
int ver[200005],edge[200005],fa[200005],n;
void dfs(int x,int from,int fl){
    dep[x]=dep[from]+1;
    for(auto t:v[x]) if(t!=from){
            fa[t]=t-1+n*fl,ver[t]=t-1+n*(fl^1);
            dfs(t,x,fl^1);
        }
}
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int p;
        cin>>p,n=(1<<p);
        for(int i=1;i<=n;i++) v[i].clear();
        for(int i=1;i<n;i++) scanf("%d%d",&x[i],&y[i]),v[x[i]].push_back(y[i]),v[y[i]].push_back(x[i]);
        ver[1]=n;
        dfs(1,0,1);
        for(int i=1;i<n;i++){
            if(dep[x[i]]<dep[y[i]]) swap(x[i],y[i]);
            edge[i]=fa[x[i]];
        }
        printf("%d\n",1);
        for(int i=1;i<=n;i++) printf("%d%c",ver[i],i==n?'\n':' ');
        for(int i=1;i<n;i++) printf("%d%c",edge[i],i==n-1?'\n':' ');
    }
    return 0;
}
//unordered_map