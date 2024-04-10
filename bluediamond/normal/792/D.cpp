#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll n,lg;
ll q;

inline ll gt(ll x) {
    if(x==0LL) {
        return -1LL;
    }
    ll ans=0;
    while(x%2==0) {
        x/=2;
        ans++;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    lg=log2(n+1);
    for(ll i=1;i<=q;i++) {
        ll x;
        cin>>x;
        ll cate=gt(x);
        string a;
        cin>>a;
        for(auto itr:a) {
            cate=gt(x);
            if(itr=='U') {
                if(cate==lg-1) {
                    continue;
                }
                ll a=x+(1LL<<cate);
                ll b=x-(1LL<<cate);
                if(gt(a)==cate+1) {
                    x=a;
                }
                else {
                    x=b;
                }
                continue;
            }
            if(itr=='L') {
                cate--;
                if(cate>=0) {
                    x-=(1LL<<cate);
                }
            }
            else {
                cate--;
                if(cate>=0) {
                    x+=(1LL<<cate);
                }
            }
        }
        cout<<x<<"\n";
    }
    return 0;
}