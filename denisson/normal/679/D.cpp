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

mt19937 mrand(1337); 
unsigned int myRand32() {
  return mrand() & (unsigned int)(-1);
}
 
unsigned ll myRand64() {
  return ((ull)myRand32() << 32) ^ myRand32();
}

const int mod = 1000000007;

void add(int& a, int b) {
  a += b; if (a >= mod) a -= mod;
}

void dec(int &a, int b) {
  a -= b; if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

int n, m;
vector<int> g[444];

int dist[444][444];

void prec() {
  for (int v = 0; v < n; ++v) {

    fill(dist[v], dist[v] + n, -1);
    dist[v][v] = 0;

    vector<int> st;
    st.pb(v);
    int uk = 0;
    while (uk < st.size()) {
      int now = st[uk++];
      for (int to : g[now]) if (dist[v][to] == -1) {
        dist[v][to] = dist[v][now] + 1;
        st.pb(to);
      }
    }

  }
}

vector<int> t[404];

db f[404];

db ma[444];
db sum[444];

int used[444];
int TT = 1;

db solve(int v, int d) {
  fill(f, f + n, 0);
  for (int p : t[d]) {
    for (int to : g[p]) f[to] += 1. / g[p].size() / t[d].size();
  }
  
//  per(v, d);
//  cout << "F: ";
 // for (int i = 0; i < n; ++i) cout << f[i] << ' '; cout << endl;

  vector<int> u;
  for (int i = 0; i < n; ++i) if (f[i] > 1e-6) u.pb(i);


  db best = 0;

  for (int nxt = 0; nxt < n; ++nxt) {

    ++TT;
    db now = 0;

    for (int r : u) uax(ma[dist[nxt][r]], f[r]), sum[dist[nxt][r]] += f[r];
    for (int r : u) if (used[dist[nxt][r]] != TT) {
      used[dist[nxt][r]] = TT;

     // per("====    ", sum[dist[nxt][r]], ma[dist[nxt][r]], dist[nxt][r], nxt);

      now += ma[dist[nxt][r]]; // sum[dist[nxt][r]] * ma[dist[nxt][r]];

      sum[dist[nxt][r]] = ma[dist[nxt][r]] = 0;
    }

    uax(best, now);

  }

 //  pper(best);

  return best;

}



db check(int v) {

  for (int i = 0; i <= n; ++i) t[i].clear();
  for (int i = 0; i < n; ++i) t[dist[v][i]].pb(i);

  db res = 0;

  for (int d = 0; d <= n; ++d) {

    
    if (t[d].size() == 0) break;
    

    res += max(solve(v, d), (db)1. / t[d].size()) * t[d].size() / (db)n;

 //   per("RESULT   ", d, solve(v, d), (db)1. / t[d].size());

  }

  return res;

}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int w1, w2;
    cin >> w1 >> w2;
    --w1; --w2;
    g[w1].pb(w2);
    g[w2].pb(w1);
  }

  prec();

  db res = 0;

//  pper(check(0)); exit(0);

  for (int v = 0; v < n; ++v) {
    uax(res, check(v));
  }

  cout.precision(10);
  cout << fixed << res;

}