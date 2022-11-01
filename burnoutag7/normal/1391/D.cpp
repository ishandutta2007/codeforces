#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> a;
int g[1000005];
int dp[1000005][1<<3];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    if(min(n,m)>=4){
        cout<<-1<<endl;
        return 0;
    }
    a.resize(n);
    for(int i=0;i<n;i++){
        a[i].resize(m);
        for(int j=0;j<m;j++){
            char c;
            cin>>c;
            a[i][j]=c=='1';
        }
    }
    if(n<m){
        vector<vector<int>> b=a;
        a.resize(m);
        for(int i=0;i<m;i++){
            a[i].resize(n);
            for(int j=0;j<n;j++){
                a[i][j]=b[j][i];
            }
        }
        swap(n,m);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            g[i]|=a[i][j]<<j;
        }
    }
    memset(dp,0x3f,sizeof(dp));
    for(int s=0;s<1<<m;s++)dp[0][s]=__builtin_popcount(g[0]^s);
    for(int i=0;i+1<n;i++){
        for(int s=0;s<1<<m;s++){
            for(int t=0;t<1<<m;t++){
                if(((s^t^s>>1^t>>1)&(1<<m-1)-1)==(1<<m-1)-1)dp[i+1][t]=min(dp[i+1][t],dp[i][s]+__builtin_popcount(g[i+1]^t));
            }
        }
    }
    cout<<*min_element(dp[n-1],dp[n-1]+(1<<m))<<endl;

    return 0;
}