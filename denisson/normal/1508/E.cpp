#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n;
vector<int> g[300007];
int p[300007];
int step[300007];
vector<int> a;
int to_v[300007];

void dfs(int v, int pp = -1) {
  p[v] = pp;
  for (int to : g[v]) if (to != pp) dfs(to, v), step[v]++;
  to_v[a[v]] = v;
}

vector<int> ord, ord2;
int ans[300007];
int tt = 0;
int mi[300007];
int bad[300007];
int le[300007];

void gom(int v, int lel = 0) {
  le[v] = lel;
  mi[v] = a[v];
  for (int to : g[v]) {
    gom(to, lel + 1);
    mi[v] = min(mi[v], mi[to]);
  }
}

void go(int v) {
  ord2.pb(v);
  sort(all(g[v]), [](int a, int b) {
    return mi[a] < mi[b];
  });
  ans[v] = tt++;
  for (int to : g[v]) {
    go(to);
  }
  ord.pb(v);
}


int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) cin >> a[i], a[i]--;
  for (int i = 0; i + 1 < n; ++i) {
    int w1, w2;
    cin >> w1 >> w2;
    --w1; --w2;
    g[w1].pb(w2);
  }
  dfs(0);

  vector<int> path;

  ll res = 0;

  for (int i = 0; i < n; ++i) {
 //   cout << i + 1 << ' ' << to_v[i] + 1 << endl;


    if (step[to_v[i]] == 0) {
      step[p[to_v[i]]]--;
      path.pb(to_v[i]);
      bad[to_v[i]] = 1;
    } else {
      int v = to_v[i];
      vector<int> vals;
      vals.pb(a[v]);

      while (v != -1) {
        if (p[v] == -1) break;
        vals.pb(a[p[v]]);
        swap(a[v], a[p[v]]);
        ++res;
        v = p[v];
      }

      sort(all(vals));

      if (vals.size() != vals.back() - vals[0] + 1) {
        cout << "NO\n"; exit(0);
      }
      if (a[0] != vals[0]) {
        cout << "NO\n"; exit(0);
      }
      break;
    }
  }

  gom(0);
  go(0);

  for (int i = 0; i < path.size(); ++i) {
//    cout << "====" << path[i] << ' ' << ord[i] << endl;

    if (path[i] != ord[i]) {
        cout << "NO\n"; exit(0);
    }
    res += le[path[i]];
  }
  

/*
  cout << "ADSASDASDSAD"<< endl;

  for (int v : ord2) cout << v + 1 << ' ' << ans[v] << ' ' << a[v] << endl;
  exit(0); */

/*
  for (int i = 0; i < n; ++i) if (!bad[i] && a[i] != ans[i] + path.size()) {
    cout << "NO\n"; exit(0);
  }
*/
  vector<pair<int, int>> q1, q2;
  for (int i = 0; i < n; ++i) if (!bad[i]) {
    q1.pb(mp(ans[i], i));
    q2.pb(mp(a[i], i));
  }
  sort(all(q1));
  sort(all(q2));
  for (int i = 0; i < q1.size(); ++i) if (q1[i].y != q2[i].y) {
    cout << "NO\n"; exit(0);
  }

  cout << "YES\n";
  cout << res << endl;
  for (int i = 0; i < n; ++i) cout << ans[i] + 1 << ' ';
}