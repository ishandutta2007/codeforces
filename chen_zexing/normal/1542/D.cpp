#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
using namespace std;
int a[505];
long long mod=998244353;
long long c[505][505],fac[505],dp[505][1005],pre[505][505];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            char c='?';
            while(c!='-'&&c!='+') scanf("%c",&c);
            if(c=='+') scanf("%d",&a[i]);
        }
        c[0][0]=c[1][0]=c[1][1]=1;
        for(int i=2;i<=n;i++) {
            c[i][0]=1;
            for (int j=1;j<=i;j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
        fac[0]=1;
        for(int i=1;i<=n;i++) fac[i]=fac[i-1]*2%mod;
        pre[0][0]=0;
        long long ans=0;
        for(int i=1;i<=n;i++){
            if(a[i]) {
                pre[0][0] = 1;
                for (int j = 1; j < i; j++) {
                    for (int k = 0; k <= n; k++) pre[j][k] = pre[j - 1][k];
                    if (a[j] == 0) {
                        pre[j][0] += pre[j - 1][0], pre[j][0] %= mod;
                        for (int k = 0; k < n; k++) pre[j][k] += pre[j - 1][k + 1], pre[j][k] %= mod;
                    }
                    else if (a[j] < a[i]) {
                        for (int k = 1; k <= n; k++) pre[j][k] += pre[j - 1][k - 1], pre[j][k] %= mod;
                    }
                    else for(int k=0;k<=n;k++) pre[j][k]+=pre[j-1][k],pre[j][k]%=mod;
                }
                for(int j=0;j<=n;j++) pre[i][j]=pre[i-1][j];
                for(int j=i+1;j<=n;j++){
                    for(int k=0;k<=n;k++) pre[j][k]=pre[j-1][k];
                    if(a[j]==0){
                        for(int k=0;k<n;k++) pre[j][k]+=pre[j-1][k+1],pre[j][k]%=mod;
                    }
                    else if(a[j]<=a[i]){
                        for(int k=1;k<=n;k++) pre[j][k]+=pre[j-1][k-1],pre[j][k]%=mod;
                    }
                    else for(int k=0;k<=n;k++) pre[j][k]+=pre[j-1][k],pre[j][k]%=mod;
                }
                for(int j=0;j<=n;j++) ans+=pre[n][j]*a[i]%mod,ans%=mod;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//