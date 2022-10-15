#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


const int N = 200000 + 7;
int n, when_tt[2 * N], first_pos[2 * N], tt;

vector<int> rep(vector<int> p, int st, int dr) {
  vector<int> np;
  for (auto &x : p) {
    if (st <= x && x <= dr) {
      np.push_back(x);
    }
  }
  return np;
}

int solve(vector<int> p1, vector<int> p2, int st, int dr) {
  p1 = rep(p1, st, dr);
  int print = 0;
  assert(!p1.empty());
  assert(!p2.empty());
  tt++;
  for (int i = 0; i + 1 < (int) p1.size(); i++) {
    assert(p1[i] < p1[i + 1]);
  }
  for (int i = 0; i + 1 < (int) p2.size(); i++) {
    assert(p2[i] < p2[i + 1]);
  }
  vector<pair<int, int>> v;
  int x = 0, y = 0;
  while (x < (int) p1.size() && y < (int) p2.size()) {
    if (p1[x] < p2[y]) {
      v.push_back({p1[x], +1});
      x++;
      continue;
    }
    assert(p2[y] < p1[x]);
    v.push_back({p2[y], -1});
    y++;
  }
  while (x < (int) p1.size()) {
    v.push_back({p1[x], +1});
    x++;
  }
  while (y < (int) p2.size()) {
    v.push_back({p2[y], -1});
    y++;
  }
  assert((int) v.size() == (int) p1.size() + (int) p2.size());
  assert((int) v.size() >= 2);
  v[0].second += n;
  for (int i = 1; i < (int) v.size(); i++) {
    assert(v[i - 1].first < v[i].first);
    v[i].second += v[i - 1].second;
  }
  when_tt[n] = tt;
  first_pos[n] = st - 1;
  for (int i = 0; i < (int) v.size(); i++) {
    int urm;
    if (i + 1 < (int) v.size()) {
      urm = v[i + 1].first - 1;
    } else {
      urm = dr;
    }
    if (when_tt[v[i].second] == tt) {

      print = max(print, urm - first_pos[v[i].second]);
    } else {
      when_tt[v[i].second] = tt;
      first_pos[v[i].second] = v[i].first;
    }
  }
  return print;
}


int ant[N];
int nxt[N];
int init[N];
int init_frq[N];
int max_init_frq;
int my_guy;
vector<int> pos[N];

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> init[i];
    pos[init[i]].push_back(i);
    init_frq[init[i]]++;
  }

  max_init_frq = *max_element(init_frq + 1, init_frq + n + 1);

  vector<int> guys_having_max_init_frq;
  for (int x = 1; x <= n; x++) {
    if (init_frq[x] == max_init_frq) {
      guys_having_max_init_frq.push_back(x);
    }
  }

  assert((int) guys_having_max_init_frq.size() >= 1);

  if ((int) guys_having_max_init_frq.size() >= 2) {
    cout << n << "\n";
    exit(0);
  }

  assert((int) guys_having_max_init_frq.size() == 1);
  my_guy = guys_having_max_init_frq[0];

  ant[0] = 0;
  for (int i = 1; i <= n; i++) {
    if (init[i - 1] == my_guy) {
      ant[i] = i - 1;
    } else {
      ant[i] = ant[i - 1];
    }
  }
  nxt[n + 1] = n + 1;
  for (int i = n; i >= 1; i--) {
    if (init[i + 1] == my_guy) {
      nxt[i] = i + 1;
    } else {
      nxt[i] = nxt[i + 1];
    }
  }


  int print = 0, rad = 250;

  for (int x = 1; x <= n; x++) {
    if (x == my_guy) {
      continue;
    }
    if (init_frq[x] == 0) {
      continue;
    }
    if (init_frq[x] >= rad) {
      print = max(print, solve(pos[x], pos[my_guy], 1, n));
    } else {
      for (int p = 0; p < (int) pos[x].size(); p++) {
        int st = 1, dr = n;
        vector<int> a, b;
        for (int i = ant[pos[x][p]]; i >= 1; i = ant[i]) {
          if ((int) a.size() > (int) pos[x].size()) {
            st = i + 1;
            break;
          }
          a.push_back(i);
        }
        for (int i = nxt[pos[x][p]]; i <= n && (int) b.size() <= rad; i = nxt[i]) {
          if ((int) b.size() > (int) pos[x].size()) {
            dr = i - 1;
            break;
          }
          b.push_back(i);
        }
        reverse(a.begin(), a.end());
        for (auto &x : b) {
          a.push_back(x);
        }
        print = max(print, solve(pos[x], a, st, dr));
      }
    }
  }
  cout << print << "\n";
  return 0;
}