#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;
const int precLen=200000;

ll qpow(ll a,ll n){
    ll res=1;
    while(n){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int fact[precLen+5],inv[precLen+5];

ll C(int n,int r){
    if(n<r||r<0)return 0;
    return (ll)fact[n]*inv[n-r]%mod*inv[r]%mod;
}

void initialization(){
    fact[0]=1;
    for(int i=1;i<=precLen;i++){
        fact[i]=(ll)fact[i-1]*i%mod;
    }
    inv[precLen]=qpow(fact[precLen],mod-2);
    for(int i=precLen-1;i>=0;i--){
        inv[i]=(ll)inv[i+1]*(i+1)%mod;
    }
}

int n,a[200005];

void mian(){
    cin>>n;
    int mx=-1,smx=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>mx){
            smx=mx;
            mx=a[i];
        }else{
            smx=max(smx,a[i]);
        }
    }
    if(mx==smx){
        cout<<fact[n]<<'\n';
    }else if(mx-1>smx){
        cout<<"0\n";
    }else{
        int cnt=0;
        for(int i=1;i<=n;i++){
            cnt+=a[i]==smx;
        }
        int ans=fact[n];
        for(int i=cnt+1;i<=n;i++){
            ans=(ans-(ll)fact[i-1]*inv[i-1-cnt]%mod*fact[n-1-cnt]%mod+mod)%mod;
        }
        cout<<ans<<'\n';
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    initialization();

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}