#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <cassert>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define mp(i, j) make_pair(i, j)
#define rs(j) resize((j))
#define pb push_back
#define pp pop_back
#define len(s) (int)s.length()
#define sz(a) (int)a.size()
#define re  return
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
using namespace std;

struct T { int x, y; };
int n, t, a, b, qq[5 * 100001];
string s;
int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("qq.in", "r",  stdin));
    cin >> n >> a >> b >> t >> s;
    forn (i, n) {
        if (s[i] == 'w') qq[i] = b;
    }
    int ans = 0, sum = 0;
    forn (i, n) {
        ans += qq[i] + 1;
        if (ans <= t) sum = max(sum, i + 1);
        ans += a;
    }
    ans = a + qq[0] + 1;
    for (int i = n - 1; i > 0; i--) {
        ans += qq[i] + 1;
        if (ans <= t) sum = max(sum, n + 1 - i);
        ans += a;
    }
    ans = 0;
    int sm = qq[0] + 1 + a, j = 0, sm1;
    for (int i = 1; i < n; i++) {
        sm += a + qq[i] + 1;
    }
    sm1 = sm;
    for (int i = 0; i < n; i++) {
        ans += qq[i] + 1;
        while (j < n && ans + sm > t) {
            sm = sm - (a + qq[j] + 1);
            j++;
        }
        //cout << i << " " << j << " " << ans << " " << sum << endl;
        if (ans + sm <= t) sum = max(sum, i + 1 + n - j);
        ans += 2 * a;
    }
   // cout << sum << endl;
    j = n - 1;
    ans = 2 * a;
    sm1 -= a;
    for (int i = n - 1; i > 0; i--) {
        ans += qq[i] + 1;
        while (j >= 0 && ans + sm1 > t) {
            sm1 -= (a + qq[j] + 1);
            j--;
        }
        if (ans + sm1 <= t) sum = max(sum, n - i + j + 1);
        ans += 2 * a;
    }
    cout << min(n, sum);
    return 0;
}