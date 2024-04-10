#include <bits/stdc++.h>
using namespace std;


int n;
int a[5];
int dp[1005][(1<<12)];
string s[5];
int b[1005];

inline void update(int x,int y,int val){
    if (dp[x][y]<val) return;
    dp[x][y]=val;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=4;++i)
        cin>>a[i];
    for (int i=1;i<=4;++i)
        cin>>s[i];
    for (int i=1;i<=n;++i) {
        if (s[1][i-1]=='.') b[i]|=1;
        if (s[2][i-1]=='.') b[i]|=2;
        if (s[3][i-1]=='.') b[i]|=4;
        if (s[4][i-1]=='.') b[i]|=8;
    }
    int op=b[1];
    op|=(b[2]<<4);
    op|=(b[3]<<8);
    for (int i=1;i<=n+1;++i)
        for (int j=0;j<(1<<12);++j)
            dp[i][j]=1e9;
    dp[1][op]=0;
    for (int i=1;i<=n;++i) {
        for (int j=0;j<(1<<12);++j) if (dp[i][j]<1e9) {
            int msk=(j>>4);
            if (i+3<=n) msk|=(b[i+3]<<8);
            if ((j&15)==15) update(i+1,msk,dp[i][j]);
            int msk2=0;
            if (i+3<=n) {
                msk2=(1<<12)-1;
                update(i+1,msk2,dp[i][j]+a[4]);
            }
            msk=j;
            if (i+2<=n) {
                msk2=msk;
                msk2|=7;
                msk2|=16;
                msk2|=32;
                msk2|=64;
                msk2|=(1<<8);
                msk2|=(1<<9);
                msk2|=(1<<10);
                update(i,msk2,dp[i][j]+a[3]);
                msk2=msk;
                msk2|=2;
                msk2|=4;
                msk2|=8;
                msk2|=32;
                msk2|=64;
                msk2|=128;
                msk2|=(1<<9);
                msk2|=(1<<10);
                msk2|=(1<<11);
                update(i,msk2,dp[i][j]+a[3]);
            }
            if (i+1<=n) {
                msk2=msk;
                msk2|=1;
                msk2|=2;
                msk2|=16;
                msk2|=32;
                update(i,msk2,dp[i][j]+a[2]);
                msk2=msk;
                msk2|=2;
                msk2|=4;
                msk2|=32;
                msk2|=64;
                update(i,msk2,dp[i][j]+a[2]);
                msk2=msk;
                msk2|=4;
                msk2|=8;
                msk2|=64;
                msk2|=128;
                update(i,msk2,dp[i][j]+a[2]);
            }
            msk2=msk;
            msk2|=1;
            update(i,msk2,dp[i][j]+a[1]);
            msk2=(msk|2);
            update(i,msk2,dp[i][j]+a[1]);
            msk2=(msk|4);
            update(i,msk2,dp[i][j]+a[1]);
            msk2=(msk|8);
            update(i,msk2,dp[i][j]+a[1]);
        }
    }
    cout<<dp[n+1][0];
}