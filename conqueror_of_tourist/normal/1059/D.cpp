#include <bits/stdc++.h>
 
#define PI 3.14159265358979323846
 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define vec vector
#define double long double

using ll = long long;
using ull = unsigned long long;
using namespace std;
 
#ifndef LOCAL 
 
#pragma GCC optimize ("O3")
#define debug(...)
 
#else 
 
#include "../../debug.cpp"

#endif 
 
int n; 
vec<pair<double, double>> pos;

bool ok(double r){
    vec<pair<double, int>> ints;
    for(auto [x, y] : pos){
        double left = r*r - (y-r)*(y-r);
        if(left <= 0) return false;
        ints.pb({x - sqrt(left), 1});
        ints.pb({x + sqrt(left), -1});
    }
    sort(all(ints));
    int cnt = 0;
    for(auto [_, c] : ints){
        cnt += c;
        if(cnt == n) return true;
    }
    return false;
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	
    cin >> n;
    int sgn = 0;
    for(int i = 0; i < n; ++i){
        double x, y; cin >> x >> y; sgn += (y > 0 ? 1 : -1);
        pos.pb({x, abs(y)});
    }
    if(abs(sgn) != n){
        cout << -1 << endl; return 0;
    }
    double l = 0.0000001, r = 50000000000000;
    for(int i = 0; i < 39; ++i){
        double m = sqrtl(l*r);
        debug(m, ok(m));
        if(ok(m)){
            r = m;
        } else {
            l = m;
        }
    }
    cout << setprecision(20) << r << endl;
 
    return 0;
}