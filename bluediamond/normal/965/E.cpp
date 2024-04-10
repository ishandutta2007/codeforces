#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct trie {
  int id;
  trie *kids[26];
  trie() {
    id = 0;
    for (int i = 0; i < 26; i++) {
      kids[i] = 0;
    }
  }
};

trie *root = new trie;
const int N = (int) 1e5 + 7;
int n, dep[N];
vector<int> g[N];
bool fin[N];

void ins(string s) {
  trie *cur = root;
  for (auto &ch : s) {
    int x = ch - 'a';
    if (!cur->kids[x]) {
      cur->kids[x] = new trie;
      cur->kids[x]->id = ++n;
      dep[n] = 1 + dep[cur->id];
      g[cur->id].push_back(n);
    }
    cur = cur->kids[x];
  }
  fin[cur->id] = 1;
}

int point[N];
multiset<int> s[N];

void dfs(int a) {
  int c = a;
  for (auto &b : g[a]) {
    dfs(b);
    if ((int) s[point[b]].size() > (int) s[c].size()) {
      c = point[b];
    }
  }
  point[a] = c;
  for (auto &b : g[a]) {
    if (point[b] != c) {
      for (auto &deps : s[point[b]]) {
        s[c].insert(deps);
      }
    }
  }
  if (fin[a]) {
    s[c].insert(dep[a]);
  } else {
    if (!s[c].empty()) {
      auto it = s[c].end();
      it--;
      s[c].erase(it);
      s[c].insert(dep[a]);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int cnt;
  cin >> cnt;
  while (cnt--) {
    string s;
    cin >> s;
    ins(s);
  }
  ll sum = 0;
  for (auto &vec : g[0]) {
    dfs(vec);
    for (auto &deps : s[point[vec]]) {
      sum += deps;
    }
  }
  cout << sum << "\n";
}