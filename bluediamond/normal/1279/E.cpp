#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = (int) 2e18 + 7;
const int N = 50 + 7;
int dp[N];
int facts[N];

int add(int a, int b) {
  return min(a + b, INF);
}

int mul(int a, int b) {
  if (a == 0 || b == 0) return 0;
  if (a <= INF / b) return a * b;
  return INF;
}

int fact(int n) {
  if (n <= 1) {
    return 1;
  }
  return facts[n];
}

bool has_a_cycle_incomplete(vector<int> v) {
  int n = (int) v.size();
  vector<bool> vis(n, false);
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    int j = i;
    while (!vis[j]) {
      vis[j] = true;
      j = v[j];
      if (j == -1) break;
    }
    if (j == i) return true;
  }
  return false;
}

vector<int> get_kth_single_cycle_and_max(int n, int k) {

  vector<bool> used(n, false);
  vector<int> sol(n, -1);

  for (int pos = 0; pos + 1 < n; pos++) {
    vector<int> elems;


    for (int x = 0; x < n; x++) {
      if (used[x]) continue;
      sol[pos] = x;
      if (!has_a_cycle_incomplete(sol)) {
        elems.push_back(x);
      }
      sol[pos] = -1;
    }
    if (pos == 0) {
      elems = {n - 1};
    }
    int ptr = 0;
    while (k >= fact(n - 2 - pos)) {
      k -= fact(n - 2 - pos);
      ptr++;
    }
    sol[pos] = elems[ptr];
    used[sol[pos]] = true;
  }
  {
    vector<int> elems;
    for (int x = 0; x < n; x++) {
      if (used[x]) continue;
      elems.push_back(x);
    }
    sol[n - 1] = elems[0];
    used[sol[n - 1]] = true;
  }
  return sol;

}


void print(int n, int k, int add) {
  if (n == 0) {
    return;
  }
  for (int len = 1; len <= n; len++) {
    int cnt = fact(len - 2) * dp[n - len];
    if (k >= cnt) {
      k -= cnt;
      continue;
    }
    int w = 0;

    vector<int> v = get_kth_single_cycle_and_max(len, k / dp[n - len]);
    for (auto &x : v) {
      x += add;
      cout << x << " ";
    }
    print(n - len, k % dp[n - len], add + len);

    return;
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


  facts[0] = 1;
  for (int i = 1; i < N; i++) {
    facts[i] = mul(facts[i - 1], i);
  }

  dp[0] = 1;
  for (int i = 1; i < N; i++) {
    for (int len = 1; len <= i; len++) {
      dp[i] = add(dp[i], mul(fact(len - 2), dp[i - len]));
    }
  }

  int tests;
  cin >> tests;
  for (int tc = 1; tc <= tests; tc++) {
    int n, k;
    cin >> n >> k;
    k--;
    if (k >= dp[n]) {
      cout << "-1\n";
      continue;
    }
    print(n, k, 1);
    cout << "\n";
  }



}