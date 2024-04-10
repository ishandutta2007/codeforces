#include<bits/stdc++.h>
using namespace std;
int T,n,a[100010],w[100010][2];
vector<int> G[100010];
void dfs(int x,int fa,int d=0){
    int cnt=0;
    for(auto to:G[x]){
        if(to==fa) continue;
        dfs(to,x,d^1);
        w[to][d]++;cnt++;
    }w[x][d^1]+=cnt;
}
void solve(){
    mt19937 myrand(time(NULL));
    scanf("%d",&n);
    for(int i=1;i<=n;i++) w[i][0]=w[i][1]=0,G[i].clear();
    for(int i=1,x,y;i<n;i++){
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }dfs(1,0);
    for(int i=1;i<=n;i++) printf("%d ",w[i][0]-w[i][1]);
    puts("");
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}