#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;

int qpow(ll a,int n){
    ll res=1;
    while(n){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int n,m;
int able[300005],pre[300005][45];
int u[20],v[20],lb[300005],rb[300005];
int frac[300005],inv[300005];

inline int chs(const int &n,const int &r){
    if(n<0||r<0||n-r<0)return 0;
    return (ll)frac[n]*inv[n-r]%mod*inv[r]%mod;
}

inline int get(const int &l,const int &r,const int &x){
    return (pre[r][x]-pre[l-1][x]+mod)%mod;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    frac[0]=inv[0]=1;
    for(int i=1;i<=300000;i++){
        frac[i]=(ll)frac[i-1]*i%mod;
        inv[i]=qpow(frac[i],mod-2);
    }
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int &l=lb[i],&r=rb[i];
        cin>>l>>r;
        able[l]++;
        able[r+1]--;
    }
    for(int i=1;i<=n;i++){
        able[i]+=able[i-1];
        for(int j=0;j<=40;j++){
            pre[i][j]=(pre[i-1][j]+chs(able[i]-j,i-j))%mod;
        }
    }
    for(int i=0;i<m;i++){
        cin>>u[i]>>v[i];
    }
    int ans=0;
    for(int s=0;s<1<<m;s++){
        set<int> t;
        int l=1,r=n;
        for(int i=0;i<m;i++)if(s>>i&1){
            l=max(l,lb[u[i]]);
            l=max(l,lb[v[i]]);
            r=min(r,rb[u[i]]);
            r=min(r,rb[v[i]]);
            t.insert(u[i]);
            t.insert(v[i]);
        }
        if(l>r)continue;
        if(__builtin_popcount(s)&1)ans=(ans-get(l,r,t.size())+mod)%mod;
        else ans=(ans+get(l,r,t.size()))%mod;
    }
    cout<<(ans+mod)%mod<<endl;

    return 0;
}