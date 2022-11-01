#include<bits/stdc++.h>
using namespace std;

int n,m;
char g[105][105];

void mian(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>g[i]+1;
    int ans=0;
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            ans+=i+(g[i][j]=='D')>n||j+(g[i][j]=='R')>m;
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
    while(T--){
        mian();
    }

    return 0;
}