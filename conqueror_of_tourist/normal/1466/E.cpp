#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

#define MOO(i, a, b) for (int i=a; i<b; i++)
#define M00(i, a) for (int i=0; i<a; i++)
#define MOOd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define M00d(i,a) for (int i = (a)-1; i >= 0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << '\n', 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << "\n";

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;
typedef vector<int> vi;
typedef vector<ll> vll;

ll MOD = 1000000007;

ll power(ll x, unsigned int y) 
{ 
    ll res = 1;     // Initialize result 
   
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % MOD; 
   
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % MOD;  // Change x to x^2 
    } 
    return res; 
}

int main() { FAST
    int t;
    cin >> t;
    
    ll count[60];
    ll pairs[3600];
    ll p2[60];
    
    for (int i = 0; i < 60; i++){
        p2[i] = power(2,i);
    }
    
    for(int u = 0; u < t; u++){
        for(int i = 0; i < 60; i++) count[i] = 0;
        for(int i = 0; i < 3600; i++) pairs[i] = 0;
        
        int n;
        cin >> n;
        
        ll sum = 0;
        
        vll xs;
        
        for(int i = 0; i < n; i++){
            ll x;

            cin >> x;
            xs.pb(x);
            
            sum += (x % MOD);
            sum %= MOD;
            
            for(ll i = 0; i < 60; i++){
                if ((x >> i) & 1) count[i] += 1;
            }
        }
    
        
        ll out = 0;
        for(int i = 0; i < 60; i++){
            ll mult = p2[i];
                
            ll tot = count[i];
            
            ll c = sum * tot;
            c %= MOD;
            c *= tot;
            c %= MOD;
            
            out += (c * mult) % MOD;
        }
        
        for(ll x : xs){
            ll m1 = 0;
            ll m2 = 0;
            for(ll i = 0; i < 60; i++){
                if ((x >> i) & 1){
                    m1 += (count[i]) * p2[i];
                    m2 += (n - count[i]) * p2[i];
                }
            }
            m1 %= MOD;
            m2 %= MOD;
            
            out += (m1 * m2) % MOD;
        }
        
        cout << (out % MOD) << '\n';
    }

}