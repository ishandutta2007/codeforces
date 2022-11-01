#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,c[505][505];

void mian(){
    cin>>n;
    for(int i=1;i<=n*2;i++)for(int j=1;j<=n*2;j++){
        cin>>c[i][j];
    }
    ll sum=0;
    int ans=1e9;
    for(int i=n+1;i<=n*2;i++)for(int j=n+1;j<=n*2;j++)sum+=c[i][j];
    for(int i=0;i<=n;i+=n){
        int j=n-i;
        for(int x=1;x<=n;x+=max(1,n-1))for(int y=1;y<=n;y+=max(1,n-1)){
            ans=min(ans,c[i+x][j+y]);
        }
    }
    cout<<ans+sum<<'\n';
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