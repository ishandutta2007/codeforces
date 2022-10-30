#include <bits/stdc++.h>
using namespace std;


int n,m;
long long kk,dp[500][500];
int pos[100000];
int mn[100000];
char s[100000];
inline bool cmp(int a,int b){
    return mn[a]<mn[b];
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>kk;
    for (int i=1;i<=n+m-1;++i) {
        mn[i]=1e9;
        pos[i]=i;
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            int x; cin>>x;
            mn[i+j-1]=min(mn[i+j-1],x);
        }
    }
    sort(pos+1,pos+n+m,cmp);
    for (int i=1;i<=n+m-1;++i) {
        s[pos[i]]='(';
        for (int j=0;j<=n+m;++j)
        for (int k=0;k<=j+1;++k)
            dp[j][k]=0;
        dp[0][0]=1;
        for (int j=0;j<n+m-1;++j) {
            for (int k=0;k<=j;++k) {
                dp[j][k]=min(dp[j][k],kk);
                if (s[j+1]!=')') dp[j+1][k+1]+=dp[j][k];
                if (s[j+1]!='(' && k) dp[j+1][k-1]+=dp[j][k];
            }
        }
        if (dp[n+m-1][0]<kk) {
            kk-=dp[n+m-1][0];
            s[pos[i]]=')';
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j)
            cout<<s[i+j-1];
        cout<<'\n';
    }
}