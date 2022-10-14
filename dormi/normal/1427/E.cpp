#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
pll EEA(ll a, ll b) {
    ll s=0,olds=1,r=b,oldr=a;
    while(r!=0){
        ll q=oldr/r;
        ll te=r;
        r=oldr-q*r;
        oldr=te;
        te=s;
        s=olds-q*s;
        olds=te;
    }
    ll bezt;
    if(b!=0){
        bezt=(oldr-olds*a)/b;
    }
    else bezt=0;
    return {olds,bezt};
}
vector<pair<bool,pll>> ops;
void make(ll a, ll b){
    ll cur=0;
    if(b&ll(1)){
        cur=a;
    }
    ll sum=a;
    for(ll i=2;i<=b;i<<=ll(1)){
        ops.push_back({0,{sum,sum}});
        sum=sum+sum;
        if(b&i){
            if(cur>0){
                ops.push_back({0,{cur,sum}});
            }
            cur+=sum;
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll a;
    cin>>a;
    ops.push_back({1,{a,a}});
    for (ll k = 1;; k ++) {
        if (__gcd(a, a ^ (2LL * a * k)) == 1 && (a ^ (2LL * a * k)) != 0) {
            ll x = a, y = a ^(2LL * a * k);
            make(a,2LL*k);
            ops.push_back({1,{a,(2LL * a * k)}});
            ll xc, yc;
            pll te=EEA(x, y);
            xc=te.first,yc=te.second;
            make(x,abs(xc)),make(y,abs(yc));
            if(xc<=0)swap(x,y),swap(xc,yc);
            if(xc%ll(2)==0){
                if(xc!=0)ops.push_back({0,{a,x*abs(xc)}});
                if(yc!=0)ops.push_back({0,{a,y*abs(yc)}});
                ops.push_back({1,{a+x*abs(xc),a+y*abs(yc)}});
            }
            else{
                ops.push_back({1,{x*abs(xc),y*abs(yc)}});
            }
            printf("%d\n",sz(ops));
            for(auto top:ops){
                if(top.first==0)printf("%lli + %lli\n",top.second.first,top.second.second);
                else printf("%lli ^ %lli\n",top.second.first,top.second.second);
            }
            return 0;
        }
    }
}