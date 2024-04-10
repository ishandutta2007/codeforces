#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#define forn(i, n) for(int i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define rs(a, j) a.resize(j)
#define pb(a, j) a.push_back(j)
#define pp(a) a.pop_back()
#define len(s) s.length()
#define sz(a) a.size()
#define re return
typedef long long ll;
typedef long double ld;
using namespace std;
ld ans = 0, p;ll l[100], r[100];
int n;
ld func(int i, ll p1){
  ll ans = 0, ok, l33;
 // cout << i << " " << p1 << " ";
  if(i > n || r[i] < p1 || l[i] > p1) return 0;
  for(int j = 0; j < n; j++){
    ok = 0;
    if(j != i){
      ok = r[j] - max(l[j] - 1, p1);
      if(j < i && p1 >= l[j] && p1 <= r[j])ok++; if(ok < 0) ok = 0;
      for(int k = 0; k < n; k++){
        if(k != i && k != j){
            l33 = min(p1, r[k] + 1) - l[k];
            if(k > i && p1 >= l[k] && p1 <= r[k])l33++;
            if(l33 < 0)l33 = 0;
            ok *= l33;
        }
      }
    }
    ans += ok;
  }
  return ans;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)cin >> l[i] >> r[i];
    for(int i = 1; i <= 10000; i++){
        p = i;
        ans += (func(0, i) + func(4, i) + func(3, i) + func(2, i) + func(1, i)) * p;
    }
    for(int i = 0; i <= n; i++)ans /= (r[i] - l[i] + 1);
    cout.precision(200);
    cout << ans << endl;
    return 0;
}