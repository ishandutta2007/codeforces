#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long dp[105][105];
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (long long i=1;i<=m;++i)
    for (long long j=1;j<=m;++j) {
        dp[i][j]=abs((m+1)/2-i)+abs((m+1)/2-j);
        dp[i][j]+=dp[i][j-1];
    }
    for (long long i=1;i<=n;++i) {
        long long ans=1e14;
        long long posx=0,posy=0;
        long long x;
        cin>>x;
        if (x>m) {
            cout<<"-1"<<'\n';
            continue;
        }
        for (long long i=1;i<=m;++i) {
            for (long long j=1;j<=m-x+1;++j){
                if (dp[i][j+x-1]-dp[i][j-1]<ans) {
                    posx=i;
                    posy=j;
                    ans=dp[i][j+x-1]-dp[i][j-1];
                }
            }
        }
        if (ans==1e14) {
            cout<<"-1"<<'\n';
            continue;
        }
        cout<<posx<<" "<<posy<<" "<<posy+x-1<<'\n';
        for (int i=m;i>=posy;--i)
            dp[posx][i]=dp[posx][i]-dp[posx][i-1];
        for (int i=posy;i<=m;++i) {
            if (i<=posy+x-1) dp[posx][i]=1e15;
            dp[posx][i]+=dp[posx][i-1];
        }
    }

}