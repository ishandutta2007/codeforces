#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 2e5 + 7;
mt19937 rng_int((long long) (new char));

ll get_random() {
  ll x = rng_int();
  ll y = rng_int();
  ll z = rng_int();
  return x * y + z;
}

int n, m, p[N];
bool vis[N];
bool valid[N];
vector<int> g[N];
int parrent[N];

ll special[N];
ll _meh_[N];
ll v[N];

vector<int> kids_with_parrents, all;

void build_init(int a) {
  all.push_back(a);
  if (parrent[a]) {
    kids_with_parrents.push_back(a);
  }

  assert(vis[a] == 0);
  vis[a] = 1;

  _meh_[a] = special[p[a]] - special[a];

  vector<int> newG;

  for (auto &b : g[a]) {
    if (vis[b] == 0) {
      parrent[b] = a;
      build_init(b);
      _meh_[a] += _meh_[b];
      newG.push_back(b);
    }
  }

  v[a] = _meh_[a] - special[p[a]];

  g[a] = newG;
}


set<pair<ll, int>> s[N];

void add(int a) {
  if (!parrent[a]) return;
  s[parrent[a]].insert({v[a], a});
}

void del(int a) {
  if (!parrent[a]) return;
  s[parrent[a]].erase({v[a], a});
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    valid[i] = 1;
    special[i] = get_random();
  }
  map<pair<int, int>, int> Ind;
  for (int i = 1; i <= m; i++) {
    int X, Y;
    cin >> X >> Y;
    Ind[{X, Y}] = Ind[{Y, X}] = i;
    g[X].push_back(Y);
    g[Y].push_back(X);
  }
  vector<int> solution;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;

    kids_with_parrents.clear();
    all.clear();
    build_init(i);
    assert((int) all.size() == 1 + (int) kids_with_parrents.size());

    for (auto &a : kids_with_parrents) {
      add(a);
    }

    queue<int> Q;

    shuffle(all.begin(), all.end(), rng_int);

    for (int step = 1; step <= (int) kids_with_parrents.size(); step++) {
      int sol = -1;
      if (Q.empty()) {
        for (auto &vertex : all) {
          auto it = s[vertex].lower_bound({-special[p[vertex]], -1});
          if (it != s[vertex].end() && it->first == -special[p[vertex]]) {
            Q.push(vertex);
          }
        }
      }
      while (!Q.empty()) {
        int vertex = Q.front();
        Q.pop();
        auto it = s[vertex].lower_bound({-special[p[vertex]], -1});
        if (it != s[vertex].end() && it->first == -special[p[vertex]]) {
          int a = it->second;
          assert(v[a] + special[p[vertex]] == 0);
          sol = a;
          break;
        }
      }

      if (sol == -1) {
        step--;
        continue;
      }

      assert(sol != -1);
      int a = sol;
      valid[a] = 0;
      _meh_[a] = v[a] + special[p[a]] - special[p[a]] + special[p[parrent[a]]];


      swap(p[a], p[parrent[a]]);

      if (parrent[a]) Q.push(parrent[a]);
      if (parrent[parrent[a]]) Q.push(parrent[parrent[a]]);
      Q.push(a);

      del(a);
      del(parrent[a]);
      v[a] = v[a] + special[p[parrent[a]]] - special[p[a]];
      v[parrent[a]] = _meh_[parrent[a]] - special[p[parrent[a]]];

      add(a);
      add(parrent[a]);


      pair<int, int> Search = {a, parrent[a]};
      assert(Ind.count(Search));
      solution.push_back(Ind[Search]);
    }
  }
  for (auto &i : solution) {
    cout << i << " ";
  }
  cout << "\n";
}