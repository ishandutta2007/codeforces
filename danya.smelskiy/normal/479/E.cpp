#include <bits/stdc++.h>
using namespace std;
const int md=1e9+7;
int n,a,b,k;
long long dp[2][5005];
int ans;
long long p[50005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>a>>b>>k;
    int x=0,y=1;
    dp[0][a]=1;
    for (int i=1;i<=k;++i) {
        swap(x,y);
        for (int j=1;j<=n;++j) {
            if (abs(j-b)<=1) continue;
            int len=abs(j-b)-1;
            p[j+1]=(p[j+1]+dp[y][j]);
            p[min(n+1,j+len+1)]-=dp[y][j];
            p[max(1,j-len)]=(p[max(1,j-len)]+dp[y][j]);
            p[j]-=dp[y][j];
        }
        long long last=0;
        for (int j=1;j<=n;++j) {
            last+=p[j];
            p[j]=0;
            dp[x][j]=(last%md);
            dp[y][j]=0;
        }
    }
    for (int i=1;i<=n;++i)
        ans = (ans + dp[x][i]) % md;
    cout<<ans;
}