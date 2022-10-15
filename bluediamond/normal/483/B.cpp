#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool ok(ll n,ll nevx,ll nevy,ll x,ll y) {
    ll a=n-n/x;
    ll b=n-n/y;
    ll val1=n/x;
    ll val2=n/y;
    ll com=n-(n/(x*y)+val1-val1/y+val2-val2/x);
    a-=com;
    b-=com;
    ll t=min(a,nevx);
    nevx-=t;
    t=min(nevx,com);
    nevx-=t;
    com-=t;
    if(nevx>0) {
        return 0;
    }
    ll lft=com+b;
    if(lft>=nevy) {
        return 1;
    }
    return 0;

}

ll nevx;
ll nevy;
ll x,y;

bool good(ll a) {
    return ok(a,nevx,nevy,x,y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>nevx>>nevy>>x>>y;
    ll r=0,pas=(1LL<<60);
    while(pas) {
        if(good(r+pas)==0) {
            r+=pas;
        }
        pas/=2;
    }
    r++;
    cout<<r<<"\n";
    return 0;
}
/**

1 1
2 3

**/