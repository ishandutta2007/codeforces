#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const ll mod=998244353;
const int MN=3e5+1;
ll fact[MN],inv[MN];
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
ll choose(ll a, ll b){
    return fact[a]*inv[b]%mod*inv[a-b]%mod;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    fact[0]=inv[0]=1;
    for(int i=1;i<MN;i++){
        fact[i]=fact[i-1]*ll(i)%mod;
        inv[i]=fp(fact[i],mod-2);
    }
    while(t--){
        int n;
        cin>>n;
        string a;
        cin>>a;
        bool last=false;
        int cnt=0,acnt=0;
        for(int i=0;i<n;i++){
            if(a[i]=='1')acnt++;
            if(a[i]=='1'&&last){
                cnt++;
                last=false;
            }
            else if(a[i]=='1')last=true;
            else last=false;
        }
        int positions=cnt;
        int nums=n-(acnt-2*cnt)-2*cnt+1;
        printf("%lli\n",choose(positions+nums-1,nums-1));
    }
    return 0;
}