#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
    #ifdef LOCAL_RUN
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int T; cin >> T; while(T--){
    #else
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    #endif // LOCAL_RUN
    int n;
    cin >> n;
    vector<ll> a(n);
    for(auto &e:a) cin >> e, --e;
    vector<ll> m(n), q(n);
    ll s=0, cur=0;

    for(int i=0;i<n;++i){
        cur+= abs(a[i]-i);
        if(a[i]<=i){
            --s;
        } else {
            ++s;
        }
        m[(i-a[i]+n)%n]+=2;
        m[i]-=2;
        q[i]+=(abs(n - a[i])) - abs(0 - a[i]);
    }
    pair<ll, ll> ans(1e15, -1);
    for(int i=0;i<n;++i){
        if(ans > make_pair(cur, (ll)i)){
            ans = make_pair(cur, (ll)i);
        }
        //cerr << "cur: " << cur << ", s: " << s;
        //cerr << ", m: " << m[i] << ", q: " << q[i];
        //cerr << "\n";
        s+=m[i];
        cur+=s;
        cur+=q[i];
    }
    cout << ans.first << " " << (n-ans.second)%n << "\n";

    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}