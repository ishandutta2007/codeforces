#include <bits/stdc++.h>

using namespace std;

bool home = 1;
#define int ll
typedef long long ll;
typedef long double ld;

signed realMain();

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



const int N = 1000 + 7;
int n, cost[N], y;
string s, v[N];

struct node {
  node* k[14];
  node* to;
  string val; /// delete later
  int cost;
  int id;
  node() {
    id = 0;
    val = "";
    for (int j = 0; j < 14; j++) {
      k[j] = 0;
    }
    cost = 0;
    to = 0;
  }
};

node* root = new node;

vector<node*> ord;

void bfs() {
  queue<node*> q;
  q.push(root);
  while (!q.empty()) {
    node *now = q.front();
    ord.push_back(now);
    q.pop();
    for (int j = 0; j < 14; j++) {
      if (now->k[j]) {
        q.push(now->k[j]);
      }
    }
  }
}

void build() {
  root->id = ++y;
  for (int i = 1; i <= n; i++) {
    node* now = root;
    for (auto &ch : v[i]) {
      int x = ch - 'a';
      if (!now->k[x]) {
        now->k[x] = new node;
        now->k[x]->id = ++y;
        now->k[x]->val = now->val + ch;
      }
      now = now->k[x];
    }
    now->cost += cost[i];
  }
  bfs();
  root->to = root;
  for (auto &now : ord) {
    for (int j = 0; j < 14; j++) {
      if (now->k[j]) {
        node* sol = now->to;
        while (sol != root && !sol->k[j]) {
          sol = sol->to;
        }
        if (now != root && sol->k[j]) {
          sol = sol->k[j];
        }
        now->k[j]->to = sol;
      }
    }
  }
  for (auto &now : ord) {
    now->cost += now->to->cost;
  }
}

const int K = 14;
const int INF = (int) 1e18;
int urm[N][K], gain[N];
string what[N];
int after_state[K + 7][N], after_gain[K + 7][N];
int dp[1 << K][N];

signed realMain() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i] >> cost[i];
  }
  cin >> s;
  build();
  for (auto &now : ord) {
    what[now->id] = now->val;
    gain[now->id] = now->cost;
    for (int j = 0; j < 14; j++) {
      node* ret = now;
      while (ret != root && !ret->k[j]) {
        ret = ret->to;
      }
      if (ret->k[j]) {
        ret = ret->k[j];
      }
      urm[now->id][j] = ret->id;
    }
  }
  int sz = (int) s.size(), qs = 0;
  vector<int> questions = {-1};
  for (int j = 0; j < sz; j++) {
    if (s[j] == '?') {
      qs++;
      questions.push_back(j);
    }
  }
  questions.push_back(sz);
  for (int j = 0; j + 1 < (int) questions.size(); j++) {
    int l = questions[j] + 1, r = questions[j + 1] - 1;
    for (int state = 1; state <= y; state++) {
      int now_state = state, now_gain = 0;
      for (int j = l; j <= r; j++) {
        now_state = urm[now_state][s[j] - 'a'];
        now_gain += gain[now_state];
      }
      after_state[j][state] = now_state;
      after_gain[j][state] = now_gain;
    }
  }
  for (int mask = 0; mask < (1 << K); mask++) {
    for (int i = 1; i <= y; i++) {
      dp[mask][i] = -INF;
    }
  }
  dp[0][1] = 0;
  int ret = -INF;
  for (int mask = 0; mask < (1 << K); mask++) {
    for (int i = 1; i <= y; i++) {
      if (dp[mask][i] == -INF) continue;
      int cnt = 0;
      for (int bit = 0; bit < K; bit++) {
        if (mask & (1 << bit)) {
          cnt++;
        }
      }
      if (cnt == qs) {
        int relax = dp[mask][i] + after_gain[cnt][i];
        ret = max(ret, relax);
        continue;
      }
      assert(cnt < qs);
      for (int bit = 0; bit < K; bit++) {
        if (!(mask & (1 << bit))) {
          int new_mask = mask + (1 << bit);
          int state = urm[after_state[cnt][i]][bit];
          int relax = dp[mask][i] + after_gain[cnt][i] + gain[state];
          dp[new_mask][state] = max(dp[new_mask][state], relax);
        }
      }
    }
  }
  cout << ret << "\n";
  return 0;
}