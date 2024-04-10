#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long kk;
long long dp[55][55][105];
pair<long long,long long> pred[55][55][105];
long long a[55],b[55],c[55];
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>kk;
    for (long long i=1;i<=m;++i) {
        cin>>a[i]>>b[i]>>c[i];
        for (long long j=a[i];j<=b[i];++j)
            dp[0][i][j-a[i]]=j;
    }
    for (long long i=0;i<n-1;++i) {
        for (long long j=1;j<=m;++j)
        for (long long k=0;k<=b[j]-a[j];++k) if (dp[i][j][k]) {
            for (long long z=1;z<=m;++z) if (c[z]>c[j]) {
                long long nxt=a[j]+k;
                if (nxt+kk>=a[z] && nxt+kk<=b[z] && dp[i+1][z][nxt+kk-a[z]]<dp[i][j][k]+nxt+kk) {
                    dp[i+1][z][nxt+kk-a[z]]=dp[i][j][k]+nxt+kk;
                    pred[i+1][z][nxt+kk-a[z]]=make_pair(j,k);
                }
                nxt*=kk;
                if (nxt>=a[z] && nxt<=b[z] && dp[i+1][z][nxt-a[z]]<dp[i][j][k]+nxt) {
                    dp[i+1][z][nxt-a[z]]=dp[i][j][k]+nxt;
                    pred[i+1][z][nxt-a[z]]=make_pair(j,k);
                }
            }
        }
    }
    long long mx=0;
    long long pos1=-1,pos2=-1;
    for (long long i=1;i<=m;++i)
        for (long long j=0;j<=b[i]-a[i];++j)
        if (dp[n-1][i][j]>mx) {
            mx=dp[n-1][i][j];
            pos1=i;
            pos2=j;
        }
    if (pos1==-1) {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<'\n';
    vector<pair<long long,long long> > ans;
    for (long long i=n-1;i>=0;--i) {
        ans.push_back(make_pair(pos1,a[pos1]+pos2));
        long long pos3,pos4;
        pos3=pred[i][pos1][pos2].first;
        pos4=pred[i][pos1][pos2].second;
        pos1=pos3;
        pos2=pos4;
    }
    for (long long i=n-1;i>=0;--i)
        cout<<ans[i].first<<" "<<ans[i].second<<'\n';
}