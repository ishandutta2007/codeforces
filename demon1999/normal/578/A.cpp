#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>

#define forn(i, n) for(int i = 0; i < n; i++)
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
long double x, ans = 20000000000;
long long l, r, a, b, k;
int main(){
    iostream::sync_with_stdio(0);
    cin >> a >> b;
    if (a == b) {
        cout << a;
        re 0;
    }
    if (a < b) {
        cout << -1;
        re 0;
    }
    k = (a + b);
    a -= b;
    l = 1, r = 20000000001;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (k / (2 * mid) < b) r = mid;
        else l = mid;
    }
    if (ld(k) / ld(2 * l) >= b)
        ans = min(ans, ld(k) / ld(2 * l));
    l = 1; r = 20000000001;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (a / (2 * mid) < b) r = mid;
        else l = mid;
    }
    if (ld(a) / ld(2 * l) >= b)
        ans = min(ans, ld(a) / ld(2 * l));
    cout.precision(20);
    cout << ans;
    return 0;
}