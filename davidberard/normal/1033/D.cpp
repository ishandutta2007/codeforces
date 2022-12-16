#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const ll MOD = 998244353;
const ll NMAX = 1.5e6;

int sieve[NMAX];
vector<int> primes;
void setup() {
    for(ll i = 2;i<NMAX;++i) {
        if(sieve[i] == 0) {
            for(ll j = i*i;j<NMAX;j+=i) {
                sieve[j] = 1;
            }
            primes.push_back(i);
        }
    }
}

unordered_map<ll, int> factors;

void add_fac(ll x, ll amt) {
    if(factors.count(x) == 0) {
        factors[x] = 0;
    }
    factors[x] += amt;
}

ll find_fac_t(ll x) {
    ////cerr << "FIND FAC_T " << x << endl;
    for(auto& P : primes) {
        ll p = P;
        ////cerr << " try " << p << " as a factor of " << x << ", exit now ? " << (p*p*p > x) << endl;
        if(p*p*p > x) {
            return -1;
        } 
        ////cerr << "x%p = " << x%p << endl;
        if(x%p == 0) {
            return p;
        }
    }
    return -1;
}

ll find_fac(ll x) {
    for(auto& P : primes) {
        ll p = P;
        if(p*p > x) {
            return -1;
        } 
        if(x%p == 0) {
            return p;
        }
    }
    return -1;
}

ll sqt(ll x) {
    ////cerr << "TRY SQT " << x << endl;
    ll mn = 0;
    ll mx = 1.5e9;
    while(mn < mx-1) {
        ll md = (mn+mx)/2;
        if(md*md == x) {
            return md;
        } else if(md*md < x){
            mn = md;
        } else {
            mx = md;
        }
    }
    if(mn*mn == x) return mn;
    if(mx*mx == x) return mx;
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    setup();
    ll  N;
    cin >> N;
    vector<ll> a(N);
    for(auto& x : a) {
        cin >> x;
    }
    vector<ll> unknowns;
    for(int i=0;i<a.size();++i) {
        ll x = a[i];
        ll v, vv;
        if((v = sqt(x)) != -1) {
            vv = sqt(v);
            if(vv != -1) {
                add_fac(vv, 4);
            } else {
                add_fac(v, 2);
            }
        }
        else if((v = find_fac_t(x)) != -1) {
            ////cerr << "!! got fac_t " << v << endl;
            add_fac(v, 1);
            v = x/v;
            if((vv = sqt(v)) != -1) {
                add_fac(vv, 2);
            }
            else if((vv = find_fac(v)) != -1) {
                add_fac(vv, 1);
                add_fac(v/vv, 1);
            } else if((vv = sqt(v)) != -1){
                add_fac(vv, 2);
            } else {
				add_fac(v, 1);
			}
        } else {
            ////cerr << "UNK" << x << endl;
            unknowns.push_back(x);
        }
    }
    for(int i=0;i<unknowns.size();++i) {
        //cerr << "i = " << i << ":" << unknowns[i] << endl;
        if(unknowns[i] == 0) continue;
        for(int j=i+1;j<unknowns.size();++j) {
            if(unknowns[j] == 0 || unknowns[i] == 0) continue;
            ll v;
            ////cerr << " i " << i << " j " << j << ": " << __gcd(unknowns[i], unknowns[j])<< endl;
            if((v = __gcd(unknowns[i], unknowns[j])) != 1) {
                if(v != unknowns[i] && v != unknowns[j]) {
                    ////cerr << " v = " << v << " .. " << (v != 1) << endl;
                    ////cerr << "ADDING " << unknowns[i]/v << " " << unknowns[j]/v << " " << v << endl;
                    add_fac(unknowns[i]/v, 1);
                    add_fac(unknowns[j]/v, 1);
                    add_fac(v, 2);
                    unknowns[i] = 0;
                    unknowns[j] = 0;
                }
            }
        }
    }
    map<ll, int> u;
    for(int i=0;i<unknowns.size();++i) {
        if(unknowns[i] == 0) continue;
        for(auto& x : factors) {
            if(unknowns[i]%x.first == 0) {
                add_fac(unknowns[i]/x.first, 1);
                add_fac(x.first, 1);
                goto donee;
            }
        }
        if(u.count(unknowns[i]) == 0) {
            u[unknowns[i]] = 0;
        }
        u[unknowns[i]]++;
donee:;
    }
    ll ans = 1;
    for(auto& p : factors) {
        //cerr << p.first << " " << p.second << " so we get "<< p.second+1<< endl;
        ans = (ans*(p.second+1))%MOD;
    }
    for(auto& p : u ) {
        ans = (ans*(p.second+1))%MOD;
        ans = (ans*(p.second+1))%MOD;
    }
    cout << ans << endl;
    return 0;
}