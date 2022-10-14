#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
const int MV=1e6+1;
int pream[MN];
int sufam[MN+2];
int given[MN];
bool nprime[MV];
int e;
ll solve(vector<int> arr){
    int n=sz(arr)-1;
    pream[0]=0;
    sufam[n+1]=0;
    for(int i=1;i<=n;i++){
        pream[i]=(arr[i]==1?1+pream[i-1]:0);
    }
    for(int i=n;i>=1;i--){
        sufam[i]=(arr[i]==1?1+sufam[i+1]:0);
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(!nprime[arr[i]]){
            ll pre=pream[i-1],suf=sufam[i+1];
            ans+=(suf+1)*(pre+1)-1;
        }
    }
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    nprime[1]=true;
    for(ll i=2;i<MV;i++){
        if(!nprime[i]){
            for(ll j=i*i;j<MV;j+=i){
                nprime[j]=true;
            }
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n>>e;
        for(int i=0;i<n;i++)cin>>given[i];
        ll ans=0;
        for(int i=0;i<e;i++){
            vector<int> touse={0};
            for(int j=i;j<n;j+=e){
                touse.push_back(given[j]);
            }
            ans+=solve(touse);
        }
        printf("%lli\n",ans);
    }
    return 0;
}