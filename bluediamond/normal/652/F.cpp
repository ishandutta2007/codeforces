#include <bits/stdc++.h>

bool home = 1;
using namespace std;

typedef long long ll;
const int N = (int) 3e5 + 7;
int n;
ll m;
ll t;
ll init_pos[N];
ll dir[N];
int tag[N];
int position_of_tag[N];
int rl[N];
int inv_rl[N];
int p0 = 0;

ll rep(ll x) {
  x %= m;
  if (x < 0) x += m;
  return x;
}

void simulate() {
  vector<set<ll>> st(2);
  map<ll, int> inv;
  for (int i = 0; i < n; i++) {
    st[(dir[i] == +1)].insert(init_pos[i]);
    inv[init_pos[i]] = i;
  }
  ll dt = 1;
  while (dt <= t) {
    ll srch;
    if (dir[p0] == +1) {
      srch = rep(init_pos[p0] + 2 * dt);

      if (st[0].count(srch)) {
        p0 = inv[srch];
      } else {
        auto it = st[0].lower_bound(srch);
        if (it != st[0].end()) {
          dt += (*it - srch) / 2;
        } else {
          dt += (m - srch) / 2 + 1;
        }
        continue;
      }
    } else {
      srch = rep(init_pos[p0] - 2 * dt);

      if (st[1].count(srch)) {
        p0 = inv[srch];
      } else {
        auto it = st[1].lower_bound(srch);
        if (it != st[1].begin()) {
          it--;
          dt += (srch - *it) / 2;
          continue;
        } else {
          dt += srch / 2;
        }
      }
    }
    dt++;
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  if (home) {
    freopen("I_am_iron_man", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin >> n >> m >> t;
  m *= 4;
  t = 4 * t + 1;
  ll real_t = t - 1;
  ll delta = 0;

  vector<int> init_order(n), end_order(n);

  for (int i = 0; i < n; i++) {
    cin >> init_pos[i];
    init_pos[i]--;
    init_pos[i] *= 4;

    string s_dir;
    cin >> s_dir;
    dir[i] = ((s_dir == "R") ? +1 : -1);
    delta -= dir[i];

    tag[i] = i;
    init_order[i] = i;
    end_order[i] = i;
  }

  sort(init_order.begin(), init_order.end(), [&] (int i, int j) {return init_pos[i] < init_pos[j];});
  sort(end_order.begin(), end_order.end(), [&] (int i, int j) {return rep(init_pos[i] + dir[i] * t) < rep(init_pos[j] + dir[j] * t);});


  for (int i = 0; i < n; i++) {
    rl[init_order[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    inv_rl[rl[i]] = i;
  }

  {
    int position_of_zero = 0;
    for (int i = 0; i < n; i++) {
      if (tag[init_order[i]] == 0) {
        position_of_zero = i;
      }
    }
    vector<int> new_init_order(n);
    for (int step = 0; step < n; step++) {
      new_init_order[step] = init_order[(position_of_zero + step) % n];
    }
    init_order = new_init_order;
  }

  ll full = t / m;
  p0 = inv_rl[((rl[p0] + delta * -full) % n + n) % n];
  t -= full * m;

  simulate();


  for (int i = 0; i < n; i++) {
    if (end_order[i] == p0) {
      p0 = i;
      break;
    }
  }

  for (int step = 0; step < n; step++) {
    tag[end_order[(p0 + step) % n]] = init_order[step];
  }

  for (int i = 0; i < n; i++) {
    position_of_tag[tag[i]] = i;
  }


  for (int _ = 0; _ < n; _++) {
    int i = position_of_tag[_];

    ll P = rep(init_pos[i] + real_t * dir[i]) / 4 + 1;

    cout << P << " ";
  }
  cout << "\n";
}