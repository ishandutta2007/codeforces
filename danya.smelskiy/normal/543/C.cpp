#include <bits/stdc++.h>
using namespace std;

int n,m;
string s[25];
int a[25][25];
int pr[25][25];
int ms[25][25];
int dp[(1<<20)+5];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;++i)
        cin>>s[i];
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            cin>>a[i][j];
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            int mx=0;
            for (int k=0;k<n;++k) if (s[i][j]==s[k][j]){
                ms[i][j]|=(1<<(k));
                mx=max(mx,a[k][j]);
                pr[i][j]+=a[k][j];
            }
            pr[i][j]-=mx;
        }
    }
    for (int i=0;i<(1<<n);++i)
        dp[i]=1e9;
    dp[0]=0;
    for (int i=0;i<(1<<n)-1;++i){
        int mn=0;
        for (int j=0;j<n;++j)
        if (!(i&(1<<j))) {
            mn=j;
            break;
        }
        for (int j=0;j<m;++j){
            dp[(i|(1<<mn))]=min(dp[(i|(1<<mn))],dp[i]+a[mn][j]);
            dp[(i|ms[mn][j])]=min(dp[(i|ms[mn][j])],dp[i]+pr[mn][j]);
        }
    }
    cout<<dp[(1<<n)-1];
}