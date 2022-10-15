#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e9;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 100100

ll mod(ll a, ll m){
    a %= m;
    if (a <0)a+=m;
    return a;
}

ll inverse(ll a,ll m){
    a = mod(a,m);
    if (a <= 1)return a;
    return mod((1-inverse(m,a) * m) / a, m);
}

ll gcd(ll a, ll b){
    if (b == 0)return a;
    return gcd(b,a%b);
}

ll N;
ll memo[MAXN];
bitset<MAXN+1> bs;
vi primes;
vi fact[MAXN];
vi normie;

bool cmp(ll a, ll b){
    return SZ(fact[a]) < SZ(fact[b]);
}

int main(){
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    cin >> N;
    ll F = inverse(N,MOD);
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i=2;i*i<=MAXN;++i){
        if (!bs[i])continue;
        for (ll j=i*2;j<=MAXN;j+=i){
            bs[j] = 0;
            fact[j].pb(i);
        }
    }
    for (int i=2;i<=MAXN;++i)if (bs[i])primes.pb(i);
    for (ll i=0;i<SZ(primes)&&primes[i]<=MAXN;++i){
        ll r = N/primes[i];
        memo[primes[i]] = N * inverse(N-r,MOD);
        memo[primes[i]] %= MOD;
    }
    for (int v = 2;v<=N;++v){
        ll tmp = v;
        for (auto i : fact[v]){
            while(tmp % i ==0)tmp /= i;
        }
        if (tmp != 1)fact[v].pb(tmp);
    }
    normie.clear();
    for (ll i=2;i<=N;++i){
        if (bs[i] == 1)continue;
        bool isnorm = 1;
        for (auto v : fact[i]){
            if (i % (v*v) == 0)isnorm = 0;
        }
        if (isnorm)normie.pb(i);
    }
    sort(ALL(normie), cmp);
    ll t = 0;
    for (auto v : normie){
        vpi fct;
        
        ll l = SZ(fact[v]);
        for (ll i=1;i<(1<<l);++i){
            ll k = 0;
            ll m = 1;
            for (ll j=0;j<l;++j){
                if (i & (1<<j)){
                    k++;
                    m*=fact[v][j];
                }
            }
            fct.pb(mp(k,m));
        }
        sort(ALL(fct));
        ll rep = 0;
        for (auto i : fct){
            if (i.s == v)continue;
            ll r = N/i.s;
            for (auto j : fct){
                if (j.s<=i.s||j.s % i.s != 0)continue;
                ll x = j.f - i.f;
                if (x % 2 == 1)r -= N/j.s;
                else r += N/j.s;
            }
            memo[v] += r * memo[i.s];
            memo[v] %= MOD;
            // cout<<i.s<<' '<<r<<'\n';
        }
        ll r = N-N/v;
        memo[v] = memo[v] * F + 1;
        memo[v] %= MOD;
        memo[v] = memo[v] * N;
        memo[v] %= MOD;
        // cout<<memo[v]<<'\n';
        memo[v] = memo[v] * inverse(r, MOD);
        memo[v] %= MOD;
        // cout<<memo[v]<<' ';
    }
    for (ll i=2;i<=N;++i){
        if (memo[i] == 0){
            ll model = 1;
            for (auto v : fact[i])model *= v;
            memo[i] = memo[model];
        }
    }
    t = 0;
    for (ll i=1;i<=N;++i){
        t += memo[i];
        t %= MOD;
    }
    t *= F;
    t %= MOD;
    cout << t+1;
    // for (ll i=2;i<=N;++i)cout<<i<<' '<<memo[i]<<'\n';
}