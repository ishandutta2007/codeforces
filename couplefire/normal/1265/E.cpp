#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353

struct frac{
    long long a, b;
    frac(long long aa, long long bb){
        a = aa;
        b = bb;
    }
    frac add(){
        long long aa = a;
        aa += b;
        aa %= MOD;
        return {aa, b};
    }
    frac mult(long long pi){
        long long aa = a, bb = b;
        aa *= 100;
        aa %= MOD;
        bb *= pi;
        bb %= MOD;
        return {aa, bb};
    }
    void coprime(){
        long long t = __gcd(a, b);
        a /= t;
        b /= t;
    }

};

long long modInverse(long long a, long long m) 
{ 
    long long m0 = m; 
    long long y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
        // q is quotient 
        long long q = a / m; 
        long long t = m; 
  
        // m is remainder now, process same as 
        // Euclid's algo 
        m = a % m, a = t; 
        t = y; 
  
        // Update y and x 
        y = x - q * y; 
        x = t; 
    } 
  
    // Make x positive 
    if (x < 0) 
       x += m0; 
  
    return x; 
}

int main(){
    //freopen("a.in", "r", stdin);
    long long n; cin >> n;
    vector<long long> v(n);
    for(long long i = 0; i<n; i++) cin >> v[i];
    vector<frac> vv(n, {0, 0});
    vv[0] = {100, v[0]};
    for(long long i = 1; i<n; i++) vv[i] = (vv[i-1].add()).mult(v[i]);
    vv[n-1].coprime();
    cout << ((modInverse(vv[n-1].b, MOD))*(vv[n-1].a))%MOD << endl;
}