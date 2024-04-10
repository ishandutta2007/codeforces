#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
const ll mod=1e9+7;
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
ll fact[MN],inv[MN];
ll perm(ll a, ll b){
    return fact[a]*inv[a-b]%mod;
}
int loc[MN];
int arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    fact[0]=inv[0]=1;
    for(int i=1;i<MN;i++){
        fact[i]=fact[i-1]*ll(i)%mod;
        inv[i]=fp(fact[i],mod-2)%mod;
    }
    while(t--){
        int n;
        cin>>n;
        set<int> notfound;
        notfound.insert(n);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            loc[arr[i]]=i;
            notfound.insert(arr[i]);
        }
        ll ans=1;
        int l=loc[0],r=loc[0];
        notfound.erase(0);
        while(l!=1||r!=n){
            int nextnum=*notfound.begin();
            int nextloc=loc[nextnum];
            while(l>nextloc){
                l--;
                notfound.erase(arr[l]);
            }
            while(r<nextloc){
                r++;
                notfound.erase(arr[r]);
            }
            int curnum=*notfound.begin();
            int num=curnum-nextnum-1;
            ans=ans*perm(r-l+1-(nextnum+1),num)%mod;
        }
        printf("%lli\n",ans);
    }
    return 0;
}