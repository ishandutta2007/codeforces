#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ll> VI;
typedef vector<VI> VVI;

const ll maxs = 1e6 + 321;

ll mpow(ll a, ll b, ll p){
    if (b == 0) return 1;
    ll t = mpow(a*a%p, b/2, p);
    if (b % 2) t = t*a%p;
    return t;
}

ll fact[maxs], invf[maxs];



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, m, a, q;
    cin >> n >> m >> a >> q;
    
    a %= q;
    ll ord = 1;
    ll ac = a;
    while (ac != 1){
        ac = ac*a;
        ac %= q;
        ++ord;
    }
    
   // cerr << "eps "  << ord << endl;
    
    invf [0] = fact[0] = 1;
    for (int i = 1; i < maxs; ++i){
        fact[i] = fact[i-1]*i%ord;
        invf[i] = mpow(fact[i], ord-2, ord);
    }
    
    //cerr << "hola "  << fact[2]*invf[2]%ord << endl;
    
    VI sol;
    ll acum = 0;
    for (int i = 0; i < min(n, m+1); ++i){
        acum = (acum + fact[m]*invf[m-i]%ord*invf[i])%ord;
        sol.push_back(acum);
    }
    while (sol.size() < n){
        sol.push_back(sol.back());
    }
    reverse(sol.begin(), sol.end());
    for (int i = 0; i < n; ++i){
        cout << (i ? " " : "") << mpow(a, sol[i], q);
    }
    cout << endl;
    
}