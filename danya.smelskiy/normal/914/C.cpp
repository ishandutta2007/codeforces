#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;

string s;
int n;
bool used[2005];
long long ans;

long long dp2[2005];
long long dp3[2005][2005];
long long dp4[2005][2005][2];
int dp[2005];

int dfs(int x) {
    if (used[x]) return dp[x];
    used[x]=true;
    int kol=0;
    int j=x;
    while (j) {
        if (j&1) ++kol;
        j>>=1;
    }
    return dp[x]=dfs(kol)+1;
}


void solve1(int len) {
    if (!len) return;
    memset(dp3,0,sizeof(dp3));
    dp3[1][1]=1;
    ++dp2[1];
    if (dp2[1]>=md) dp2[1]-=md;
    for (int i=2;i<=len;++i) {
        for (int j=1;j<=i;++j) {
            dp3[i][j]=dp3[i-1][j];
            dp3[i][j]+=dp3[i-1][j-1];
            if (dp3[i][j]>=md) dp3[i][j]-=md;
            dp2[j]+=dp3[i][j];
            if (dp2[j]>=md) dp2[j]-=md;
        }
    }
}


void solve2(int len,string s) {
    memset(dp4,0,sizeof(dp4));
    dp4[1][1][0]=1;
    for (int i=1;i<len;++i) {
        for (int j=1;j<=i;++j) {
            for (int k=0;k<2;++k) if (dp4[i][j][k]) {
                if (k==1) {
                    dp4[i+1][j+1][k]+=dp4[i][j][k];
                    if (dp4[i+1][j+1][k]>=md) dp4[i+1][j+1][k]-=md;
                    dp4[i+1][j][k]+=dp4[i][j][k];
                    if (dp4[i+1][j][k]>=md) dp4[i+1][j][k]-=md;
                } else {
                    int x=s[i]-'0';
                    if (x==0) {
                        dp4[i+1][j][k]+=dp4[i][j][k];
                        if (dp4[i+1][j][k]>=md) dp4[i+1][j][k]-=md;
                    } else {
                        dp4[i+1][j][1]+=dp4[i][j][k];
                        if (dp4[i+1][j][1]>=md) dp4[i+1][j][1]-=md;
                        dp4[i+1][j+1][k]+=dp4[i][j][k];
                        if (dp4[i+1][j+1][k]>=md) dp4[i+1][j+1][k]-=md;
                    }
                }
            }
        }
    }
    for (int i=1;i<=len;++i) {
        dp2[i]+=dp4[len][i][0];
        dp2[i]%=md;
        dp2[i]+=dp4[len][i][1];
        dp2[i]%=md;
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    cin>>n;
    if (n==0) {
        cout<<1;
        return 0;
    }
    used[1]=true;
    for (int i=2;i<=2000;++i)
        if (used[i]==false) dfs(i);
    solve1(s.size()-1);
    solve2(s.size(),s);
    --dp2[1];
    for (int i=1;i<=2000;++i)
        if (dp[i]==n-1) {
            ans=(ans+dp2[i])%md;
        }
    cout<<ans;
}