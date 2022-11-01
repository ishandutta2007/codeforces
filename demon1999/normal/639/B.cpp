#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <assert.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <queue>
#define forn(i, n) for(int i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define rs(a, j) a.resize(j)
#define pb(a, j) a.push_back(j)
#define pp(a) a.pop_back()
#define len(s) s.length()
#define sz(a) a.size()
#define re  return
#define fi first
#define se second
#define l1 l11
#define l2 l22
typedef long long ll;
typedef long double ld;
using namespace std;
const ll mod = 1000000007;
ll n, d, h;


int main(){
    iostream::sync_with_stdio(0), cin.tie(0);
    //assert(freopen("point.in", "r", stdin));
    //freopen("point.out", "w", stdout);
    cin >> n >> d >> h;
    if (d == 1 && n > 2) {
        cout << -1;
        re 0;
    }
    if (d > 2 * h) {
        cout << -1;
        re 0;
    }
    forn (i, h) {
        cout << i + 1 << " " << i + 2 << "\n";
    }
    int nu = h + 2;
    if (d == h) {
        while (nu <= n) {
            cout << "2 " << nu << "\n";
            nu++;
        }
        re 0;
    }
    d -= h;
    cout << 1 << " " << h + 2 << "\n";
    nu++;
    d--;
    while (d) {
        cout << nu  - 1 << " " << nu << "\n";
        nu++;
        d--;
    }
    while (nu <= n) {
        cout << 1 << " " << nu << "\n";
        nu++;
    }
    re 0;
}