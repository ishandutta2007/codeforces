#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct T {
  int id;
  int c1;
  int c2;
};

bool operator < (T a, T b) {
  if (a.c1 != b.c1) {
    return a.c1 < b.c1;
  } else {
    return a.c2 < b.c2;
  }
}


const int N = 200000 + 7;
int n;
int top;
int p[N];
int c[N];
int f[N];
int tab[N];
int kol[N];
int ant[N];
int nxt[N];
int stk[N];
int tree[4 * N];
string s;

void build(int v, int tl, int tr) {
  if (tl == tr) {
    tree[v] = tab[tl];
  } else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    tree[v] = min(tree[2 * v], tree[2 * v + 1]);
  }
}

void build() {
  build(1, 0, n - 1);
}

int get_min(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) {
    return N;
  }
  if (l <= tl && tr <= r) {
    return tree[v];
  } else {
    int tm = (tl + tr) / 2;
    return min(get_min(2 * v, tl, tm, l, r), get_min(2 * v + 1, tm + 1, tr, l, r));
  }
}

int get_min(int l, int r) {
  return get_min(1, 0, n - 1, l, r);
}

vector<T> so(vector<T> a) {
  int n = (int) a.size();
  vector<T> b(n);
  int mc = 0;
  for (auto &it : a) {
    mc = max(mc, it.c1);
    mc = max(mc, it.c2);
  }
  for (int i = 0; i <= mc; i++) {
    f[i] = 0;
  }
  for (auto &it : a) {
    f[it.c2]++;
  }
  for (int i = 1; i <= mc; i++) {
    f[i] += f[i - 1];
  }
  for (int i = 0; i < n; i++) {
    b[--f[a[i].c2]] = a[i];
  }
  for (int i = 0; i <= mc; i++) {
    f[i] = 0;
  }
  for (auto &it : b) {
    f[it.c1]++;
  }
  for (int i = 1; i <= mc; i++) {
    f[i] += f[i - 1];
  }
  for (int i = n - 1; i >= 0; i--) {
    a[--f[b[i].c1]] = b[i];
  }
  return a;
}

int lcp(int i, int j) {
  i = c[i];
  j = c[j];
  if (i == j) {
    return kol[i];
  }
  if (i > j) {
    swap(i, j);
  }
  return get_min(i + 1, j);
}

bool ko;

bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.second == b.second) {
    return (a.first > b.first) ^ ko;
  } else {
    return c[a.second] < c[b.second];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int q;
  cin >> n >> q >> s;
  s += "$";
  n = (int) s.size();
  for (int i = 0; i < n; i++) {
    f[s[i]]++;
  }
  for (int x = 1; x < 1000; x++) {
    f[x] += f[x - 1];
  }
  for (int i = 0; i < n; i++) {
    p[--f[s[i]]] = i;
    c[i] = s[i];
  }
  for (int l = 1; l <= n; l *= 2) {
    vector<T> vec;
    for (int i = 0; i < n; i++) {
      vec.push_back({i, c[i], c[(i + l) % n]});
    }
    vec = so(vec);
    for (int i = 0; i < n; i++) {
      p[i] = vec[i].id;
    }
    c[vec[0].id] = 0;
    int cur = 0;
    for (int i = 1; i < n; i++) {
      if (vec[i - 1].c1 != vec[i].c1 || vec[i - 1].c2 != vec[i].c2) {
        cur++;
      }
      c[vec[i].id] = cur;
    }
  }
  int k = 0;
  for (int i = 0; i < n - 1; i++) {
    int pi = c[i];
    int j = p[pi - 1];
    while (s[i + k] == s[j + k]) {
      k++;
    }
    tab[pi] = k;
    k = max(0, k - 1);
  }
  for (int i = 0; i < n; i++) {
    kol[c[i]] = n - i - 1;
  }
  build();
  top =0 ;
  stk[0] = -1;
  for (int i = 0; i < n; i++) {
    while (top && tab[i] <= tab[stk[top]]) {
      top--;
    }
    ant[i] = stk[top];
    stk[++top] = i;
  }
  top = 0;
  stk[0] = n;
  for (int i = n - 1; i >= 0; i--) {
    while (top && tab[i] < tab[stk[top]]) {
      top--;
    }
    nxt[i] = stk[top];
    stk[++top] = i;
  }
  while (q--) {
    int l1, l2;
    cin >> l1 >> l2;
    vector<int> v1(l1), v2(l2);
    ll sol = 0;
    for (auto &p : v1) {
      cin >> p;
      p--;
    }
    for (auto &p : v2) {
      cin >> p;
      p--;
    }
    vector<pair<int, int>> vec;
    for (auto &p : v1) {
      vec.push_back({1, p});
    }
    for (auto &p : v2) {
      vec.push_back({2, p});
    }
    ko = 1;
    sort(vec.begin(), vec.end(), cmp);
    ko = 0;
    map<int, int> mp;
    ll sum = 0;
    int ant = -1;
    for (auto &it : vec) {
      int i = it.second;
      if (ant != -1) {
        int x = lcp(ant, i);
        while (!mp.empty()) {
          auto it = mp.end();
          it--;
          if (it->first > x) {
            sum -= (ll) it->first * it->second;
            sum += (ll) x * it->second;
            mp[x] += it->second;
            mp.erase(it);
          } else {
            break;
          }
        }
      }
      ant = i;
      if (it.first == 1) {
        sum += n - i - 1;
        mp[n - i - 1]++;
      } else {
        sol += sum;
      }
    }
    for (auto &it : vec) {
      it.first = 3 - it.first;
    }
    sort(vec.begin(), vec.end(), cmp);
    mp.clear();
    sum = 0;
    ant = -1;
    for (auto &it : vec) {
      int i = it.second;
      if (ant != -1) {
        int x = lcp(ant, i);
        while (!mp.empty()) {
          auto it = mp.end();
          it--;
          if (it->first > x) {
            sum -= (ll) it->first * it->second;
            sum += (ll) x * it->second;
            mp[x] += it->second;
            mp.erase(it);
          } else {
            break;
          }
        }
      }
      ant = i;
      if (it.first == 1) {
        sum += n - i - 1;
        mp[n - i - 1]++;
      } else {
        sol += sum;
      }
    }
    cout << sol << "\n";
  }
}