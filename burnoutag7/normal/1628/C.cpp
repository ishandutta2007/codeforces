#include<bits/stdc++.h>
using namespace std;

int n;
bool vis[1005][1005];

void mian(){
    for(int i=1;i<=n;i++)memset(vis[i]+1,0,n);
    cin>>n;
    for(int i=1,a;i<=n;i++)cin>>a;
    int ans=0;
    for(int i=2,a;i<=n;i++)for(int j=1;j<=n;j++){
        cin>>a;
        if(!vis[i-1][j]){
            vis[i-1][j]^=1;
            if(j+1<=n)vis[i][j+1]^=1;
            if(j>=2)vis[i][j-1]^=1;
            if(i+1<=n)vis[i+1][j]^=1;
            ans^=a;
        }
    }
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