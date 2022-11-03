#include <bits/stdc++.h>
#define ll long long
#define db long double
#define ull unsigned long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

#define pper(a) cerr << #a << " = " << a << endl;

void per() { cerr << endl; }
template<typename Head, typename... Tail> void per(Head H, Tail... T) { cerr << H << ' '; per(T...); }

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

template<class U, class V> 
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.x << ", " << a.y << ")";
}

template<class U, class V> 
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.x >> a.y;
}

template<typename W, typename T = typename enable_if<!is_same<W, string>::value, typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) { out << "{ "; for (const auto& x : v) out << x << ", "; return out << '}'; }

template<class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}

struct Node {
  int p, r;
};

struct DSU {
  static const int SZ = 5e6;
  Node t[SZ];

  DSU() { reset(SZ); }

  void reset(int n) {
    for (int i = 0; i < n; ++i) {
      t[i].p = i;
      t[i].r = 0;
    }
  }

  int get(int v) {
    if (t[v].p == v) return v;
    return t[v].p = get(t[v].p);
  }

  void merge(int a, int b) {
   // per("merge: ", a, b);
    a = get(a), b = get(b);
    if (a != b) {
      if (t[a].r < t[b].r) swap(a, b);
      t[b].p = a;
      if (t[a].r == t[b].r) ++t[a].r;
    }
  }
} dsu;

struct TrieNode {
  int to[2];
  int stop;
  ll mask;
  int len;
  bool zest;
  TrieNode() { to[0] = to[1] = -1; stop = len = mask = zest = 0; }
} tr[5000000];

int n, m;
pair<string, pair<ll, ll>> a[50007]; 
pair<ll, ll> b[50007];
int sz = 1;

vector<pair<int, pair<ll, ll>>> st;
void add(ll vl, ll vr, ll l, ll r, int v = 0, int len = 0, ll mask = 0) {
//  per(vl, vr, l, r, v);
  if (l > r) return;
  if (r < vl || l > vr) return;

  tr[v].mask = mask;
  tr[v].len = len;

  tr[v].stop = 0;

  if (vl >= l && vr <= r) {
    tr[v].stop = tr[v].zest = 1;
    st.pb(mp(v, mp(vl, vr)));
  } else {
    ll vm = (vl + vr) >> 1;

    if (max(l, vl) <= min(r, vm)) {
      if (tr[v].to[0] == -1) tr[v].to[0] = sz++;
      add(vl, vm, l, r, tr[v].to[0], len + 1, mask);
    }
    if (max(l, vm + 1) <= min(r, vr)) {
      if (tr[v].to[1] == -1) tr[v].to[1] = sz++;
      add(vm + 1, vr, l, r, tr[v].to[1], len + 1, mask ^ ((ll)1 << len));
    }
  }
}

void kek(int v) {
  if (tr[v].stop) return;
  tr[v].stop = 1;
  for (int to = 0; to < 2; ++to) if (tr[v].to[to] != -1) {
    dsu.merge(v, tr[v].to[to]);
    kek(tr[v].to[to]);
  }
}

void go(int root) {
  ll mask = tr[root].mask;
  int len = tr[root].len;
  int v = 0;

  for (int i = 0; i < len; ++i) {
    int go = (mask >> i) & 1;

    if (tr[v].to[go ^ 1] != -1) {
      int cp = tr[v].to[go ^ 1];

      if (tr[cp].zest) {
        dsu.merge(cp, root);
        break;
      } else {

        int need = 1;

        for (int j = i + 1; j < len; ++j) {

          int goo = (mask >> j) & 1;
          if (tr[cp].to[goo] == -1) {
            need = 0;
            break;
          }
          cp = tr[cp].to[goo];

          if (tr[cp].zest) {
            need = 0;
            dsu.merge(cp, root);
            break;
          }
        }

        if (need) {
          dsu.merge(cp, root);
          kek(cp);
        }

      }

    }

    if (tr[v].to[go] == -1) return;
    v = tr[v].to[go];
    if (tr[v].zest) {
      dsu.merge(v, root); return;
    }
  }
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> m;
  readArr(a, a + m);

  int k = 0;
  for (int i = 0; i < m; ++i) if (a[i].x[0] == 'b') b[k++] = a[i].y;

  sort(b, b + k);
  
  if (k == 0) {
    add(0, ((ll)1 << n) - 1, 0, ((ll)1 << n) - 1);
  } else {
    add(0, ((ll)1 << n) - 1, 0, b[0].x - 1);
    for (int i = 0; i + 1 < k; ++i)
      add(0, ((ll)1 << n) - 1, b[i].y + 1, b[i + 1].x - 1);
    add(0, ((ll)1 << n) - 1, b[k - 1].y + 1, ((ll)1 << n) - 1);
  }
  
  set<pair<pair<ll, ll>, int> > se;
  for (auto c : st) go(c.x), se.insert(mp(mp(c.y.y, c.y.x), c.x));
  st.clear();

  vector<int> res;

 // pper(se);
  
  for (int i = m - 1; i >= 0; --i) {
    ll vl = a[i].y.x;
    ll vr = a[i].y.y;

    if (a[i].x[0] == 'a') {

      auto v1 = se.lower_bound(mp(mp(vl, -1), -1))->second;
      auto v2 = se.lower_bound(mp(mp(vr, -1), -1))->second;
      res.pb(dsu.get(v1) == dsu.get(v2));

    } else {

      add(0, ((ll)1 << n) - 1, vl, vr);
      for (auto c : st) go(c.x), se.insert(mp(mp(c.y.y, c.y.x), c.x));
      st.clear();

    }
  
  }
  
  reverse(all(res));
  for (int x : res) cout << x << "\n";


}