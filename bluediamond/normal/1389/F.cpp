///   ///https://www.youtube.com/watch?v=hQh9gsPTSbM Hola nios
#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

mt19937 rng_home(2);
mt19937 rng_oj((long long) (new char));

int rng() {
  if (home) {
    return rng_home();
  } else{
    return rng_oj();
  }
}

ull rng_ull() {
  return (ull) rng() * rng() ^ ((ull) rng() * rng());
}

int rng_range(int l, int r) {
  return l + abs(rng()) % (r - l + 1);
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = (int) 2e5 + 7;
int n;

struct event {
  int tp;
  int tm;
  bool start;
  int id;
  int fn;
};

bool operator < (event a, event b) {
  if (a.tm == b.tm) {
    return a.start < b.start;
  } else {
    return a.tm < b.tm;
  }
}

set<pair<int,int>> s[3];

signed realMain() {
/// /// /// /// ///   ///https://www.youtube.com/watch?v=hQh9gsPTSbM Hola nios
/// maximum independent set = nr vertexes - flow
  /// flow =  max matching
  /// max matching = greedy bro
  cin>>n;
  vector<event> e;
  for (int i=1;i<=n;i++) {
    int l,r,t;
    cin>>l>>r>>t;
    e.push_back({t,l,1,i,r});
    e.push_back({t,r+1,0,i,r});
  }
  sort(e.begin(),e.end());
  int flow=0;
  for (auto &it : e) {
    if (it.start) {
      s[it.tp].insert({it.fn,it.id});
    } else {
      if (!s[it.tp].count({it.fn,it.id})) continue;
      if (!s[3-it.tp].empty()) {
      if (home)
        cout<<it.id << " with " << s[3-it.tp].begin()->second<<"\n";
        flow++;
        s[3-it.tp].erase(s[3-it.tp].begin());
      }
      s[it.tp].erase({it.fn,it.id});
    }
  }
  cout << n-flow << "\n";
  return 0;
}