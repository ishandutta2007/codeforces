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
#define pb push_back
#define pp(a) a.pop_back()
#define len(s) s.length()
#define sz(a) a.size()
#define re  return
typedef long long ll;
typedef long double ld;
using namespace std;
vector<ll> a[200000];
ll n, ans[200000], a1[200000], kk, p, ans1 = 0;
set<pair<ll, ll> > q[200000];
set<pair<ll, ll> > :: iterator it;
void dfs(int kk){
  ll cou = 0; ans[kk] = a1[kk]; ll mi = a1[kk], nu = kk, p1 = kk;
  forn(i, sz(a[kk])){
    dfs(a[kk][i]);
    if(q[a[kk][i]].begin() != q[a[kk][i]].end() && mi > q[a[kk][i]].begin() -> first){
        mi = q[a[kk][i]].begin() -> first; p1 = a[kk][i]; nu = q[a[kk][i]].begin() ->  second;
    }
    ans[kk] += ans[a[kk][i]];
    cou++;
  }
  q[kk].insert(mp(a1[kk], kk));
  if(cou % 2){
    ans[kk] -= mi;
    q[p1].erase(mp(a1[nu], nu));
    forn(i, sz(a[nu])){
      cou = a[nu][i];
      for(it = q[cou].begin(); it != q[cou].end(); it++){
        q[p1].insert(mp(it -> first, it -> second));
      }
      while(q[cou].begin()!= q[cou].end())q[cou].erase(q[cou].begin());
    }
  }
  ans1 = max(ans1, ans[kk]);
}
int main(){
    //freopen("s.in", "r", stdin);
    cin >> n;
    forn(i, n){
      cin >> p >> a1[i];
      if(p == -1){
        kk = i;continue;
      }
      a[p - 1].pb(i);
    }
    dfs(kk);
    cout << ans1;
    return 0;
}