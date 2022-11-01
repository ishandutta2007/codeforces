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

#define forn(i, n) for (int i = 0; i < int(n); i++)
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

struct T { ll m1, m2; };
T t = {1, 2};

const int ma = 2 * 131072;
ll n, m, l, r, k;
string s1, s2;
int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //freopen("round.in", "r",  stdin);
    cin >> l >> r;
    ll ans = 0;
    forn (i, 61) {
        n = (1LL << (i + 1)) - 1;
        forn (j, i)
            if ((n - (1LL << j)) >= l && (n - (1LL << j)) <= r) ans++;
    }
    cout << ans;
    return 0;
}