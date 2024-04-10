// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;

int n;
ll ar[200005];
ll ans=1e18;
set<ll>mem;
void tes(ll x){
    if(x==1)return;
    if(mem.count(x))return;
    mem.insert(x);
    ll tp=0;
    rep(i,n){
        if(ar[i]<=x)tp+=x-ar[i];
        else tp+=min(ar[i]%x,x-(ar[i]%x));
    }
    ans=min(ans,tp);
}
void rn(ll x){
    if(!x)return;
    for(ll i=2;i*i<=x;i++){
        if(x%i)continue;
        tes(i);
        while(x%i==0)x/=i;
    }
    tes(x);
}
mt19937 rng(152149433);
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    rep(i,n)cin>>ar[i];
    tes(2);
    vector<int>order(n);
    rep(i,n)order[i]=i;
    shuffle(all(order),rng);
    rep(lp,min(n,2)){
        rn(ar[order[lp]]-1);
        rn(ar[order[lp]]);rn(ar[order[lp]]+1);
    }
    cout<<ans<<endl;
}