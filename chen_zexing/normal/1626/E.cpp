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
using namespace std;
int c[300005],sz[300005];
vector <int> v[300005],vv[300005];
void dfs(int x,int from){
    sz[x]=c[x];
    for(auto t:v[x]) if(t!=from) dfs(t,x),sz[x]+=sz[t];
}
void build(int x,int from){
    if(sz[1]-sz[x]>=2||c[from]) vv[from].push_back(x);
    for(auto t:v[x]){
        if(t!=from&&(sz[t]>=2||c[t])) vv[t].push_back(x);
        if(t!=from) build(t,x);
    }
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&c[i]);
        for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
        dfs(1,0),build(1,0);
        queue <int> q;
        for(int i=1;i<=n;i++) if(c[i]) q.push(i);
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(auto t:vv[temp])
                if(!c[t])
                    c[t]=1,q.push(t);
        }
        for(int i=1;i<=n;i++) printf("%d ",c[i]);
        puts("");
    }
    return 0;
}