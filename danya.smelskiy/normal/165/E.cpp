#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000001];
int dp[(1<<22)+10];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=0;i<(1<<22);++i)
        dp[i]=-1;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        dp[a[i]]=a[i];
    }
    for (int i=1;i<=22;++i) {
        for (int j=0;j<(1<<22);++j) {
            if (j&(1<<(i-1))) {
                dp[j]=max(dp[j],dp[j^(1<<(i-1))]);
            }
        }
    }
    for (int i=1;i<=n;++i) {
        int x=a[i];
        x=x^((1<<(22))-1);
        cout<<dp[x]<<" ";
    }
}