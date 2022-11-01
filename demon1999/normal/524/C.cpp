#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#define forn(i, n) for(int i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define rs(a, j) a.resize(j)
#define pb(a, j) a.push_back(j)
#define pp(a) a.pop_back()
#define len(s) s.length()
#define sz(a) a.size()
#define re  return
#define l1 l11
#define r1 r11
using namespace std;
typedef long long ll;
typedef long double ld;
const long ma11 = 524288, ma1 = 16;
ll mi = 21, k, n, q, p;

bool ok = false;
vector<ll> a;

int main(){
    //freopen("i.in", "r", stdin);
    cin >> n >> k; a.resize(n);
    set<ll> b;
    for(int i = 0; i < n ; i++){
      cin >> a[i]; b.insert(a[i]);
    }
    cin >> q;
    for(int i = 0; i < q; i++){
      cin >> p; mi = 21;
      for(int j = 0; j <= k; j++){
        for(int p1 = 1; p1 <= k - j; p1++)
          for(int q = 0; q < n; q++){
            if(p > a[q] * j && (p - a[q] * j) % p1 == 0 && b.find((p - a[q] * j) / p1) != b.end()){
              mi = min(mi, (ll)p1 + j);
            }
          }
      }
      if(mi != 21)cout << mi << "\n";
      else cout << -1 << "\n";
    }
    return 0;
}