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

struct Query {
  int l;
  int r;
  int index;
};

vector<Query> queries;

bool cmp(Query &a, Query &b) {
  return (a.l < b.l);
}

struct Rmq {

  vector<ll> rmq;
  vector<int> p;
  vector<ll> last;

  int n;
  int index;

  void build(int i, int l, int r) {
    if (r - l == 0) return;
    if (r - l == 1) {
      rmq[i] = 2e9;
      p[i] = -1;
      last[i] = 2e9;
      return;
    }

    int mid = (l+r)/2;
    build(2 * i + 1, l, mid);
    build(2 * i + 2, mid, r);

    rmq[i] = rmq[2*i+1] + rmq[2*i+2];
    last[i] = last[2 * i + 2];
  }

  Rmq(int n_) {
    rmq.assign(4 * n_, 2e9);
    p.assign(4 * n_, -1);
    last.assign(4 * n_, -1);

    index = n_;
    n = n_;
    build(0, 0, n);
  }

  void push(int i, int l, int r) {

    if (r - l <= 1) return;
    int mid = (l + r) / 2;

    if (p[i] != -1) {
      int P = p[i];
      p[i] = -1;

      rmq[2 * i + 1] = (ll) (mid - l) * P;
      p[2 * i + 1] = P;
      last[2 * i + 1] = P;

      rmq[2 * i + 2] = (ll) (r - mid) * P;
      p[2 * i + 2] = P;
      last[2 * i + 2] = P;
    }
  }

  int get_bigger(int i, int l, int r, int x) {

    push(i, l, r);

    if (r - l == 0) return 0;

    if (r - l == 1) {
      if (last[i] >= x) return 1;
      return 0;
    }

    int mid = (l+r)/2;
    if (last[2 * i + 1] >= x) {
      return (mid - l) + get_bigger(2*i+2, mid, r, x);
    }
    return get_bigger(2*i+1, l, mid, x);
  }

  void upd(int i, int l, int r, int l1, int r1, int x) {

    push(i, l, r);

    if (l1 >= r1) return;
    if (l == l1 && r == r1) {
      rmq[i] = (ll) (r - l) * x;
      p[i] = x;
      last[i] = x;
      return;
    }

    int mid = (l+r)/2;
    upd(2*i+1, l, mid, l1, min(r1, mid), x);
    upd(2*i+2, mid, r, max(l1, mid), r1, x);

    rmq[i] = rmq[2*i+1] + rmq[2*i+2];
    last[i] = last[2 * i + 2];

  }

  void move_index(int x) {
    int G = get_bigger(0, 0, n, x);
    upd(0, 0, n, index - 1, G, x);
    index--;
  }

  ll get(int i, int l, int r, int l1, int r1) {

    push(i, l, r);
    if (l1 >= r1) return 0;
    if (l == l1 && r == r1) return rmq[i];

    int mid = (l+r)/2;
    return get(2*i+1, l, mid, l1, min(r1, mid)) + get(2*i+2, mid, r, max(l1, mid), r1);

  }

  ll get(int t, int x) {
    return get(0, 0, n, index + t, index + x);
  }

};

int main(){
#ifdef LOCAL
  freopen("E_input.txt", "r", stdin);
  //freopen("E_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q, k;
  cin >> n >> q >> k;

  vector<int> v(n);
  for (auto &x : v) cin >> x;

  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    queries.pb({l - 1, r - 1, i});
  }

  sort(all(queries), cmp);

  Rmq global(n);

  vector<Rmq> partial;

  for (int i = 0; i < k; ++i) {
    partial.pb(Rmq((n - i) / k));
  }

  vector<ll> res(q);
  int u = q - 1;

  for (int i = n - 1; i >= 0; --i) {

    global.move_index(v[i]);

    if (i + k <= n) {
      int location = i % k;
      partial[location].move_index(global.get(k - 1, k));
    }

    while (u >= 0 && queries[u].l == i) {

      if (k == 1) {
        res[queries[u].index] = global.get(0, queries[u].r - i + 1);
        u--;
        continue;
      }

      int r = queries[u].r;
      ll ans = v[i];

      int len = r - i + 1;
      int jumps = (len - 1) / k;

      if (jumps) {
        int kek = min(jumps, partial[(i + 1) % k].get_bigger(0, 0, partial[(i+1)%k].n, v[i]) - partial[(i + 1) % k].index);

        //per(i, kek);

        ans += (ll) kek * v[i];
        ans += partial[(i + 1) % k].get(kek, jumps);
      }

      res[queries[u].index] = ans;
      u--;
    }
  }

  for (auto x : res) cout << x << " ";


}