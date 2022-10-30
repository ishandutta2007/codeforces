#include <bits/stdc++.h>
using namespace std;

int n;
string s;
long long dp[40][40][40];
pair<int,int> pred[40][40][40];
long long f[100];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>s;
    for (int i=0;i<=n+n;++i)
        for (int j=0;j<=n;++j)
            for (int k=0;k<=n;++k)
                dp[i][j][k]=-1;
    dp[0][0][0]=0;
    f[n-1]=1;
    for (int i=n-2;i>=0;--i)
        f[i]=f[i+1]*10ll;
    for (int i=0;i<n+n;++i)
        for (int j=0;j<=n;++j)
            for (int k=0;k<=n;++k)
    if (dp[i][j][k]>-1) {
        long long res;
        if (j<n) {
            res=dp[i][j][k]+f[j]*(long long)(s[i]-'0');
            if (res>dp[i+1][j+1][k]) {
                dp[i+1][j+1][k]=res;
                pred[i+1][j+1][k]=make_pair(j,k);
            }
        }
        if (k<n) {
            res=dp[i][j][k]+f[k]*(long long)(s[i]-'0');
            if (res>dp[i+1][j][k+1]) {
                dp[i+1][j][k+1]=res;
                pred[i+1][j][k+1]=make_pair(j,k);
            }
        }
    }
    int x=n;
    int y=n;
    string ans="";
    for (int i=n+n;i>0;--i) {
        pair<int,int> q=pred[i][x][y];
        if (q.first==x-1) {
            ans+="H";
            --x;
        } else {
            ans+="M";
            --y;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
}