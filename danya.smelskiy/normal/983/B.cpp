#include <bits/stdc++.h>
using namespace std;


int n;
int a[5005];
int dp[5005][5005];
int f[5005][5005];
int x,y;

int get(int l,int r) {
    return f[r-l+1][l];
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   cin>>n;
   for (int i=1;i<=n;++i) {
        cin>>a[i];
        f[1][i]=a[i];
   }
   for (int i=2;i<=n;++i) {
        for (int j=1;j<=n-i+1;++j) {
            f[i][j]=(f[i-1][j]^f[i-1][j+1]);
        }
   }
   for (int i=1;i<=n;++i) {
    for (int j=1;j<=n-i+1;++j) {
        dp[j][j+i-1]=max(get(j,j+i-1),max(dp[j+1][j+i-1],dp[j][j+i-2]));
    }
   }
   cin>>n;
   while (n--) {
        cin>>x>>y;
        cout<<dp[x][y]<<'\n';
   }

}