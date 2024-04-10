#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int n,m;
int lb[1<<20];
bool g[20][20];
ll dp[1<<20][20];
 
int main(){
 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        g[a][b]=1;
        g[b][a]=1;
    }
    for(int i=1;i<1<<n;i++){
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                lb[i]=j;
                break;
            }
        }
    }
    for(int i=0;i<n;i++)dp[1<<i][i]=1;
    for(int s=0;s<1<<n;s++){
        for(int i=0;i<n;i++){
            if(dp[s][i]){
                for(int j=lb[s]+1;j<n;j++){
                    if(g[i][j]&&!(s&(1<<j))){
                        dp[s|(1<<j)][j]+=dp[s][i];
                    }
                }
            }
        }
    }
    ll ans=0;
    for(int s=0;s<1<<n;s++){
        if(__builtin_popcount(s)>2){
            for(int i=0;i<n;i++){
                if(g[i][lb[s]])ans+=dp[s][i];
            }
        }
    }
    cout<<ans/2<<endl;
 
    return 0;
}