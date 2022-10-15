#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int T = (int) 1e7;
const int B = 17;

struct Vertex {
  int sub;
  int c[2];
} verts[T];

int first_free;
int root;

int get_new_vertex() {
  verts[first_free].sub = 0;
  verts[first_free].c[0] = 0;
  verts[first_free].c[1] = 0;
  return first_free++;
}

void rst() {
  root = 1;
  first_free = 1;
  get_new_vertex();
}

int has(int x, int bit) {
  return !!(x & (1 << bit));
}

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int tests;
  cin >> tests;
  for (int tc = 1; tc <= tests; tc++) {
    int l, r, n;
    cin >> l >> r;
    n = r - l + 1;
    vector<int> a(n);
    set<int> s;
    rst();
    for (auto &x : a) {
      cin >> x;
      s.insert(x);
      int cur = root;
      verts[cur].sub++;
      for (int bit = B - 1; bit >= 0; bit--) {
        int value = has(x, bit);
        if (!verts[cur].c[value]) {
          verts[cur].c[value] = get_new_vertex();
        }
        cur = verts[cur].c[value];
        verts[cur].sub++;
      }
    }
    if (n == 1) {
      cout << (l ^ a[0]) << "\n";
      continue;
    }
    int solution = -1;
    for (int IL = 0; IL < n; IL++) {
      int x = l ^ a[IL];
      int bit = B - 1;
      while (has(l, bit) == has(r, bit)) {
        bit--;
      }
      int inside = 0;
      inside += s.count(l ^ x);
      inside += s.count(r ^ x);
      int cur = root;
      bool fl = 0;
      for (int j = B - 1; j > bit; j--) {
        int value = has(l, j) ^ has(x, j);
        if (!verts[cur].c[value]) {
          fl = 1;
          break;
        }
        cur = verts[cur].c[value];
      }
      if (fl) {
        continue;
      }
      int st = cur;
      {
        fl = 0;
        int urm = bit;
        for (int i = bit - 1; i >= 0 && !fl; i--) {
          if (has(l, i) == 0) {
            while (urm > i) {
              int value = has(l, urm) ^ has(x, urm);
              if (!verts[cur].c[value]) {
                fl = 1;
                break;
              }
              cur = verts[cur].c[value];
              urm--;
            }
            if (fl) {
              break;
            }
            inside += verts[verts[cur].c[has(x, i) ^ 1]].sub;
          }
        }
        /// r case
        fl = 0;
        urm = bit;
        cur = st;
        for (int i = bit - 1; i >= 0; i--) {
          if (has(r, i) == 1) {
            while (urm > i) {
              int value = has(r, urm) ^ has(x, urm);
              if (!verts[cur].c[value]) {
                fl = 1;
                break;
              }
              cur = verts[cur].c[value];
              urm--;
            }
            if (fl) {
              break;
            }
            inside += verts[verts[cur].c[has(x, i)]].sub;
          }
        }
      }
      if (inside == n) {
        cout << x << "\n";
        break;
      }
    }
  }


  return 0;
}