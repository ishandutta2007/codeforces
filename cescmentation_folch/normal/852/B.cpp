#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ll> VI;
typedef vector<VI> VVI;

int m;

const ll mod = 1e9+7;

VI operator * (const VI &a, const VI &b){
    VI res(m, 0);
    for (int i = 0; i < int(a.size()); ++i){
        for (int j = 0; j < int(b.size()); ++j){
            res[(i+j)%m] += a[i]*b[j];
            res[(i+j)%m] %= mod;
        }
    }
    return res;
}

VI mpow(VI a, int b){
    if (b == 1) return a;
    VI t = mpow(a*a, b/2);
    if (b%2) return t*a;
    return t;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, l;
    cin >>n >> l >> m;
    vector<ll> ini(m,0), fi(n, 0);
    VI mid(m, 0);
    vector<ll> mid2(n, 0);
    
    for (int i = 0; i < n; ++i){
        int a;
        cin >> a;
        if (a == m) ini[0]++;
        else ini[a]++;
    }
    for (int i = 0; i < n; ++i){
        int a;
        cin >> a;
        if (a == m) a = 0;
        
        mid2[i] = a;
        mid[a]++;
    }
    for (int i = 0; i < n; ++i){
        cin >> fi[i];
        if (fi[i] == m) fi[i] = 0;
        fi[i] += mid2[i];
        if (fi[i] >= m) fi[i] -= m;
    }
    
//     VI t = ini*mpow(mid, l-2);
//     for (int x : t) cerr << x << " ";
//     cerr << endl;
    
    //VI tt = ini*mpow(mid, l-1)*fi;
    //for (int x : tt) cerr << x << " ";
    //cerr << endl;
    
    
    VI res;
    if (l > 2) res = ini*mpow(mid, l-2);
    else res = ini;
    int ans = 0;
    for (int i = 0; i < n; ++i){
       // cerr << (m-fi[i]%m) << endl;
        if (fi[i] == 0) ans += res[0];
        else ans += res[(m-fi[i])];
        if (ans >= mod) ans -= mod;
    }
    
    cout << ans << endl;
}