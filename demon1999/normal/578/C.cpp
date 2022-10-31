#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>

#define forn(i, n) for(long long i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define rs(a, j) a.resize(j)
#define pb(a, j) a.push_back(j)
#define pp(a) a.pop_back()
#define len(s) s.length()
#define sz(a) a.size()
#define re  return
typedef long long ll;
typedef long double ld;
using namespace std;
long long n, k, x, ans, p;
vector<long double> a;
long double l = -100001, r = 100001, mid, ma1, ma, mi1, mi;
ld f(ld x) {
    ma1 = a[0] - x, mi1 = a[0] - x;
    ma = mi = 0;
    forn (i, n) {
        ma += a[i] - x;
        ma1 = max(ma, ma1);
        mi += a[i] - x;
        mi1 = min(mi, mi1);
        if (mi > 0) mi = 0;
        if (ma < 0) ma = 0;
    }
    return max(abs(ma1), abs(mi1));
}
int main(){
    //ifstream cin("input.txt");
    iostream::sync_with_stdio(0);
    cin >> n;
    a.resize(n);
    forn (i, n) {
        cin >> a[i];
    }
    while (r - l > 0.0000000000001) {
        if (f(l + (r - l) / 3) < f(l + 2 * (r - l) / 3))
            r = l + 2 * (r - l) / 3;
        else l += (r - l) / 3;
    }
    cout.precision(30);
    cout << f(l);
    return 0;
}