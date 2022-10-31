#include <bits/stdc++.h>
using namespace std;
int q,k;
long double dp[10005];
int ans[10005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>k>>q;
    dp[0]=1;
    int last=1;
    for (int i=1;last<=1000;++i) {
        for (int j=k;j>0;--j) {
            dp[j]=(dp[j]*(long double)j+dp[j-1]*((long double)k-j+1))/k;
        }
        if (i==1) dp[0]=0;
        while (last<=1000 && dp[k]>=(long double)(last)/(long double)(2000)) {
            ans[last]=i;
            ++last;
        }
    }
    for (int i=1;i<=q;++i){
        int x;
        cin>>x;
        cout<<ans[x]<<'\n';
    }
}