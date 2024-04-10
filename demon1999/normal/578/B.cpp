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
long long n, k, x, ans, p, q[64];
vector<long long> a;
int main(){
    iostream::sync_with_stdio(0);
    cin >> n >> k >> x;
    a.resize(n);
    forn (i, n) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    forn (i, n) {
        forn (j, 33)
            if (a[i] & (1 << j)) q[j] ++;
    }
    forn (i, n) {
        forn (j, 33)
            if (a[i] & (1 << j)) q[j]--;
        p = a[i];
        forn (j, k) p *= x;
        forn (j, 33)
            if (q[j] > 0) p |= (1 << j);
        forn (j, 33)
            if (a[i] & (1 << j)) q[j] ++;
        ans = max(ans, p);
    }
    cout << ans;
    return 0;
}