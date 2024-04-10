#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
vector <int> v[200005];
int d[200005],ans[200005],f[200005];
queue <int> q;
void bfs(){
    d[1]=1;
    q.push(1);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<v[x].size();i++)
            if(!d[v[x][i]])
                d[v[x][i]]=d[x]+1,q.push(v[x][i]);
    }
}
int dfs2(int x){
    if(f[x]) return ans[x];
    f[x]=1;
    for(int i=0;i<v[x].size();i++){
        if(d[v[x][i]]<=d[x]) ans[x]=min(ans[x],d[v[x][i]]);
        else ans[x]=min(ans[x],dfs2(v[x][i]));
    }
    return ans[x];
}
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) v[i].clear(),f[i]=0;
        for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
        }
        for(int i=1;i<=n;i++) d[i]=0;
        bfs();
        for(int i=1;i<=n;i++) ans[i]=d[i];
        dfs2(1);
        for(int i=1;i<=n;i++) printf("%d ",ans[i]-1);
        puts("");
    }
    return 0;
}