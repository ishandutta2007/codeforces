#include<bits/stdc++.h>
using namespace std;
int T,n,p[100010];
pair<int,int> pr[100010];
bool vis[100010];
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) vis[i]=0;
    for(int i=1;i<=n;i++) scanf("%d",&pr[i].first);
    for(int i=1;i<=n;i++) scanf("%d",&pr[i].second);
    sort(pr+1,pr+n+1);
    for(int i=1;i<=n;i++) p[i]=pr[i].second;
    int t=0;long long ans=0;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        int cnt=0,x=i;
        while(!vis[x]){
            vis[x]=1;cnt++;
            x=p[x];
        }
        t+=cnt/2;
    }
    for(int i=1;i<=t;i++) ans-=i;
    for(int i=n-t+1;i<=n;i++) ans+=i;
    printf("%lld\n",ans*2);
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}