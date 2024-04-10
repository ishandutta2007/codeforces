// --------
//< 114514 >
// --------
//        \   ^__^
//         \  (oo)\_______
//            (__)\       )\/\
//                ||----w |
//                ||     ||
#include<bits/stdc++.h>
using namespace std;

int n,m,ans,g[100005],vis[100005];

void dfs(const int& x){
    if(g[x]==x)return;
    vis[x]=1;
    if(!vis[g[x]])dfs(g[x]);
    else ans+=vis[g[x]]==1;
    ans++;
    vis[x]=2;
}

void mian(){
    cin>>n>>m;
    iota(g+1,g+1+n,1);
    for(int i=1;i<=m;i++){
        static int x,y;
        cin>>x>>y;
        g[x]=y;
    }
    memset(vis+1,0,n<<2);
    ans=0;
    for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}