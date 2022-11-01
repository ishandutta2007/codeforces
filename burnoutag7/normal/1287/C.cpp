#include<bits/stdc++.h>
using namespace std;

int dp[105][105];

int DP(int *w,int *v,int n,int wt){
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=0;j<=wt;j++){
            if(j>=w[i])dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    int res=0;
    for(int i=0;i<=wt;i++)res=max(res,dp[n][i]);
    return res;
}

int n,tot[2],ans;
int p[105],a[105];
int w[2][105],v[2][105],cnt[2],sum[2];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    tot[1]=tot[0]=n>>1;
    if(n&1)tot[1]++;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        a[i]=p[i]&1;
        if(!p[i])continue;
        if(a[i])tot[1]--;
        else tot[0]--;
    }

    int st=1;while(p[st]==0&&st<=n)st++;
    if(st==n+1){
        cout<<1<<endl;
        return 0;
    }
    int ed=n;while(p[ed]==0&&ed>0)ed--;

    cnt[a[st]]++;
    sum[a[st]]++;
    w[a[st]][cnt[a[st]]]=st-1;
    v[a[st]][cnt[a[st]]]=1;
    cnt[a[ed]]++;
    sum[a[ed]]++;
    w[a[ed]][cnt[a[ed]]]=n-ed;
    v[a[ed]][cnt[a[ed]]]=1;

    int pre=st;
    for(int i=st+1;i<=ed;i++){
        if(p[i]==0)continue;
        if(a[i]!=a[pre]){
            ans++;
            pre=i;
            continue;
        }
        if(a[i]==a[pre]){
            cnt[a[i]]++;
            sum[a[i]]+=2;
            w[a[i]][cnt[a[i]]]=i-pre-1;
            v[a[i]][cnt[a[i]]]=2;
            pre=i;
        }
    }
    assert(pre==ed);

    ans+=sum[1]-DP(w[1],v[1],cnt[1],tot[1]);
    ans+=sum[0]-DP(w[0],v[0],cnt[0],tot[0]);

    cout<<ans<<endl;

    return 0;
}