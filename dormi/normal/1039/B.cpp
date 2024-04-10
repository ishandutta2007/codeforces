#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
int cnt=0;
bool query(ll l, ll r){
    printf("%lli %lli\n",l,r);
    cnt++;
    assert(cnt<=4500);
    string in;
    cin>>in;
    if(l==r&&in=="Yes")exit(0);
    if(in=="Bad")assert(0);
    return in=="Yes";
}
int main(){
    setbuf(stdout,NULL);
    ll n,k;
    cin>>n>>k;
    ll lo=1,hi=n;
    random_device rd;
    mt19937 gen(rd());
    while(1){
        while(1){
            ll mid=(lo+hi)/2;
            if(max(min(n,mid+k)-max(ll(1),lo-k)+1,min(n,hi+k)-max(ll(1),mid+1-k)+1)>=(hi-lo+1))break;
            if(query(lo,mid))lo=max(ll(1),lo-k),hi=min(n,mid+k);
            else lo=max(ll(1),mid+1-k),hi=min(n,hi+k);
        }
        uniform_int_distribution<ll> dis(lo, hi);
        ll poi=dis(gen);
        query(poi,poi);
        lo=max(ll(1),lo-k),hi=min(n,hi+k);
    }
    return 0;
}