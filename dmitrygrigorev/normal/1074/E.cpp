#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
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
const int N = 21;
int matrix[N][N];
bool used[N][N];

int get(int i, int j) {
  return m * i + j;
}

vector<vector<int> > ans;
void print() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cout << matrix[i][j] << " ";
    per();
  }
  per();
}

pair<int, int> find(int x) {
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (matrix[i][j] == x) return mp(i, j);
} 

void rotate(vector<int> v) {

  vector<pair<int, int> > cur;
  for (auto x : v) cur.pb(find(x));

  for (int i = 0; i < v.size(); ++i) {
    int T = (i+1)%v.size();
    matrix[cur[T].x][cur[T].y] = v[i];
  }

  ans.pb(v);


}

bool vis[N][N];
pair<int, int> last[N][N];

vector<pair<int, int> > find_shortest_path(pair<int, int> a, pair<int, int> b, bool tt) {

  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) vis[i][j] = false;

  vis[a.x][a.y] = true;
  queue<pair<int, int> > q;
  q.push(mp(a.x, a.y));

  auto A = a;

  while (q.size()) {
    auto W = q.front();
    q.pop();
    for (int dx = -1; dx <= 1; ++dx) {
      for (int dy = -1; dy <= 1; ++dy) {

        if (abs(dx) + abs(dy) != 1) continue;
        int a = W.x + dx, bb = W.y + dy;
        if (!tt) {
          if (W == A && mp(a, bb) == b) continue;
        }
        if (a < 0 || a >= n || bb < 0 || bb >= m || vis[a][bb] || (used[a][bb] && mp(a, bb) != b)) {
          continue;
        }

      //  per(a, bb);

        vis[a][bb] = true;
        last[a][bb] = W;

        q.push(mp(a, bb));

      }
    }
  }

  if (!vis[b.x][b.y]) return {};

  vector<pair<int, int> > path;
  int nowx = b.x, nowy = b.y;

  while (mp(nowx, nowy) != a) {
    path.pb(last[nowx][nowy]);
    nowx = path.back().x;
    nowy = path.back().y;
  }

  reverse(all(path));
  return path;



}

vector<int> find_path(pair<int, int> a, pair<int, int> b) {

  //per(a, b);

  auto p1 = find_shortest_path(a, b, true);
  //per(p1);
  for (auto x : p1) used[x.x][x.y] = true;
  auto p2 = find_shortest_path(b, a, false);
//per(p2);
  for (auto x : p1) used[x.x][x.y] = false;

  if (!p1.size() || !p2.size()) return {};

  vector<int> res;
  for (auto x : p1) res.pb(matrix[x.x][x.y]);
  for (auto x : p2) res.pb(matrix[x.x][x.y]);
  return res;

}

int encode(vector<int> v) {

  vector<bool> used(9, false);
  int res = 0;

  int t = 1;
  for (int i = 0; i < 8; ++i) t *= (i + 1);

  int now = 8;

  for (int i = 0; i < v.size(); ++i) {
    int num = 3 * (v[i] / m) + (v[i] % m);
    int cur = 0;
    for (int j = 0; j < num; ++j) if (!used[j]) cur++;

    res += cur * t;

    if (now == 0) break;
    t /= (now--);

    used[num] = true;
  }

  return res;

}

