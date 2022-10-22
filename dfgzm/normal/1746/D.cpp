#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1000010;
int i,j,k,n,m;ll sum[maxn],Ans,u[maxn];
vector<int>V[maxn];
void dfs(int now,int K,long long Sum){
    Sum+=sum[now];
    if(!V[now].size()){Ans+=Sum*K;u[now]=Sum;return;}
    vector<ll>V2;
    for(int x:V[now]){
        dfs(x,K/V[now].size(),Sum);
        V2.push_back(u[x]);
    }sort(V2.begin(),V2.end());
    reverse(V2.begin(),V2.end());
    for(int i=0;i<K%V[now].size();i++)Ans+=V2[i];
    u[now]=V2[K%V[now].size()];
    // cerr<<u[now]<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(i=1;i<=n;i++)V[i].clear();
        for(i=2;i<=n;i++){
            int x;
            scanf("%d",&x);
            V[x].push_back(i);
        }
        for(i=1;i<=n;i++)scanf("%lld",&sum[i]);
        dfs(1,m,0);
        printf("%lld\n",Ans);
        Ans=0;
    }
}