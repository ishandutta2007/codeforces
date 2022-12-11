#include<bits/stdc++.h>

using namespace std;

const int S = 27;
struct node { int len, link, next[S]; };
struct tree_node { int t0[S], t1[S], next[S], k; };

typedef long long ll;

const int N = 200010;
int sz, last;
node v[N];
tree_node tree[N];
int T[N], Tsz;

inline void init() {
  sz = 1; last = 0; v[0].len = 0; v[0].link = -1;
  memset(v[0].next, -1, sizeof(v[0].next));
}

//crea el automata de la palabra invertida
inline void add(int c) {
  int nlast = sz++;
  v[nlast].len = v[last].len + 1;
  memset(v[nlast].next, -1, sizeof(v[nlast].next));
  int p = last;
  while (p != -1 && v[p].next[c] == -1) {
    v[p].next[c] = nlast; p = v[p].link;
  }
  if (p == -1) {
    v[nlast].link = 0;
  } else {
    int q = v[p].next[c];
    if (v[p].len + 1 == v[q].len) {
      v[nlast].link = q;
    } else {
      int clone = sz++;
      v[clone].len = v[p].len + 1;
      v[clone].link = v[q].link;
      memcpy(v[clone].next, v[q].next,
          sizeof(v[q].next));
      while (p != -1 && v[p].next[c] == q) {
        v[p].next[c] = clone; p = v[p].link;
      }
      v[nlast].link = v[q].link = clone;
    }
  }
  last = nlast;
}

//pone los indices que tocan a cada arista
int dfs_tree(int x) {
    int p[S];
    for (int i = 0; i < tree[x].k; ++i) p[i] = tree[x].next[i];
    memset(tree[x].next, -1, sizeof(tree[x].next));
    int minval = Tsz;
    for (int i = 0; i < tree[x].k; ++i) {
        int t1 = dfs_tree(p[i]) - 1;
        int t0 = t1 - v[p[i]].len + v[x].len + 1;
        minval = min(minval, t0);
        tree[x].next[T[t0]] = p[i];
        tree[x].t0[T[t0]] = t0;
        tree[x].t1[T[t0]] = t1;
    }
    return minval;
}

//crea el suffix tree a partir del automata
void suffix_tree(string& a) {
    Tsz = (int)a.size();
    for (int i = 0; i < Tsz; ++i) T[i] = a[i] - 'a';
    T[Tsz++] = S-1;
    init();
    for (int i = Tsz-1; i >= 0; --i) add(T[i]);
    for (int i = 0; i < sz; ++i) {tree[i].k = 0;}
    for (int i = 1; i < sz; ++i) tree[v[i].link].next[tree[v[i].link].k++] = i;
    dfs_tree(0);
}

ll res;

int dfs(int x, int s) {
    int conter = 0;
    for (int i = 0; i < S; ++i) {
        if (tree[x].next[i] == -1) continue;
        int next = tree[x].next[i];
//         for (int j = 0; j <= s; ++j) cerr << "--";
//         cerr << "> ";
//         for (int j = tree[x].t0[i]; j <= tree[x].t1[i]; ++j) cerr << char(T[j] + 'a');
//         cerr << endl;
        ll quants = dfs(next, s + tree[x].t1[i] - tree[x].t0[i] + 1);
        ll dist = tree[x].t1[i] - tree[x].t0[i] + 1;
        res += quants*dist*(quants + 1)/2;
        conter += quants;
//         for (int j = 0; j <= s; ++j) cerr << "--";
//             cerr << "> " << quants << endl;
    }
    if (!conter) return 1;
    return conter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a;
    cin >> a;
    suffix_tree(a);
    res = 0;
    dfs(0, 0);
    res -= (ll)a.size() + 1;
    cout << res << '\n';
}