void solve(int n, int m) {

  if (m > 3 && m >= n) {

    for (int i = n-1; i >= 0; --i) {

      //print();
      //per(n, m, i);

      int x = i, y = m-1;
      if (i <= 1) {
        y = 0;
        x ^= 1;
      }

      int want = get(i, m - 1);

      while (true) {

        //per(1488, clock(), want);

        auto pos = find(want);
        if (pos == mp(x, y)) break;

        auto p = find_path(pos, mp(x, y));
       // per(pos, mp(x, y), p, matrix[19][19]);
        if (p.size()) {
          int iter = 0;
          while (matrix[x][y] != want && (iter++) < 1) {
            rotate(p);
          }
          //used[x][y] = true;
        }
        else {

          if (pos != mp(1, 1)) {
            vector<int> p = find_path(pos, mp(1, 1));
            while (matrix[1][1] != want) {
              rotate(p);
            }
          }

          vector<int> p = find_path(mp(1, 1), mp(x, y));
          while (matrix[x][y] != want) {
            rotate(p);
          }
         // used[x][y] = true;

        }

      }

      used[x][y] = true;
    }

    used[0][0] = false, used[1][0] = false;
    vector<int> p;
    for (int i = 0; i < m; ++i) p.pb(matrix[0][i]);
    for (int i = m-1; i >= 0; --i) p.pb(matrix[1][i]);

    for (int i = 0; i < m; ++i) rotate(p);

    solve(n, m - 1);
    return;

  }

  else if (n > 3) {
   // print();
    for (int i = m-1; i >= 0; --i) {

      int x = n - 1, y = i;
      if (i <= 1) {
        x = 0;
        y ^= 1;
      }

      int want = get(n - 1, i);
      while (true) {

        auto pos = find(want);
        if (pos == mp(x, y)) break;

        auto p = find_path(pos, mp(x, y));
        if (p.size()) {
          for (int dx = -1; dx <= 1; ++dx) for (int dy = -1; dy <= 1; ++dy) {
            int a = pos.x+dx, b = pos.y+dy;
            if (a < 0 || a >= n || b < 0 || b >= m) continue;
            if (matrix[a][b] == p[1]) {
              //per(1588);
              p = find_path(pos, mp(a, b));
              //cout << p.size() << endl;
            }
          }

          int iter = 0;
          while (matrix[x][y] != want && (iter++) < 1) {
            rotate(p);
          }
          //used[x][y] = true;
        }
        else {

          if (pos != mp(1, 1)) {
            vector<int> p = find_path(pos, mp(1, 1));
            while (matrix[1][1] != want) {
              rotate(p);
            }
          }

          vector<int> p = find_path(mp(1, 1), mp(x, y));
          while (matrix[x][y] != want) {
            rotate(p);
          }
         // used[x][y] = true;

        }

      }

      used[x][y] = true;
     // print();
    }

    used[0][0] = false, used[0][1] = false;
    vector<int> p;
    for (int i = 0; i < n; ++i) p.pb(matrix[i][0]);
    for (int i = n-1; i >= 0; --i) p.pb(matrix[i][1]);

    for (int i = 0; i < n; ++i) rotate(p);

   // print();
   // exit(0);

    solve(n - 1, m);
    return;
  }

  vector<vector<int> > last(362880);
  vector<vector<int> > state(362880);

  vector<int> arr;

  for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) arr.pb(matrix[i][j]);

  queue<vector<int> > tt;
  tt.push(arr);

  state[encode(arr)].pb(1488);

  while (tt.size()) {
    auto W = tt.front();
    tt.pop();
    
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {

        for (int k = 0; k < 3; ++k) for (int e = 0; e < 3; ++e) matrix[k][e] = W[3 * k + e];

        vector<int> p;
        p.pb(matrix[i][j]);
        p.pb(matrix[i][j+1]);
        p.pb(matrix[i+1][j+1]);
        p.pb(matrix[i+1][j]);

        rotate(p);
        ans.pop_back();

        vector<int> g;
        for (int k = 0; k < 3; ++k) for (int e = 0; e < 3; ++e) g.pb(matrix[k][e]);

       // per(W, g);
        int T = encode(g);

        if (!state[T].size()) {
          last[T] = p;
          state[T] = W;
          tt.push(g);
        }

      }
    }
  }


  vector<int> Z = arr;
  for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) matrix[i][j] = arr[3 * i + j];
  sort(all(Z));


  vector<vector<int> > add;

  while (true) {

    if (arr==Z) break;
    //per(encode(Z), Z);
    add.pb(last[encode(Z)]);
    Z = state[encode(Z)];
  }

  //exit(0);

  reverse(all(add));
  for (auto x : add) {
    rotate(x);
  }

  //print();

  int tot = 0;
  for (auto x : ans) tot += x.size();
  //per(tot);

  //print();

  //exit(0);


  cout << ans.size() << '\n';
  for (auto x : ans) {
    cout << x.size() << " ";
    assert(x.size() >= 4);
    for (auto y : x) cout << y + 1 << " ";
    cout << '\n';
  }

}

int main(){
#ifdef LOCAL
  freopen("E_input.txt", "r", stdin);
  freopen("E_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> matrix[i][j];
      --matrix[i][j];
    }
  }

  solve(n, m);


}