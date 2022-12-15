#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int fa[1005],d[1005],vis[1005];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int query(int x){
    printf("? %d\n",x);
    fflush(stdout);
    int t;
    scanf("%d",&t);
    return t;
}
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&d[i]),fa[i]=i,vis[i]=0;
        for(int i=1;i<=n;i++){
            int p=0;
            for(int j=1;j<=n;j++) if(!vis[find(j)]&&d[j]){
                    if(d[j]>d[p]) p=j;
                }
            if(!p) break;
            vis[p]=1;
            for(int j=1;j<=d[p];j++){
                int x=find(p),y=find(query(p));
                if(vis[y]){
                    fa[x]=y;
                    break;
                }
                else{
                    fa[y]=x,vis[y]=1;
                }
            }
        }
        printf("! ");
        for(int i=1;i<=n;i++) printf("%d%c",find(i),i==n?'\n':' ');
        fflush(stdout);
    }
    return 0;
}