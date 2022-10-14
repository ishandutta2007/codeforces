#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int SZ(const T &a){return int(a.size());}
const ll mod=998244353;
const int MN=2e5+1;
int bit[MN];
int n;
void update(int loc, int val){
    for(;loc<=n;loc+=loc&-loc)bit[loc]+=val;
}
int ith(int v){//ith set bit in the bit
    int loc=0;
    for(int i=__lg(n);i>=0;i--){
        if(loc+(1<<i)<=n&&bit[loc+(1<<i)]<v){
            loc+=(1<<i);
            v-=bit[loc];
        }
    }
    return loc+1;
}
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
ll pc[2*MN],inv[2*MN];
ll choose(ll a, ll b){
    return pc[a]*inv[b]%mod*inv[a-b]%mod;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    pc[0]=inv[0]=1;
    n=MN-1;
    for(int i=1;i<2*MN;i++)pc[i]=pc[i-1]*i%mod,inv[i]=fp(pc[i],mod-2);
    for(int i=1;i<MN;i++)update(i,1);
    while(t--){
        int m,a,b;
        cin>>n>>m;
        vector<pii> arr;
        for(int i=0;i<m;i++){
            cin>>a>>b;
            arr.push_back({a,a-b});
        }
        sort(arr.begin(),arr.end());
        reverse(arr.begin(),arr.end());
        set<int> ends;
        vector<int> tofix;
        for(auto x:arr){
            int loc=ith(x.first-x.second+1);
            ends.insert(loc);
            tofix.push_back(ith(x.first-x.second));
            update(tofix.back(),-1);
        }
        int sn=n-SZ(ends)-1;
        int sk=n+1;
        printf("%lli\n",choose(sn+sk-1,sk-1));
        for(auto x:tofix)update(x,1);
    }
    return 0;
}