#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i<(b); ++i)
#define per(i,a,b) for(int i=a; i>=(b); --i)
#define ll long long
#define int ll
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define sz(a) ((int)a.size())
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 777771449
#endif

const int maxn=105,mod=1000000007;
//a * p.first + b * p.second = gcd(a, b)
pair<ll,ll> extgcd(ll a, ll b){
    pair<ll,ll> res;
    if(a < 0){
        res = extgcd(-a, b);
        res.first *= -1;
        return res;
    }
    if(b < 0){
        res = extgcd(a, -b);
        res.second *= -1;
        return res;
    }
    if(b == 0) return {1, 0};
    res = extgcd(b, a % b);
    return {res.second, res.first - res.second * (a / b)};
}
ll topos(ll x, ll m){x %= m; if(x < 0) x += m; return x;}
//min value of ax + b (mod m) for x \in [0, n - 1]. O(log m)
ll min_rem(ll n, ll m, ll a, ll b){
    a = topos(a, m), b = topos(b, m);
    for(ll g = __gcd(a, m); g > 1;) return g * min_rem(n, m/g, a/g, b/g) + (b % g);
    for(ll nn, nm, na, nb; a; n = nn, m = nm, a = na, b = nb){
        //cout << n << ' ' << m << ' ' << a << ' ' << b << "\n";
        if(a <= m - a){
            nn = (a * (n - 1) + b) / m;
            if(!nn) break;
            nn += (b < a);
            nm = a, na = topos(-m, a);
            nb = b < a ? b : topos(b - m, a);
        }else{
            ll lst = b - (n - 1) * (m - a);
            if(lst >= 0){b = lst; break;}
            nn = -(lst / m) + (lst % m < -a) + 1;
            nm = m - a, na = m % (m - a), nb = b % (m - a);
        }
    }
    return b;
}

//min value of ax + b (mod m) for x \in [0, n - 1], also return min x to get the value. O(log m)
//{value, x}
pair<ll,ll> min_rem_pos(ll n, ll m, ll a, ll b){
    a = topos(a, m), b = topos(b, m);
    ll mn = min_rem(n, m, a, b), g = __gcd(a, m);
    //ax = (mn - b) (mod m)
    ll x = (extgcd(a, m).first + m) * ((mn - b + m) / g) % (m / g);
    return {mn, x};
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a,b,p,q;
        cin >> a >> b >> p >> q;
        pii p1=min_rem_pos(b-a+1,q,p,p*a-(q+1)/2),p2=min_rem_pos(b-a+1,q,-p,-(p*a)+q/2);
        cout << min(p1,p2).second+a << "\n";
    }
}