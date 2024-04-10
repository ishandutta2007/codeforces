#include <bits/stdc++.h>
using namespace std;


int n,m;
int dp[42][(1<<6)+2][(1<<6)+2];

inline bool check(int x,int y,int z){
    for (int i=0;i<n;++i) if (!(y&(1<<i))){
        if (i && (y&(1<<(i-1)))) continue;
        if (x&(1<<i)) continue;
        if (z&(1<<i)) continue;
        if (i<n-1 && y&(1<<(i+1))) continue;
        return false;
    }
    return true;
}
inline int get(int x){
    int res=0;
    for (int i=0;i<n;++i)
        if (x&(1<<i)) res++;
    return res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    if (n>m) swap(n,m);
    for (int i=1;i<=m;++i)
        for (int j=0;j<(1<<n);++j)
            for (int k=0;k<(1<<n);++k)
                dp[i][j][k]=1e9;
    for (int i=0;i<(1<<n);++i)
        for (int j=0;j<(1<<n);++j)
            if (check(0,i,j)) dp[1][i][j]=get(i)+get(j);
    for (int i=2;i<=m;++i)
        for (int j=0;j<(1<<n);++j)
            for (int k=0;k<(1<<n);++k)
                for (int z=0;z<(1<<n);++z)
                    if (dp[i-1][z][j]!=1e9 && check(z,j,k)) dp[i][j][k]=min(dp[i][j][k],dp[i-1][z][j]+get(k));
    int ans=1e9;
    for (int i=0;i<(1<<n);++i)
        ans=min(ans,dp[m][i][0]);
    cout<<n*m-ans;
}