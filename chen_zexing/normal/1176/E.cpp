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
vector <int> v[200005];
int fa[200005],c[200005];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void dfs(int x,int from){
    for(auto t:v[x])
        if(t!=from)
            c[t]=c[x]^1,dfs(t,x);
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) fa[i]=i,v[i].clear();
        for(int i=1,x,y;i<=m;i++){
            scanf("%d%d",&x,&y);
            if(find(x)==find(y)) continue;
            v[x].push_back(y),v[y].push_back(x);
            fa[find(y)]=find(x);
        }
        c[1]=1,dfs(1,0);
        int cnt=0;
        for(int i=1;i<=n;i++) cnt+=c[i];
        if(cnt*2>n){
            for(int i=1;i<=n;i++) c[i]^=1;
            cnt=n-cnt;
        }
        printf("%d\n",cnt);
        for(int i=1;i<=n;i++) if(c[i]) printf("%d ",i);
        puts("");
    }
    return 0;
}
//
/// 
//01
//