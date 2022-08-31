#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
const ll inf = 1e17;

signed main(){
    #ifdef LOCAL_RUN
    freopen("inN.txt", "r", stdin);
    #endif // LOCAL_RUN
    cin.tie(0); ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for(auto &e:a) cin >> e;
    for(auto &e:b) cin >> e;
    ll l=0, r = inf/n;
    ll ans = inf;
    while(l+1<r){
        ll m = l+(r-l)/2;
        ll res = 0;
        int hits = 0;
        priority_queue<ll, vector<ll>, greater<ll>> pa;
        priority_queue<ll> pb;
        pb.push(-inf);
        for(int i=0;i<n;++i){
            pa.push(a[i]);
            ll xb = b[i] - pb.top();
            ll xa = b[i] + pa.top() - m;
            if(xb<xa && xb<0){
                //cerr << pb.top() << " -> " << b[i] << "\n";
                res+=xb;
                pb.pop();
                pb.push(b[i]);
            }
            if(xa<=xb && xa<0){
                //cerr <<  " +  " << a[i] << "," << b[i] << "\n";
                res+=xa;
                ++hits;
                pa.pop();
                pb.push(b[i]);
            }
        }
        //cerr << m << ": " << hits << " (" << res << "," <<  res+ m*hits << ")\n";
        if(hits>=k){
            ans = min(ans, res + m*hits);
            r=m;
        } else {
            l=m;
        }
    }
    cout << ans << "\n";
}