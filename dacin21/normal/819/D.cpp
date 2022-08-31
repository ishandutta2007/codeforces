#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// returns d = gcd(a,b); finds x,y such that d = ax + by
ll extended_euclid(ll a, ll b, ll &x, ll &y) {
  ll xx = y = 0;
  ll yy = x = 1;
  while (b) {
    ll q = a/b;
    ll t = b; b = a%b; a = t;
    t = xx; xx = x-q*xx; x = t;
    t = yy; yy = y-q*yy; y = t;
  }
  return a;
}

ll inv(ll x, ll mod){
    ll a, b;
    ll g = extended_euclid(mod, x, b, a);
    assert(g==1);
    return (a%mod+mod)%mod;
}

signed main()
{
    #ifdef LOCAL_RUN
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int TTT; cin >> TTT; while(TTT--){
    #else
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    #endif
    ll T; int n;
    cin >> T >> n;
    vector<ll> a(n), t(n);
    for(auto &e:a) cin >> e;
    for(int i=1;i<n;++i){
        t[i] = t[i-1] + a[i];
    }
    ll per = t[n-1] + a[0];
    ll g = __gcd(T, per);
    ll shiftsize = T/g;
    ll stepsize = per % T / g;
    ll istep = inv(stepsize, shiftsize);
    map<int, map<ll, int> > v;
    for(int i=0;i<n;++i){
        ll a = t[i] % g;
        ll b = t[i] / g % shiftsize;
        if(!(v[a].count(b))){
            v[a][b] = i;
        }
    }
    vector<ll> ans(n, 0);
    for(auto const&ee:v){
		auto const&e = ee.second;
        vector<pair<ll, int> > ev;
        for(auto const&f:e){
            ev.emplace_back(istep*f.first%shiftsize, f.second);
        }
        if(ev.empty()) continue;
        sort(ev.begin(), ev.end());
        int last = ev.back().second;
        ll lastt = ev.back().first - shiftsize;
        for(auto const&f:ev){
            ans[last]+=f.first-lastt;
            lastt = f.first;
            last = f.second;
        }
        //ans[last]+=shiftsize-lastt;
    }
    for(int i=0;i<n;++i){
        cout << ans[i] << " ";
    }


    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}