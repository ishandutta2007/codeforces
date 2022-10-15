#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool home = 1;

const int N = 100000 + 7;
const ll INF = (ll) 1e18 + 7;
int n, q;
ll t[N];
ll what[N];
int par[N];
int cnt[N];
set<int> g[N];
multiset<ll> st[N];

ll f(int i) {
  return t[i] / (cnt[i] + 2);
}

ll extra(int i) {
  return t[i] - f(i) * (cnt[i] + 1);
}

multiset<ll> small, big;

void del2(int a) {
  if (st[a].empty()) return;
  assert(small.count(f(a) + *st[a].begin()));
  small.erase(small.find(f(a) + *st[a].begin()));
  auto it = st[a].end();
  it--;


  ///cout << "la " << a << " nu il gasesc pe " << f(a) + *it << "\n";
  assert(big.count(f(a) + *it));
  big.erase(big.find(f(a) + *it));
}

void add2(int a) {
  if (st[a].empty()) return;
  small.insert(f(a) + *st[a].begin());
  auto it = st[a].end();
  it--;
  big.insert(f(a) + *it);
}


void del(int a) {
  del2(par[a]);

  assert(st[par[a]].count(what[a]));
  st[par[a]].erase(st[par[a]].find(what[a]));

  add2(par[a]);
}

void add(int a) {
  del2(par[a]);
  st[par[a]].insert(what[a]);
  add2(par[a]);
}



signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE


  if (home) {
    freopen ("input", "r", stdin);
  }

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> par[i];
    g[par[i]].insert(i);
    cnt[par[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    what[par[i]] += f(i);
    what[i] += extra(i);
  }
  for (int i = 1; i <= n; i++) {
    st[par[i]].insert(what[i]);
  }
  for (int i = 1; i <= n; i++) {
    add2(i);
  }

  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int i, j;
      cin >> i >> j;

      g[par[i]].erase(i);

      del(par[i]);

      del(par[par[i]]);


      what[par[i]] -= f(i) + extra(par[i]);
      what[par[par[i]]] -= f(par[i]);

      del2(par[i]);
      cnt[par[i]]--;
      add2(par[i]);

      what[par[i]] += extra(par[i]);
      what[par[par[i]]] += f(par[i]);

      add(par[i]);
      add(par[par[i]]);
      del(i);

      par[i] = j;
      g[par[i]].insert(i);

      del(par[j]);
      del(par[i]);


      what[par[j]] -= f(j);


      what[par[i]] -= extra(par[i]);

      del2(par[i]);
      cnt[par[i]]++;
      add2(par[i]);

      what[par[i]] += extra(par[i]) + f(i);
      what[par[j]] += f(j);

      add(par[i]);
      add(par[j]);

      add(i);

      continue;
    }
    if (type == 2) {
      int i;
      cin >> i;
      cout << what[i] + f(par[i]) << "\n";
      continue;
    }

    if (type == 3) {
      cout << *small.begin() << " ";
      auto it = big.end();
      it--;
      cout << *it << "\n";
      continue;
    }
    assert(0);
  }

  return 0;
}
/**



**/