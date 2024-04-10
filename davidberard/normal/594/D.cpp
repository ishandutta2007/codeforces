#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

const ll MOD = 1e9+7;
const int CMAX = 1001000;
const int NMAX = 200200;

int sieve[CMAX];
int inv[CMAX];
vector<pii> primes[CMAX];

void setup() {
    for(ll i=2;i<CMAX;++i) {
        if(sieve[i]) continue;
        for(ll j=i*i; j<CMAX; j += i) {
            sieve[j] = i;
        }
    }
    for(int i=2;i<CMAX;++i) {
        if(sieve[i] == 0) {
            primes[i].push_back(pii(i, 1));
        } else {
            primes[i] = primes[i/sieve[i]];
            if(primes[i].back().first != sieve[i]) {
                primes[i].push_back(pii(sieve[i], 1));
            } else {
                primes[i].back().second++;
            }
        }
    }
	inv[1] = 1;
	for (int i=2; i<CMAX; ++i)
		inv[i] = (MOD - (MOD/i) * inv[MOD%i] % MOD) % MOD;
    //cerr << "! " << inv[37] << endl;
}

ll pw(ll v, ll p) {
    ll ans = 1;
    for(int i=0;i<p;++i) {
        ans = (ans*v)%MOD;
    }
    return ans;
}

struct bit {
    vector<ll> t;
    int n;
    bit() {}
    bit(int sz) {
        n = sz;
        t = vector<ll>(n, 1);
    }
    inline int lobit (int i) {
        return i&-i;
    }
    void apply(int i, ll v) {
        if(i == 0) return;
        for(;i < n;i+=lobit(i)) {
            t[i] = (t[i]*v)%MOD;
        }
    }
    ll query(int i) {
        if(i == 0) return 1;
        ll ans = 1;
        for(; i; i-=lobit(i)) {
            ans = (ans*t[i])%MOD;
        }
        return ans;
    }
};

int n, m;
ll a[NMAX];
int pos[CMAX];
vector<vector<int>> query;
ll ans[NMAX];

int main() {
	setup();
    cin >> n;
    for(int i=1;i<=n;++i) {
        cin >> a[i];
    }
    cin >> m;
    for(int i=0;i<m;++i) {
        int l, r;
        cin >> l >> r;
        query.emplace_back(vector<int>({r, l, i}));
    }
    sort(query.begin(), query.end());
    bit b(n+1);
    bit bi(n+1);
    int q = 0;
    int k = 1;
    while(q < m) {
        while(query[q][0] >= k) {
            //cerr << " trying to get primes of " << a[k] << " k = " << k << endl;
            for(auto& pp : primes[a[k]]) {
                int p = pp.first;
                int c = pp.second;
                //cerr << " ! " << p << " " << c << endl;
                if(pos[p]) {
                    b.apply(pos[p], ((ll) inv[p-1]*p)%MOD);
                    bi.apply(pos[p], ((ll) (p-1)*inv[p])%MOD);
                }
                b.apply(k, (p-1)*pw(p, c-1));
                bi.apply(k, inv[p-1]*pw(inv[p], c-1)%MOD);
                pos[p] = k;
            }
            ++k;
            //cerr; for(int j=1;j<k;++j) {
                //cerr << ".. " << j << " " << b.query(j) << " " << bi.query(j) << endl;
            //cerr; }
            //cerr << " -- " << inv[a[k-1]] << endl;
            //cerr << endl;
        }
        ll base = b.query(k-1);
        while(q < m && query[q][0] == k-1) {
            //cerr << "- " << q << " is " << query[q][2] << ": " << base << " " << bi.query(query[q][1]-1) << endl;
            ans[query[q][2]] = (base*bi.query(query[q][1]-1))%MOD;
            ++q;
        }
    }
    for(int i=0;i<m;++i) {
        cout << ans[i] << "\n";
    }
	return 0;
}