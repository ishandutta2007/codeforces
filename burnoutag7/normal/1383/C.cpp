#include<bits/stdc++.h>
using namespace std;

int n,m;
int g[20];
int dp[1<<20];
int fa[20];
string a,b;

int find(int x){
    if(fa[x]==x)return x;
    else return fa[x]=find(fa[x]);
}

void unite(int x,int y){
    x=find(x);
    y=find(y);
    fa[x]=y;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>n>>a>>b;
        memset(g,0,sizeof(g));
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        iota(fa,fa+20,0);
        for(int i=0;i<n;i++){
            g[a[i]-'a']|=1<<b[i]-'a';
            unite(a[i]-'a',b[i]-'a');
        }
        m=0;
        for(int i=0;i<20;i++)m+=fa[i]==i;
        int ans=n;
        for(int s=0;s<1<<20;s++)if(dp[s]){
            ans=min(ans,40-__builtin_popcount(s)-m);
            for(int i=0;i<20;i++){
                if(s>>i&1^1){
                    dp[s|1<<i]|=!(g[i]&s);
                }
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}