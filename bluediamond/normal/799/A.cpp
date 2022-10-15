#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll need;
ll wait1;
ll add;
ll wait2;

ll cnt2(ll t) {
    if(t<=wait2) {
        return (t/wait1)*add;
    }
    ll ans=(t/wait1)*add;
    ans+=((t-wait2)/wait1)*add;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>need>>wait1>>add>>wait2;
    ll t1=wait1*((need+add-1)/add);
    ll r=0,pas=(1<<30);
    while(pas) {
        if(cnt2(r+pas)<need) {
            r+=pas;
        }
        pas/=2;
    }
    r++;
    ll t2=r;
    if(t2<t1) {
        cout<<"YES\n";
    }
    else {
        cout<<"NO\n";
    }
    return 0;
}
/**

**/