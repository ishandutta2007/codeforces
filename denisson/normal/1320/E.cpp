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
 
int n, q;
vector<int> g[200007];
 
int tin[200007];
int tout[200007];
int up[200007][18];
int h[200007];
int tt = 0;
 
void dfs(int v = 0, int p = 0, int hh = 0) {
  up[v][0] = p;
  for (int i = 1; i < 18; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
  tin[v] = tt++;
  h[v] = hh;
 
  for (int to : g[v]) if (to != p) dfs(to, v, hh + 1);
 
  tout[v] = tt - 1;
}
 
bool isPred(int a, int b) {
  return tin[a] <= tin[b] && tout[b] <= tout[a];
}
 
int getLCA(int a, int b) {
  if (isPred(a, b)) return a;
  if (isPred(b, a)) return b;
  for (int i = 17; i >= 0; --i) if (!isPred(up[a][i], b)) a = up[a][i];
  return up[a][0];
}
 
vector< pair<int, int> > r[200007];
int speed[200007];
int di[200007];
 
pair<int, int> e[200007];
 
int main(){
#ifdef LOCAL
  freopen("A_input.txt", "r", stdin);
  //freopen("A_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int w1, w2;
    cin >> w1 >> w2;
    --w1; --w2;
    g[w1].pb(w2);
    g[w2].pb(w1);
  }
 
  dfs();
 
  cin >> q;
  while (q--) {
    int k, m;
    cin >> k >> m;
    vector<pair<int, int> > t(k);
    vector<int> d(m);
    readArr(all(t)); readArr(all(d));
 
    for (auto& c : d) --c;
    for (auto& c : t) --c.x;
 
    vector<int> p = d;
    for (auto [w1, w2] : t) p.pb(w1);
    sort(all(p), [](int a, int b) {
      return tin[a] < tin[b];
    });
 
    int sz = p.size();
    for (int i = 0; i + 1 < sz; ++i) {
      p.pb(getLCA(p[i], p[i + 1]));
    }
 
    sort(all(p), [](int a, int b) {
      return tin[a] < tin[b];
    });
    p.resize(unique(all(p)) - p.begin());
 
    vector<int> st;
    for (int v : p) {
      while (st.size() && !isPred(st.back(), v)) st.pop_back();
      // if (st.size()) per(st.back(), v);
      if (st.size()) r[st.back()].pb(mp(v, h[v] - h[st.back()])), r[v].pb(mp(st.back(), h[v] - h[st.back()]));
      st.pb(v);  
 
      e[v] = mp(1e9, 1e9);
    }
 
    set<pair<pair<int, int>, int> > se;
    for (int i = 0; i < t.size(); ++i) {
      se.insert(mp(mp(0, i), t[i].x));
      e[t[i].x] = mp(0, i);
      di[t[i].x] = 0;
      speed[i] = t[i].y;
    }
 
    // pper(p);
 
    while (se.size()) {
      auto [val, v] = *se.begin(); se.erase(se.begin());
 
      // per(val, v);
 
      for (auto [to, w] : r[v]) {
        pair<int, int> nxt = mp((di[v] + w + speed[val.y] - 1) / speed[val.y], val.y);
        if (nxt < e[to]) {
          se.erase(mp(e[to], to));
          e[to] = nxt;
          di[to] = di[v] + w;
          se.insert(mp(nxt, to));
        }
      }
    }
 
    // for (int v : p) per(v, e[v]);
 
    for (int v : d) cout << e[v].y + 1 << ' '; cout << "\n";
    for (int v : p) r[v].clear();
  
  }
 
}