#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cassert>
#include <cstdio>

using namespace std;

typedef long long ll;

struct Question {
  int l;
  int r;
  int s;
  int t;
};

const int N = 1000 + 7;
const int M = (int)2e5 + 7;
const int INF = (int)1e9 + 7;

int n;
int m;
int q;
pair<int, int> edges[M];
Question questions[M];
vector<int> qhere[M];
vector<int> qhere_end[M];
int is_yes[M];
bitset<N> reachable[N];
bitset<N> memo[M];
bool st_memo[M];

bool cmpQR(int i, int j) {
  return questions[i].r < questions[j].r;
}

bool cmpQL(int i, int j) {
  return questions[i].l < questions[j].l;
}

int tt, last[N];

void clr(int i) {
  if (last[i] == tt) return;
  last[i] = tt;
  reachable[i].reset();
  reachable[i].set(i);
}

void solve(int low, int high) {
  if (low >= high) {
    return;
  }
  assert(low < high);
  int mid = (low + high) / 2;





  {
    for (int r = mid + 1; r <= high; r++) {
      int x = edges[r].first, y = edges[r].second;
      reachable[x] = reachable[y] = reachable[x] | reachable[y];

      while (!qhere_end[r].empty()) {
        int i = qhere_end[r].back();
        assert(low <= questions[i].l);
        if (mid + 1 <= questions[i].l) break;
        memo[i] = reachable[questions[i].t];
        st_memo[i] = 1;
        qhere_end[r].pop_back();
      }

    }
  }


  {
    tt++;
    for (int i = mid + 1; i <= high; i++) {
      clr(edges[i].first);
      clr(edges[i].second);
    }
  }




  for (int l = mid; l >= low; l--) {
    int x = edges[l].first, y = edges[l].second;
    reachable[x] = reachable[y] = reachable[x] | reachable[y];

    while (!qhere[l].empty()) {
      int i = qhere[l].back();

      assert(questions[i].r <= high);

      if (questions[i].r <= mid) break;
      qhere[l].pop_back();

      assert(st_memo[i]);
      if ((reachable[questions[i].s] & memo[i]) != 0) {
        is_yes[i] = 1;
      }
    }
  }

  {
    tt++;
    for (int i = low; i <= mid; i++) {
      clr(edges[i].first);
      clr(edges[i].second);
    }
  }
  solve(low, mid);
  solve(mid + 1, high);
}

pair<int, int> so(int x, int y) {
  return { min(x,y),max(x,y) };
}

bool do_r[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);


  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    reachable[i].reset(i);
    reachable[i].set(i);
  }


  for (int i = 1; i <= m; i++) {
    cin >> edges[i].first >> edges[i].second;
  }

  for (int i = 1; i <= q; i++) {
    cin >> questions[i].l >> questions[i].r >> questions[i].s >> questions[i].t;
    if (questions[i].s == questions[i].t) {
      is_yes[i] = 1;
      continue;
    }
    if (questions[i].l == questions[i].r) {
      int id = questions[i].l;
      is_yes[i] = (so(questions[i].s, questions[i].t) == so(edges[id].first, edges[id].second));
      continue;
    }
    qhere[questions[i].l].push_back(i);
    qhere_end[questions[i].r].push_back(i);
  }

  for (int i = 1; i <= m; i++) {
    sort(qhere[i].begin(), qhere[i].end(), cmpQR);
    sort(qhere_end[i].begin(), qhere_end[i].end(), cmpQL);
    reverse(qhere_end[i].begin(), qhere_end[i].end());
  }

  solve(1, m);

  for (int i = 1; i <= m; i++) {
    assert(qhere[i].empty());
  }

  for (int i = 1; i <= q; i++) {
    if (is_yes[i] == -1) {
      cout << "??\n";
      continue;
    }
    cout << (is_yes[i] ? "Yes" : "No") << "\n";
  }

  return 0;
}