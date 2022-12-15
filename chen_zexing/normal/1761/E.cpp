#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
char s[4005][4005];
int fa[4005],sz[4005],d[4005],mmn[4005];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1),fa[i]=i,sz[i]=1,d[i]=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(s[i][j]=='1'){
                int x=find(i),y=find(j);
                if(x!=y) fa[y]=x,sz[x]+=sz[y];
                d[i]++,d[j]++;
            }
    if(sz[find(1)]==n){
        puts("0");
        return;
    }
    for(int i=1;i<=n;i++) mmn[i]=n;
    for(int i=1;i<=n;i++) mmn[find(i)]=min(mmn[find(i)],d[i]);
    for(int i=1;i<=n;i++){
        if(d[i]==mmn[find(i)]&&d[i]<sz[find(i)]-1||d[i]==0){
            printf("1\n%d\n",i);
            return;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++) if(fa[i]==i) cnt++;
    assert(cnt>=2);
    if(cnt==2) {
        int mn = INT_MAX, p = -1;
        for (int i = 1; i <= n; i++)
            if (fa[i] == i && sz[i] < mn) {
                mn = sz[i], p = i;
            }
        printf("%d\n", mn);
        for (int i = 1; i <= n; i++) if (find(i) == p) printf("%d ", i);
        puts("");
    }
    else{
        printf("2\n1 ");
        for(int i=2;i<=n;i++) s[1][i]=s[1][i]=='1'?'0':'1',s[i][1]=s[1][i];
        for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1,d[i]=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(s[i][j]=='1'){
                    int x=find(i),y=find(j);
                    if(x!=y) fa[y]=x,sz[x]+=sz[y];
                    d[i]++,d[j]++;
                }
        for(int i=1;i<=n;i++) mmn[i]=n;
        for(int i=1;i<=n;i++) mmn[find(i)]=min(mmn[find(i)],d[i]);
        for(int i=1;i<=n;i++){
            if(d[i]==mmn[find(i)]&&d[i]<sz[find(i)]-1||d[i]==0){
                printf("%d\n",i);
                return;
            }
        }
    }
}
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}