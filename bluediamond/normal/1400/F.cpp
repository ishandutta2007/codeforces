#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> retgen;
vector<int> cur;
int papa;

void bkt(int sum) {
  if (sum == 0) {
    for (int l = 0; l < (int) cur.size(); l++) {
      int c = 0;
      for (int r = l; r < (int) cur.size(); r++) {
        c += cur[r];
        if (c >= papa) {
          break;
        }
        if (papa % c == 0) {
          return;
        }
      }
    }
    retgen.push_back(cur);
    return;
  }
  for (int d = 1; d <= min(9, sum); d++) {
    cur.push_back(d);
    bkt(sum - d);
    cur.pop_back();
  }
}

vector<vector<int>> gen(int x) {
  retgen.clear();
  papa = x;
  bkt(x);
  return retgen;
}

struct Trie {
  int blocked;
  Trie *kids[10];
  Trie *bk;
  Trie *nxt[10];
  int id;
  Trie() {
    blocked = 0;
    for (int i = 0; i < 10; i++) {
      kids[i] = 0;
      nxt[i] = 0;
    }
    id = 0;
    bk = 0;
  }
};

Trie *root = new Trie;

vector<Trie*> ord;

void calc() {
  queue<Trie*> q;
  q.push(root);
  root->bk = root;
  while (!q.empty()) {
    Trie *cur = q.front();
    q.pop();
    cur->id = (int) ord.size();
    ord.push_back(cur);
    for (int x = 1; x <= 9; x++) {
      if (cur->kids[x]) {
        q.push(cur->kids[x]);
        Trie *now = cur->kids[x];
        if (cur == root) {
          now->bk = root;
          continue;
        }
        now = cur->bk;
        while (now != root && !now->kids[x]) {
          now = now->bk;
        }
        if (now->kids[x]) {
          now = now->kids[x];
        }
        cur->kids[x]->bk = now;
      }
    }
  }
  for (auto &cur : ord) {
    for (int x = 1; x <= 9; x++) {
      Trie *now = cur;
      while (now != root && !now->kids[x]) {
        now = now->bk;
      }
      if (now->kids[x]) {
        now = now->kids[x];
      }
      cur->nxt[x] = now;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  int x;
  cin >> s >> x;
  vector<vector<int>> all = gen(x);
  for (auto &vec : all) {
    Trie *cur = root;
    for (auto &x : vec) {
      if (!cur->kids[x]) {
        cur->kids[x] = new Trie;
      }
      cur = cur->kids[x];
    }
    cur->blocked = 1;
  }
  calc(); /// nu trebuie sa propagam blocked ca nu o sa se intalneasca astea :)))) Sunt un calut fericit
  vector<int> dp((int) ord.size(), (int) 1e9);
  dp[0] = 0;
  for (auto &ch : s) {
    int x = ch - '0';
    vector<int> dp2((int) ord.size(), (int) 1e9);
    for (int i = 0; i < (int) ord.size(); i++) {
      if (dp[i] == (int) 1e9) {
        continue;
      }
      Trie *cur = ord[i];
      dp2[cur->id] = min(dp2[cur->id], dp[cur->id] + 1);
      Trie *cur2 = cur->nxt[x];
      if (!cur2->blocked) {
        dp2[cur2->id] = min(dp2[cur2->id], dp[cur->id]);
      }
    }
    dp = dp2;
  }
  int sol = (int) 1e9;
  for (auto &it : dp) {
    sol = min(sol, it);
  }
  cout << sol << "\n";
  return 0;
}