#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
map<pli, pli> m;

pli solve(ll n, int sup) {
    pli state = make_pair(n, sup);
    if(m.count(state) > 0) return m[state];
    if(n == 0) return m[state] = make_pair(0, 0);
    if(n < 10) return m[state] = make_pair(1, max(0LL, sup - n));
    ll ret = 0;
    for(;;) {
        ll d = 1;
        while(d <= n/10) d*= 10;
        int msb = n/d;
        int nsup = max(sup, msb);
        pli child = solve(n%d, nsup);
        ret += child.first;
        n -= n%d;
        if(child.second) {n -= child.second;}
        else {ret++; n-=nsup;}
        pli next(n, sup);
        if(m.count(next)) return m[state] = pli(m[next].first + ret, m[next].second);
    }
}

int main() {
    for(int i = 0; i < 10; ++i)
        for(int j = 0; j < 10; ++j)
            solve(i, j);
    long long n;
    cin >> n;
    cout << solve(n, 0).first << endl;
    return 0;
}