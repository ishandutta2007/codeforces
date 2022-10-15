#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct Number {
  ll x;
  /// aveam in gand altceva, deci asta s-a dovedit a fi extrem de useless
};

const int N = (int) 1e6 + 7;
int n, m, k;
Number a[N];
ll mx[N];
int offmx[N];
vector<pair<ll, int>> offadd[N];
vector<pair<ld, int>> offprod;
ld sumprod[N];
bool special[N];


ld eval(int i, ll x) {
  ld lgcur = log(a[i].x);
  ld lgviit = log(a[i].x + x);
  return lgviit - lgcur;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  //freopen ("input", "r", stdin);

  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x;
  }
  for (int i = 1; i <= m; i++) {
    int type, id, b;
    cin >> type >> id >> b;
    if (type == 1) {
      if (b > mx[id]) {
        mx[id] = b;
        offmx[id] = i;
      }
      special[i] = 1;
    }
    if (type == 2) {
      offadd[id].push_back({b, i});
    }
    if (type == 3) {
      offprod.push_back({log(b), i});
    }
  }
  for (int i = 1; i <= n; i++) {
    if (mx[i]) {
      offadd[i].push_back({mx[i] - a[i].x, offmx[i]});
      /// atentie cand afisez sa pun pe offmx[i] primul
    }
  }
  for (int i = 1; i <= n; i++) {
    sort(offadd[i].begin(), offadd[i].end());
  }
  sort(offprod.rbegin(), offprod.rend());
  for (int i = 1; i <= (int) offprod.size(); i++) {
    sumprod[i] = sumprod[i - 1] + offprod[i - 1].first;
  }
  ld sol = 0, cursum = 0;
  for (int i = 1; i <= n; i++) {
    cursum += log(a[i].x);
  }

  priority_queue<pair<ld, int>> pq;
  for (int i = 1; i <= n; i++) {
    if (!offadd[i].empty()) {
      pq.push({eval(i, offadd[i].back().first), i});
    }
  }

  sol = sumprod[min((int) offprod.size(), k)] + cursum;

  vector<int> indici;

  int noprodsol = 0;

  for (int noprod = 1; noprod <= k; noprod++) {
    if (pq.empty()) break;
    auto it = pq.top();
    pq.pop();
    cursum += it.first;
    int i = it.second;

    a[i].x += offadd[i].back().first;

    indici.push_back(offadd[i].back().second);
    offadd[i].pop_back();

    if (!offadd[i].empty()) {
      pq.push({eval(i, offadd[i].back().first), i});
    }

    ld cur = sumprod[min((int) offprod.size(), k - noprod)] + cursum;
    if (cur > sol) {
      sol = cur;
      noprodsol = noprod;
    }
  }

  indici.resize(noprodsol);
  vector<pair<int, int>> anss;
  for (auto &i : indici) {
    anss.push_back({special[i], i});
  }
  sort(anss.rbegin(), anss.rend());
  vector<int> ans;
  for (auto &i : anss) {
    ans.push_back(i.second);
  }

  for (int i = 1; i <= min((int) offprod.size(), k - noprodsol); i++) {
 //   cout << "aici\n";
    ans.push_back(offprod[i - 1].second);
  }

  cout << (int) ans.size() << "\n";
  for (auto &i : ans) cout << i << " ";

  cout << "\n";
  return 0;


  /// daca sz(sol) < k atunci pun niste lucruri random la inceput
  cout << noprodsol << "\n";
  cout << "my   max = " << sol << "\n";
  cout << "real max = " << log(19) + log(60) << "\n";
  return 0;
}