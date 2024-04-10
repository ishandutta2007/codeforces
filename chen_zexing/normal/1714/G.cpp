#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
long long prea[200005],preb[200005];
long long fab[200005][20],fa[200005][20],dep[200005];
struct edge{
    int ed,a,b;
};
vector <edge> v[200005];
void dfs(int x,int from){
    dep[x]=dep[from]+1;
    for(auto t:v[x])
        if(t.ed!=from){
            preb[t.ed]=preb[x]+t.b,prea[t.ed]=prea[x]+t.a;
            fab[t.ed][0]=t.b,fa[t.ed][0]=x;
            dfs(t.ed,x);
        }
}
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) v[i].clear(),prea[i]=preb[i]=fab[i][0]=fa[i][0]=0;
        for(int i=2,x,a,b;i<=n;i++){
            scanf("%d%d%d",&x,&a,&b);
            v[x].push_back(edge{i,a,b});
        }
        dfs(1,0);
        for(int i=1;i<20;i++)
            for(int j=1;j<=n;j++)
                fab[j][i]=fab[j][i-1]+fab[fa[j][i-1]][i-1],fa[j][i]=fa[fa[j][i-1]][i-1];
        for(int i=2;i<=n;i++){
            if(prea[i]>=preb[i]){
                printf("%lld ",dep[i]-1);
                continue;
            }
            int now=i;
            long long ac=0;
            for(int j=19;j>=0;j--)
                if(ac+fab[now][j]<preb[i]-prea[i])
                    ac+=fab[now][j],now=fa[now][j];
            printf("%lld ",dep[i]-1-(dep[i]-dep[now]+1));
        }
        puts("");
    }
    return 0;
}