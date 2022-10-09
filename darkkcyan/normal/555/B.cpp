#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define ll pair<llong, llong>
#define fir first
#define sec second
#define len(x) ((int)x.size())

#define maxn 201010

int n, m;
multimap<ll, int> a;
multimap<llong, int> b;

multiset<ll> lf, rf;

void ins(llong l, llong r) {
  //lf.insert({l, r});
  rf.insert({r, l});
}

void rem(llong l, llong r) {
  //lf.erase(lf.find({l, r}));
  rf.erase(rf.find({r, l}));
}

int ans[maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  if (m < n - 1) {
    cout << "No";
    return 0;
  }

  ll last; cin >> last.fir >> last.sec;
  for (int i = 0; ++i < n; ) {
    llong l, r; cin >> l >> r;
    llong mi = l - last.sec, ma = r - last.fir;
    a.insert({ll(mi, ma), i});
    last = {l, r};
  }
  for (int i = 0; ++i <= m; ) {
    llong u; cin >> u;
    b.insert({u, i});
  }
  
  auto v = a.begin();
  int cnt = n - 1;
  for (auto u: b) {
    while (v != a.end() and v->fir.fir <= u.fir) {
      ins(v->fir.fir, v->fir.sec);
      ++v;
    }
    while (len(rf) and rf.begin()->fir < u.fir) {
      rem(rf.begin()->sec, rf.begin()->fir);
    }
    //clog << endl << u.fir << endl;
    //for (auto i: lf) {
      //clog << i.fir << ' ' << i.sec << endl;
    //}
    if (len(rf)) {
      ll t = *rf.begin();
      swap(t.fir, t.sec);
      rem(t.fir, t.sec);
      auto x = a.find(t);
      ans[x->sec] = u.sec;
      a.erase(x);
      --cnt;
    }
  }

  //clog << cnt << endl;

  if (cnt > 0) {
    cout << "No";
    return 0;
  }

  cout << "Yes\n";
  for (int i = 1; i < n; ++i) cout << ans[i] << ' ';

  return 0;
}