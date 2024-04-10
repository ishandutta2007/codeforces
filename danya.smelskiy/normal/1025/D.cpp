#include <bits/stdc++.h>
#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;


int n;
int a[806];
bool dp[806][806][2];
int j;
bool used[806][806];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            if (__gcd(a[i],a[j])>1) used[i][j]=true;
    for (int len=1;len<=n;++len) {
        for (int i=1;i<=n-len+1;++i) {
            j=i+len-1;
            for (int k=i;k<=j;++k) {
                if (i>1 && used[i-1][k] && (k==i || dp[i][k-1][1]) && (k==j || dp[k+1][j][0])) dp[i][j][0]=true;
                if (i<n && used[j+1][k] && (k==i || dp[i][k-1][1]) && (k==j || dp[k+1][j][0])) dp[i][j][1]=true;
            }
        }
    }
    for (int i=1;i<=n;++i)
    if ((i==1 || dp[1][i-1][1]) && (i==n || dp[i+1][n][0])) {
        cout<<"Yes";
        return 0;
    }
    cout<<"No";
}