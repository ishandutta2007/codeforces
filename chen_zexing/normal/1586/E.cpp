#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#include <list>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
vector <int> v[300005];
int fa[300005];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int f[300005][20];
int x[300005],y[300005],cnt[300005],dep[300005];
void dfs(int x,int from){
    dep[x]=dep[from]+1;
    for(auto t:v[x])
        if(t!=from)
            f[t][0]=x,dfs(t,x);
}
int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=19;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
    if(x==y) return x;
    for(int i=19;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    return f[x][0];
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,m,q,c=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++) fa[i]=i;
        for(int i=1,x,y;i<=m;i++){
            scanf("%d%d",&x,&y);
            if(find(x)==find(y)) continue;
            v[x].push_back(y),v[y].push_back(x),fa[find(y)]=find(x);
        }
        cin>>q;
        for(int i=1;i<=q;i++) scanf("%d%d",&x[i],&y[i]),cnt[x[i]]++,cnt[y[i]]++;
        for(int i=1;i<=n;i++) if(cnt[i]%2) c++;
        if(c) puts("NO"),printf("%d\n",c/2);
        else{
            dfs(1,0);
            for(int i=1;i<=19;i++)
                for(int j=1;j<=n;j++)
                    f[j][i]=f[f[j][i-1]][i-1];
            puts("YES");
            for(int i=1;i<=q;i++){
                int l=lca(x[i],y[i]);
                printf("%d\n",dep[x[i]]+dep[y[i]]-dep[l]*2+1);
                while(x[i]!=l) printf("%d ",x[i]),x[i]=f[x[i]][0];
                printf("%d ",l);
                vector <int> temp;
                while(y[i]!=l) temp.push_back(y[i]),y[i]=f[y[i]][0];
                while(temp.size()) printf("%d ",temp.back()),temp.pop_back();
                puts("");
            }
        }
    }
    return 0;
}
//
/// 
//01
//