/*
 * @Author: BilyHurington
 * @Date: 2021-02-28 21:50:36
 * @LastEditors: BilyHurington
 * @LastEditTime: 2021-02-28 22:11:59
 */
#include<bits/stdc++.h>
using namespace std;
int T,n,S[5010];
long long f[5010];
void solve(){
    scanf("%d",&n);f[n+1]=0;
    for(int i=1;i<=n;i++) scanf("%d",&S[i]),f[i]=0;
    for(int i=1;i<n;i++){
        if(S[i]-1<f[i]) f[i+1]+=(f[i]-(S[i]-1));
        f[n+1]+=max(0,S[i]-(n-i));
        S[i]=min(S[i],n-i);
        for(int j=2;j<=S[i];j++) f[i+j]++;f[i]=0;
        // for(int j=1;j<=n+1;j++) printf("%lld ",f[j]);puts("");
    }
    printf("%lld\n",f[n+1]+max(S[n]-1ll,f[n]));
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}