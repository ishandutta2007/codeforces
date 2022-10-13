#include <bits/stdc++.h>

using namespace std;

struct AhoCorasick {
  struct Node {
    int link, fin, ans, jump;
    map<char, int> leg;
  };
  int n;
  vector<Node> T;
  vector<string> words;
  vector<int> fin;

  int root = 0, nodes = 1;

  AhoCorasick(vector<string>&& words) : 
      n(words.size()), words(words), fin(n) {
    int sz = 1;
    for (auto& w : words)
      sz += w.size();
    T.resize(sz, Node{-1, 0, 0, -1, {}});

    for (int i = 0; i < n; ++i) {
      int node = AddWord(words[i]);
      T[node].fin = true;
      fin[i] = node;
    }
    
    auto topo = Build();
    for (auto node : topo) {
      int link = T[node].link;
      if (link == -1) {
        T[node].jump = -1;
      } else if (T[link].fin) {
        T[node].jump = link;
      } else {
        T[node].jump = T[link].jump;
      }
    }
  }

  int AddWord(const string &word) {
    int node = root;
    for (auto c : word) {
      auto &nxt = T[node].leg[c];
      if (nxt == 0) nxt = nodes++;
      node = nxt;
    }
    return node;
  }

  int Advance(int node, char chr) {
    while (node != -1 && T[node].leg.count(chr) == 0)
      node = T[node].link;
    if (node == -1) return root;
    return T[node].leg[chr];
  }

  vector<int> Build() {
    vector<int> order = {root};
    T[root].link = -1;

    for (int i = 0; i < (int)order.size(); ++i) {
      int node = order[i];
      for (auto &p : T[node].leg) {
        int vec = p.second;
        char chr = p.first;
        T[vec].link = Advance(T[node].link, chr);
        order.push_back(vec);
      }
    }
    return order;
  }

  void Process(int i) {
    int node = 0;
    for (auto c : words[i]) {
      node = Advance(node, c);
      for (int x = node; x != -1; x = T[x].jump) {
        T[x].ans += 1;
      }
    }
  }

  int Get(int x) {
    return T[fin[x]].ans;
  }
};

int main() {
  int n, q; cin >> n >> q;
  vector<string> words(n);
  for (int i = 0; i < n; ++i) 
    cin >> words[i];

  AhoCorasick aho(move(words));

  vector<tuple<int, int, int, int>> qrs;
  for (int i = 0; i < q; ++i) {
    int l, r, k; cin >> l >> r >> k; --l; --r; --k;
    qrs.emplace_back(l - 1, k, -1, i);
    qrs.emplace_back(r, k, 1, i);
  }
  sort(qrs.begin(), qrs.end());

  int at = -1;
  vector<long long> ans(q, 0);
  for (auto q : qrs) {
    int p, k, coef, i; tie(p, k, coef, i) = q;
    while (at < p) 
      aho.Process(++at);
    ans[i] += coef * aho.Get(k);
  }

  for (int i = 0; i < q; ++i)
    cout << ans[i] << '\n';

  return 0;
}