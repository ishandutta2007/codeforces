#include <bits/stdc++.h>

using namespace std;

bool home = 1;
#define int ll
typedef long long ll;
///typedef long double ld;
typedef unsigned long long ull;

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

int n, k, y;

struct node {
  int pay, id;
  node* k[10];
  node() {
    id = 0;
    pay = 0;
    for (int j = 0; j < 10; j++) {
      k[j] = 0;
    }
  }
};

node* root = new node;
const int N = 500 + 7; /// change to 500
const int K = 12;
const int INF = (int) 1e18;
int dp[N][N][K]; /// dp[node][height difference][number of things used]
int nw[N][K];

string s;
void dfs(node* now, int h) {
  int id = now->id;
  for (int dif = 0; dif < h; dif++) {
    for (int cnt = 0; cnt < K; cnt++) {
      dp[id][dif][cnt] = now->pay * dif;
    }
  }
  for (int digit = 0; digit <= 9; digit++) {
    if (!now->k[digit]) {
      continue;
    }
    s += (char) (digit + '0'); dfs(now->k[digit], h + 1); s.pop_back();
    int id_k = now->k[digit]->id;
    for (int dif = 0; dif < h; dif++) {
      for (int cnt = 0; cnt < K; cnt++) {
        nw[dif][cnt] = INF;
        for (int from = 0; from <= cnt; from++) {
          nw[dif][cnt] = min(nw[dif][cnt], dp[id][dif][cnt - from] + dp[id_k][dif + 1][from]);
        }
      }
    }
    for (int dif = 0; dif < h; dif++) {
      for (int cnt = 0; cnt < K; cnt++) {
        dp[id][dif][cnt] = nw[dif][cnt];
      }
    }
  }
  for (int dif = 1; dif < h; dif++) {
    for (int cnt = 1; cnt < K; cnt++) {
      dp[id][dif][cnt] = min(dp[id][dif][cnt], dp[id][0][cnt - 1]);
    }
  }
}

signed realMain() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < K; k++) {
        dp[i][j][k] = INF;
      }
    }
  }
  cin >> n >> k;
  root->id = ++y;
  for (int i = 1; i <= n; i++) {
    string s;
    int cost;
    cin >> s >> cost;
    node* now = root;
    for (auto &ch : s) {
      int digit = ch - '0';
      if (!now->k[digit]) {
        now->k[digit] = new node;
        now->k[digit]->id = ++y;
      }
      now = now->k[digit];
    }
    now->pay += cost;
  }
  dfs(root, 1);
  cout << dp[1][0][k] << "\n";
  return 0;
}