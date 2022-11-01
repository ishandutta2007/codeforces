#include<bits/stdc++.h>
using namespace std;

int n,m,dp[1000005];
char buf[1000005];
vector<int> a[1000005];

void mian(){
    for(int i=2;i<=n+m;i++)a[i].clear();
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>buf+1;
        for(int j=1;j<=m;j++)if(buf[j]=='1'){
            a[i+j].emplace_back(j-i);
        }
    }
    int ans=0;
    for(int par=0;par<2;par++){
        memset(dp,0x3f,n*m+5<<2);
        for(int i=2+par;i<=n+m;i+=2){
            sort(a[i].begin(),a[i].end(),greater<int>());
            for(int x:a[i]){
                *lower_bound(dp,dp+n*m,x)=x;
            }
        }
        ans+=lower_bound(dp,dp+n*m,0x3f3f3f3f)-dp;
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