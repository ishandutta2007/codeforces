#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m;
int a[500005],b[500005],p[500005],rev[500005],prv[500005];
ll bit[500005],cost[500005],ans,dp[500005];

ll sum(int pos){
    ll res=0;
    while(pos>0){
        res+=bit[pos];
        pos-=pos&-pos;
    }
    return res;
}

void add(int pos,ll val){
    while(pos<=n){
        bit[pos]+=val;
        pos+=pos&-pos;
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>b[i];
        rev[b[i]]=i;
        prv[b[i]]=b[i-1];
    }
    for(int i=1;i<=n;i++){
        cost[i]=sum(a[i])-sum(prv[a[i]]);
        if(p[i]<0){
            ans+=p[i];
            cost[i]-=p[i];
        }else{
            add(a[i],p[i]);
        }
    }
    ans+=sum(n)-sum(b[m]);
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=n;i++){
        dp[rev[a[i]]]=min(dp[rev[a[i]]],dp[rev[a[i]]-1]+cost[i]);
    }
    ans+=dp[m];
    if(ans>=(ll)1e18)cout<<"NO"<<endl;
    else cout<<"YES"<<endl<<ans<<endl;

    return 0;
}