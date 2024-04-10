#include<bits/stdc++.h>
using namespace std;
const int N=500005;
const int MOD=998244353;
int add(int x,int y){x+=y; return x>=MOD ? x-MOD : x;}
int mul(int x,int y){return 1ll*x*y%MOD;}
int sub(int x,int y){x-=y; return x<0 ? x+MOD : x;}
int n,k,m,dp[N];
int L[N],R[N],X[N],a[N],pre[N];
int v[N];

int ans=1;
void solve(){
    for(int i=1;i<=n;i++) v[i]=0,pre[i]=0,dp[i]=0;
    for(int i=1;i<=m;i++){
        if(a[i]==1) pre[L[i]]++, pre[R[i]+1]--;
        else v[R[i]]=max(v[R[i]],L[i]);
    }
    for(int i=1;i<=n;i++) pre[i]=add(pre[i],pre[i-1]);
    dp[0]=1; int sum=1,now=0;
    for(int i=1;i<=n;i++){
        if(!pre[i]) dp[i]=sum, sum=add(sum,dp[i]);
        if(v[i]>0) while(now<v[i]) sum=sub(sum,dp[now]), dp[now++]=0;
    }
    int S=0;
    for(int i=0;i<=n;i++) S=add(S,dp[i]); 
    ans=mul(ans,S);
}

int main(){
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<=m;i++) scanf("%d%d%d",&L[i],&R[i],&X[i]);
    for(int bit=0;bit<k;bit++){
        for(int i=1;i<=m;i++) a[i]=(X[i]>>bit&1);
        solve();
    }
    printf("%d\n",ans);
}