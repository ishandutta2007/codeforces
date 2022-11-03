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

int n;
vector<int> g[100007];
pair<int, int> dp[100007];
int res[111111];

vector<int> ord;

void go(int v = 0, int p = -1) {
  // per(p, v);
  int pos = -1;
  for (int i = 0; i < (int)g[v].size(); ++i) {
    if (g[v][i] == p) {
      pos = i;
    } else go(g[v][i], v);
  }
  if (pos != -1) {
    swap(g[v][pos], g[v].back()); g[v].pop_back();
  }
  ord.pb(v);  
}

int f(int len) {
  if (len == 1) return n;
  if (res[len] != -1) return res[len];

  for (int v : ord) {
    dp[v] = mp(0, 1);

    pair<int, int> k = mp(0, 0);

    for (int to : g[v]) {
      // dfs(to, v);
      dp[v].x += dp[to].x;
      if (k.x < dp[to].y + 1) {
        k.y = k.x; k.x = dp[to].y + 1;
      } else uax(k.y, dp[to].y + 1);
    }
    
    if (k.x != 0) {
      if (k.x >= len) {
        dp[v] = mp(dp[v].x + 1, 0);
      } else if (k.y != 0) {
        if (k.x + k.y - 1 >= len) {
          dp[v] = mp(dp[v].x + 1, 0);
        } else dp[v].y = k.x;
      } else {
        dp[v].y = k.x;
      }
    }
  }

  return res[len] = dp[0].x;
}


int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  fill(res, res + 100007, -1);

  cin >> n;
  for (int i = 1; i < n; ++i) {
    int w1, w2;
    cin >> w1 >> w2;
    --w1; --w2;
    // w1 = i - 1, w2 = i;
    g[w1].pb(w2);
    g[w2].pb(w1);
  }

  go();
  // for (int v = 0; v < n; ++v) pper(g[v]);

  for (int i = 1; i <= min(1007, n); ++i) res[i] = f(i);
  int last = min(1007, n);

  // pper(f(n)); exit(0);

  while (last < n) {
    int vl = last, vr = n + 1;
    while (vl + 1 < vr) {
      int vm = (vl + vr) >> 1;
      if (f(vm) != res[last]) vr = vm; else vl = vm;
    }

    for (int i = last + 1; i < vr; ++i) res[i] = res[last];

    if (vr == n + 1) break;
    res[vr] = f(vr);
    last = vr;

  }

  for (int i = 1; i <= n; ++i) cout << res[i] << '\n';
}