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

struct Vertex {
  int l;
  int r;
  int father;
  int cnt;
};


Vertex rmq[4000007];
int ptr = 0;

vector<int> want[4000007];

int create(int vertex) {
  rmq[ptr++] = {-1, -1, vertex, 0};
  want[ptr-1] = {};
  return ptr - 1;
}

void go(int vertex, ll l, ll r, ll l1, ll r1) {
  if (l1 >= r1) return;
  if (l == l1 && r == r1) {
    rmq[vertex].cnt = 1;
    return;
  }

  if (rmq[vertex].l == -1) {
    rmq[vertex].l = create(vertex);
  }
  if (rmq[vertex].r == -1) {
    rmq[vertex].r = create(vertex);
  }

  ll mid = (l+r)/2;
  go(rmq[vertex].l, l, mid, l1, min(r1, mid));
  go(rmq[vertex].r, mid, r, max(l1, mid), r1);
  rmq[vertex].cnt = rmq[rmq[vertex].l].cnt + rmq[rmq[vertex].r].cnt;

}

struct Node {
  int p, r, f;
};

struct DSU {
  static const int SZ = 10000007;
  Node t[SZ];

  DSU() { reset(SZ); }

  void reset(int n) {
    for (int i = 0; i < n; ++i) {
      t[i].p = i;
      t[i].r = 0;
      t[i].f = 1;
    }
  }

  int get(int v) {
    if (t[v].p == v) return v;
    return t[v].p = get(t[v].p);
  }

  int get_func(int v) {
    return t[get(v)].f;
  }

  void merge(int a, int b) {
    a = get(a), b = get(b);
    if (a != b) {
      if (t[a].r < t[b].r) swap(a, b);
      t[b].p = a;
      t[a].f += t[b].f;
      if (t[a].r == t[b].r) ++t[a].r;
    }
  }
};

DSU dsu;

bool good(int vertex) {
  if (vertex == -1) return false;
  if (rmq[vertex].cnt) return false;
  return true;
}

void restore(int vertex) {
  if (good(rmq[vertex].father)) dsu.merge(vertex, rmq[vertex].father);
  if (good(rmq[vertex].l)) dsu.merge(vertex, rmq[vertex].l);
  if (good(rmq[vertex].r)) dsu.merge(vertex, rmq[vertex].r);

  for (auto to : want[vertex]) dsu.merge(vertex, to);

  int W = vertex;

  vector<int> bits;
  while (true) {
    int t = rmq[vertex].father;
    if (t == -1) break;
    if (rmq[t].l == vertex) bits.pb(0);
    else bits.pb(1);
    vertex = t;
  }

  reverse(all(bits));
  //per(W, bits);
  int start = 0;
  for (int i = 0; i < bits.size() && start != -1; ++i) {
    bits[i] ^= 1;

    int now = start;
    for (int j = i; j < bits.size(); ++j) {
      int x = bits[j];
      if (x == 0) {
        if (rmq[now].l == -1) {
          break;
        }
        now = rmq[now].l;
      }
      else {
        if (rmq[now].r == -1) {
          break;
        }
        now = rmq[now].r;
      }
    }

    if (good(now)) {
      dsu.merge(W, now);
     // per(W, now);
    }
    else want[now].pb(W);

    bits[i] ^= 1;
    if (bits[i] == 0) start = rmq[start].l;
    if (bits[i] == 1) start = rmq[start].r;
  }

}

void go_back(int vertex, ll l, ll r, ll l1, ll r1) {
  if (l1 >= r1) return;
  if (l == l1 && r == r1) {
    rmq[vertex].cnt = 0;
    restore(vertex);
    return;
  }

  ll mid = (l+r)/2;
  go_back(rmq[vertex].l, l, mid, l1, min(r1, mid));
  go_back(rmq[vertex].r, mid, r, max(l1, mid), r1);

  int W = rmq[vertex].cnt;
  rmq[vertex].cnt = rmq[rmq[vertex].l].cnt + rmq[rmq[vertex].r].cnt;
 // per(vertex, l, r);
  if (rmq[vertex].cnt == 0 && W != 0) restore(vertex);

}

int n, m;

int gg(ll x) {

  int now = 0;

  for (int i = n - 1; i >= 0; --i) {
    int t = (((1LL<<i)&x) > 0);
    if (t == 0) {
      if (rmq[now].l == -1) return now;
      now = rmq[now].l;
    }
    else {
      if (rmq[now].r == -1) return now;
      now = rmq[now].r;
    }
  }

  return now;

}

main(){
#ifdef LOCAL
  freopen("G_input.txt", "r", stdin);
  //freopen("G_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  create(-1);
  rmq[0].l = create(0);
  rmq[0].r = create(0);

  vector<tuple<int, ll, ll> > queries;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;

    if (s == "ask") {
      ll l, r;
      cin >> l >> r;
      queries.pb(make_tuple(0, l, r));
    }
    else {
      ll l, r;
      cin >> l >> r;

      queries.pb(make_tuple(1, l, r));

      go(0, 0, (1ll<<n), l, r + 1);

    }
  }

  vector<int> ans;
  dsu.reset(ptr);

  for (int i = 0; i < ptr; ++i) {
    if (!rmq[i].cnt) {
      restore(i);
    }
  }

  reverse(all(queries));

  for (auto x : queries) {

    int tp = get<0>(x);
    ll l = get<1>(x);
    ll r = get<2>(x);

    if (tp == 1) {
      go_back(0, 0, (1ll<<n), l, r + 1);
    }

    else {
      //exit(0);
      int A = gg(l), B = gg(r);
      //per(A, B);
      //exit(0);
      if (dsu.get(A) == dsu.get(B) && !rmq[A].cnt && !rmq[B].cnt) ans.pb(1);
      else ans.pb(0);
    }

  }

  reverse(all(ans));

  for (auto x : ans) cout << x << '\n';

}