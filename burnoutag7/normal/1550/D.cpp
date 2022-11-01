#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9+7;
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

int n,lb,rb,ub;

void mian(){
    cin>>n>>lb>>rb;
    map<int,int> ni,pi;
    ub=1e9;
    for(int i=1;i<=n;i++){
        int a,b;
        a=i-lb;
        b=rb-i;
        if(a<b){
            pi[a+1]++;
            ub=min(ub,b+1);
        }else if(b<a){
            ni[b+1]++;
            ub=min(ub,a+1);
        }else ub=min(ub,a+1);
    }
    vector<int> pt(1,1);
    for(auto p:ni)if(p.first<ub)pt.emplace_back(p.first);
    for(auto p:pi)if(p.first<ub)pt.emplace_back(p.first);
    sort(pt.begin(),pt.end());
    pt.erase(unique(pt.begin(),pt.end()),pt.end());
    pt.emplace_back(ub);
    int all,req,pos=0,neg=0,ans=0;
    for(int i=0;i+1<pt.size();i++){
        //calculate [pt[i],pt[i+1])
        pos+=pi[pt[i]];
        neg+=ni[pt[i]];
        all=n-pos-neg;
        req=max(pos,neg)-min(pos,neg);
        if(all+1<req)break;
        if(n&1){
            if(all>req)ans=(ans+(C(all,req+(all-req)/2)+C(all,req+(all-req)/2+1))*(pt[i+1]-pt[i]))%mod;
            else ans=(ans+pt[i+1]-pt[i])%mod;
        }else{
            req=max(pos,neg)-min(pos,neg);
            ans=(ans+C(all,req+(all-req)/2)*(pt[i+1]-pt[i]))%mod;
        }
    }
    cout<<ans<<'\n';
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