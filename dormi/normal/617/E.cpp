#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e5+1;
const int MAXV=2e6+1;
int arr[MAXN];
ll valam[MAXV];
pair<pii,int> query[MAXN];
ll tp[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q,k;
    cin>>n>>q>>k;
    for(int i=1;i<=n;i++)cin>>arr[i],arr[i]^=arr[i-1];
    int bs=sqrt(n);
    for(int i=0;i<q;i++)cin>>query[i].first.first>>query[i].first.second,query[i].first.first--,query[i].second=i;
    sort(query,query+q,[&](auto lhs, auto rhs){
       if(lhs.first.first/bs==rhs.first.first/bs)return lhs.first.second<rhs.first.second;
       return lhs.first.first/bs<rhs.first.first/bs;
    });
    int l=0,r=-1;
    ll ans=0;
    for(int i=0;i<q;i++){
        while(r<query[i].first.second){
            r++;
            ans+=valam[k^arr[r]];
            valam[arr[r]]++;
        }
        while(l<query[i].first.first){
            valam[arr[l]]--;
            ans-=valam[k^arr[l]];
            l++;
        }
        while(l>query[i].first.first){
            l--;
            ans+=valam[k^arr[l]];
            valam[arr[l]]++;
        }
        while(r>query[i].first.second){
            valam[arr[r]]--;
            ans-=valam[k^arr[r]];
            r--;
        }
        tp[query[i].second]=ans;
    }
    for(int i=0;i<q;i++)printf("%lli\n",tp[i]);
    return 0;
}