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

const int mod = 998244353;

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

int n;
int a[1505][1505];

int dp[3003][1505];
int last_color[1505];

int color[1505];
int edge[3003];
int saved_sz[3003];

vector<int> g[3003];

int heh[3003];

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  vector<pair<int, pair<int, int>>> t;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
      if (i < j)
      t.pb(mp(a[i][j], mp(i, j)));
    }
  }

  sort(all(t));

  for (int i = 0; i < n; ++i) {
    dp[i][1] = 1;
    edge[i] = 0;
    last_color[i] = color[i] = i;
    g[i].pb(i);
    saved_sz[i] = 1;
  }

  int sz = n;

  for (auto c : t) {
    auto [w1, w2] = c.y;
    int col = color[w1];
    
  //  per(w1, w2);

    edge[col]++;
    if (color[w1] == color[w2]) {
    } else {
      edge[col] += edge[color[w2]];
      for (int v : g[color[w2]]) {
        g[col].pb(v);
        color[v] = col;
      }
    }

    if (edge[col] == (g[col].size() * ((int)g[col].size() - 1)) / 2) {

      int node = sz++;
      dp[node][0] = 1;

      set<int> se;
      for (int v : g[col]) se.insert(last_color[v]);

    //  for (int i = 0; i < n; ++i) cout << last_color[i] << ' '; cout << endl;
    //  pper(g[col]);
    //  pper(se);

      int tot_sz = 0;
      for (int v : se) {
        
        fill(heh, heh + saved_sz[v] + tot_sz + 1, 0);

        for (int w = 1; w <= saved_sz[v]; ++w) if (dp[v][w] > 0) {
          for (int ww = tot_sz; ww >= 0; --ww) {
            add(heh[w + ww], mult(dp[v][w], dp[node][ww]));
          }
        }
        
        tot_sz += saved_sz[v];
        
        copy(heh, heh + saved_sz[v] + tot_sz + 1, dp[node]);

      }

      dp[node][1] = 1;

      for (int v : g[col]) {
        color[v] = node;
        last_color[v] = node;
      }
      edge[node] = edge[col];
      swap(g[node], g[col]);
      saved_sz[node] = g[node].size();

   //   for (int i = 0; i <= 10; ++i) {
   //     cout << dp[node][i] << ' ';
   //   }
   //   cout << endl;

    }

  }

  for (int w = 1; w <= n; ++w) cout << dp[last_color[0]][w] << ' ';

}