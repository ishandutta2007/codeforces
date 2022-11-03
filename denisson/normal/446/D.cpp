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

int n, m, k;
int a[555];
vector<int> g[555];

db p[505][505];

struct Matr {
  db a[102][102];
  Matr() { fill((db*)a, (db*)a + 102 * 102, 0); }
};

Matr mult_matr(const Matr& a, const Matr& b) {
  Matr c;
  for (int i = 0; i < 102; ++i) {
    for (int j = 0; j < 102; ++j) {
      c.a[i][j] = 0;
      for (int s = 0; s < 102; ++s) {
        c.a[i][j] += a.a[i][s] * b.a[s][j];
      }
    }
  }
  return c;
}

Matr bp_matr(Matr a, int b) {
  Matr res;
  for (int i = 0; i < 102; ++i) for (int j = 0; j < 102; ++j) res.a[i][j] = i == j;
  while (b > 0) {
    if (b & 1) res = mult_matr(res, a);
    a = mult_matr(a, a);
    b >>= 1;
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

  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) cin >> a[i];

  map<int, int> con; int sz = 0;
  int cnt = 0;
  for (int i = 0; i < n; ++i) if (a[i] == 0) con[i] = sz++;
  for (int i = 0; i < n; ++i) if (a[i] == 1) con[i] = sz++, ++cnt;

  for (int i = 0; i < m; ++i) {
    int w1, w2;
    cin >> w1 >> w2;
    --w1; --w2;
    w1 = con[w1];
    w2 = con[w2];
    g[w1].pb(w2);
    g[w2].pb(w1);
   // per(w1, w2);
  }

  vector<vector<db>> e;

  for (int i = 0; i < n - cnt; ++i) {
    vector<db> eq(n, 0);
    eq[i] = 1;
    for (int to : g[i]) eq[to] += -1. / g[i].size();
    e.pb(eq);
  }

 // pper(e);

  for (int i = 0; i < n - cnt; ++i) {
    int v = i;
    for (int j = i; j < e.size(); ++j) if (fabsl(e[v][i]) < fabsl(e[j][i])) v = j;
    for (int j = 0; j < e[0].size(); ++j) swap(e[i][j], e[v][j]);

    for (int j = i + 1; j < e.size(); ++j) {
      db coef = e[j][i] / e[i][i];
      for (int s = i; s < e[0].size(); ++s) {
        e[j][s] -= coef * e[i][s];
      }
    }
  }


  for (int i = (int)e.size() - 1; i >= 0; --i) {

    for (int j = 0; j < i; ++j) {
      db coef = e[j][i] / e[i][i];
      for (int d = i; d < e[0].size(); ++d) {
        e[j][d] -= coef * e[i][d];
      }

    }

  }

 // pper(e);

  for (int i = n - cnt; i < n; ++i) {
    for (int j = 0; j < e.size(); ++j) {
      p[i][j] = -e[j][i] / e[j][j];
    }
  }

  for (int i = n - cnt; i < n; ++i) {
    for (int j = n - cnt; j < n; ++j) {
      p[i][j] = 0;
      for (int to : g[j]) {
        if (to >= n - cnt) {
          if (to == i) p[i][j] += 1.0 / g[i].size(); 
        } else {
          p[i][j] += p[i][to] / g[i].size();
        }
      } 
    }
  }

  vector<db> t;
  for (int i = n - cnt; i < n; ++i) t.pb(p[i][con[0]]);

  Matr m;


  for (int i = n - cnt; i < n; ++i)
  for (int j = n - cnt; j < n; ++j)
    m.a[i - (n - cnt)][j - (n - cnt)] = p[i][j];

/*
  pper(t);
  for (int i = 0; i < cnt; ++i) {
    for (int j = 0; j < cnt; ++j) {
      cout << m.a[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl; */

  m = bp_matr(m, k - 2);

  db res = 0;
  for (int i = 0; i < cnt; ++i) res += t[i] * m.a[i][cnt - 1];

  cout.precision(10);
  cout << fixed << res;

}