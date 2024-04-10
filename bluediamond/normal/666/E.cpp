#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int SumN = (int) 5e4 + 7;
const int T = (int) 1e7 + 7;
const int N = (int) 5e5 + 7;
const int K = 16;
int ant[K][2 * SumN];

struct State {
  int len, link, dp;
  map<char, int> nxt;
};

struct MX {
  int mx;
  int who;
};

MX operator + (MX a, MX b) {
  if (a.mx == b.mx) {
    if (a.who < b.who) {
      return a;
    } else {
      return b;
    }
  }
  if (a.mx > b.mx) {
    return a;
  } else {
    return b;
  }
}

struct Vertex {
  int lft_kid, rgh_kid;
  MX dt;
};

Vertex t[T];
int cnt_nodes;

void pull(int current_node) {
  int lft_kid = t[current_node].lft_kid;
  int rgh_kid = t[current_node].rgh_kid;
  t[current_node].dt = t[lft_kid].dt + t[rgh_kid].dt;
}

void ins(int &current_node, int tl, int tr, int index) {
  assert(tl <= index && index <= tr);
  if (!current_node) {
    current_node = ++cnt_nodes;
  }
  if (tl == tr) {
    assert(tl == index);
    assert(tr == index);
    t[current_node].dt = {1, index};
    assert(t[current_node].dt.who == tl);
    //cout << "\t\t\t\t" << current_node << " ---> " << tl << "\n";
    return;
  }
  int tm = (tl + tr) / 2;
  if (index <= tm) {
    ins(t[current_node].lft_kid, tl, tm, index);
  } else {
    ins(t[current_node].rgh_kid, tm + 1, tr, index);
  }
  pull(current_node);
}

int join(int r1, int r2, int tl, int tr) {
  if (!r1) {
    return r2;
  }
  if (!r2) {
    return r1;
  }
  int new_root = ++cnt_nodes;
  if (tl == tr) {
    assert(t[r1].dt.who == tl);
    assert(t[r2].dt.who == tl);
    t[new_root].dt.mx = t[r1].dt.mx + t[r2].dt.mx;
    t[new_root].dt.who = tl;
  ///  cout << "join : " << t[new_root].dt.mx << "\n";
    return new_root;
  }
  int tm = (tl + tr) / 2;
  t[new_root].lft_kid = join(t[r1].lft_kid, t[r2].lft_kid, tl, tm);
  t[new_root].rgh_kid = join(t[r1].rgh_kid, t[r2].rgh_kid, tm + 1, tr);

  pull(new_root);
  return new_root;
}

MX get(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl || !v) {
    return {0, 0};
  }
  if (l <= tl && tr <= r) {
    return t[v].dt;
  }
  int tm = (tl + tr) / 2;
  return get(t[v].lft_kid, tl, tm, l, r) + get(t[v].rgh_kid, tm + 1, tr, l, r);
}

State st[2 * SumN];
int sz, last;

void init() {
  sz = last = 0;
  st[0].len = 0;
  st[0].link = -1;
  st[0].dp = 0;
  sz++;
}

void extend(char ch) {
  if (st[last].nxt.count(ch)) {
    int p = last;
    int q = st[p].nxt[ch];
    if (st[p].len + 1 == st[q].len) {
      last = q;
      return;
    }
    int clone = sz++;
    st[clone].len = st[p].len + 1;
    st[clone].nxt = st[q].nxt;
    st[clone].link = st[q].link;
    while (p != -1 && st[p].nxt.count(ch) && st[p].nxt[ch] == q) {
      st[p].nxt[ch] = clone;
      p = st[p].link;
    }
    st[q].link = clone;
    last = clone;
    return;
  }
  int cur = sz++;
  st[cur].len = st[last].len + 1;
  int p = last;
  while (p != -1 && !st[p].nxt.count(ch)) {
    st[p].nxt[ch] = cur;
    p = st[p].link;
  }
  if (p == -1) {
    st[cur].link = 0;
  } else {
    int q = st[p].nxt[ch];
    if (st[q].len == 1 + st[p].len) {
      st[cur].link = q;
    } else {
      int clone = sz++;
      st[clone].len = st[p].len + 1;
      st[clone].nxt = st[q].nxt;
      st[clone].link = st[q].link;
      while (p != -1 && st[p].nxt.count(ch) && st[p].nxt[ch] == q) {
        st[p].nxt[ch] = clone;
        p = st[p].link;
      }
      st[q].link = st[cur].link = clone;
    }
  }
  last = cur;
}

bool vis[2 * SumN];
vector<int> g[2 * SumN];
int root[N];
string s;
int ls;
int cnt_words;


void dfs(int a) {
  for (int i = 1; i < K; i++) {
    ant[i][a] = ant[i - 1][ant[i - 1][a]];
  }
  assert(vis[a] == 0);
  vis[a] = 1;
  for (auto &it : g[a]) {
    ant[0][it] = a;
    assert(st[a].len < st[it].len);
    dfs(it);
    root[a] = join(root[a], root[it], 1, cnt_words);
  }
}

int lmax[N];
int wstate[N];
string wo[SumN];

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
    freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE


  string s;
  cin >> s;
  ls = (int) s.size();
  cin >> cnt_words;
  init();
  for (int i = 0; i < cnt_words; i++) {
    last = 0;
    string word;
    cin >> word;
    wo[i + 1] = word;
    int dm = 0;
    for (auto &ch : word) {
      extend(ch);
      dm++;
      assert(st[last].len >= dm);
      ins(root[last], 1, cnt_words, i + 1);
    }
  }
  for (int i = 1; i < sz; i++) {
    g[st[i].link].push_back(i);
  }
 /// if (ls >= 100) exit(0);
  dfs(0);
  for (int i = 0; i < sz; i++) {
    assert(vis[i]);
    /**if (!vis[i]) {
      cout << "bad i = " << i << ", len = " << st[i].len << "\n";
    }**/
  }
  int state = 0, l = 0;
  for (int i = 0; i < ls; i++) {
    while (state && !st[state].nxt[s[i]]) {
      state = st[state].link;
      l = st[state].len;
    }
    if (st[state].nxt[s[i]]) {
      state = st[state].nxt[s[i]];
      l++;
    }
    wstate[i] = state;
    lmax[i] = l;
  }

  /**
  cout << " ---> ";
  for (auto &x : topsort) {
    cout << x << " ";
  }
  cout << "\n";
  **/

  int q;
  cin >> q;
  for (int iq = 1; iq <= q; iq++) {
    int l, r, a, b;
    cin >> l >> r >> a >> b;
    a--;
    b--;
    int p = wstate[b];
    if (lmax[b] < b - a + 1) {
      cout << l << " " << 0 << "\n";
      continue;
    }
    for (int k = K - 1; k >= 0; k--) {
      if (st[ant[k][p]].len >= b - a + 1) {
        p = ant[k][p];
      }
    }
    MX sol = get(root[p], 1, cnt_words, l, r);
    if (sol.mx == 0) {
      sol.who = l;
    }
   /** if (iq == 33) {
      /// wrong answer 33rd lines differ - expected: '3 0', found: '15 1'
      cout << l << " " << r << " " << " : " << sol.who << " " << sol.mx << "\n";
      cout << ls << "\n";
      cout << (int) wo[15].size() << "\n";
      ///cout << wo[15] << "\n";
      continue;
    }
    if (ls >= 100) {
     /// continue;
    }**/
    cout << sol.who << " " << sol.mx << "\n";
  }

  return 0;
}