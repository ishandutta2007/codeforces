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

vector<int> a;
vector<int> b;

const int N = 1000000 * 16;
int possible_sum[N];

int x, y;

void recursion(int t, int mask, vector<int> &v, int sum) {
  if (t == v.size()) {
    if (possible_sum[sum] != -1 && __builtin_popcount(mask) == v.size() / 2) {
      x = possible_sum[sum];
      y = mask;
      return;
    }
    if (__builtin_popcount(mask) == v.size() / 2) {
      possible_sum[sum] = mask;
    }
    return;
  }

  recursion(t + 1, mask, v, sum);
  recursion(t + 1, mask + (1<<t), v, sum + v[t]);

}


void derecursion(int t, int mask, vector<int> &v, int sum) {
  if (t == v.size()) {
    possible_sum[sum] = -1;
    return;
  }

  derecursion(t + 1, mask, v, sum);
  derecursion(t + 1, mask + (1<<t), v, sum + v[t]);

}

bool bad = false;
int n, k;

void stupid(vector<int> v) {

  bad = false;
  x = -1, y = -1;
  recursion(0, 0, v, 0);
  derecursion(0, 0, v, 0);

  if (x == -1) {
    bad = true;
    return;
  }

  int A = x ^ (x & y);
  int B = y ^ (x & y);

  vector<bool> used(v.size());
  for (int i = 0; i < v.size(); ++i) {
    if (A&(1<<i)) {
      used[i] = true;
      a.pb(v[i]);
    }
    if (B&(1<<i)) {
      used[i] = true;
      b.pb(v[i]);
    }
  }
}

const int M = 20000007;
bitset<28> wh[M];

void naive(vector<int> v) {

  vector<ll> used_sums;
  bitset<28> x, y;

  while (true) {
    bitset<28> cur;
    ll sum = 0;

    vector<int> current_check;
    for (int i = 0; i < v.size(); ++i) current_check.pb(i);
    random_shuffle(all(current_check));

    for (int i = 0; i < v.size() / 2; ++i) {
      int t = current_check[i];
      sum += v[t];
      cur[t] = 1;
    }

    used_sums.pb(sum);
    if (cur.count() == 0) continue;

    if (wh[sum].count() != 0) {
      x = wh[sum];
      y = cur;
      if (x!=y) break;
    }

    wh[sum] = cur;
  }

  auto A = x ^ (x & y);
  auto B = y ^ (x & y);

  for (auto x : used_sums) wh[x].reset();
  vector<bool> used(v.size());
  for (int i = 0; i < v.size(); ++i) {
    if (A[i]) {
      used[i] = true;
      a.pb(v[i]);
    }
    if (B[i]) {
      used[i] = true;
      b.pb(v[i]);
    }
  }
}

pair<vector<int>, vector<int>> find(vector<int>& v) {
  for (int i = 0; i < N; ++i) possible_sum[i] = -1;
  if (v.size() >= 28) {
    vector<int> t;
    for (int i = 0; i < 28; ++i) t.pb(v[i]);
    naive(t);
    return mp(a, b);
  }
  else {
    stupid(v);
    return mp(a, b);
  }
}

int main(){
#ifdef LOCAL
  freopen("J_input.txt", "r", stdin);
  //freopen("J_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector <int> b(n);
  set <int> sb;

  vector<int> even, odd;
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    sb.insert(b[i]);
    if (b[i] % 2 == 0) {
      even.pb(b[i]);
    } else {
      odd.pb(b[i]);
    }
  }

  vector <int> a(n, 0);
  if (sb.size() < n) {
    int now = 0;
    for (int x : sb) {
      a[now++] = x;
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
      cout << a[i] << " ";
    }
    cout << "\n";
    exit(0);
  }

  if (n == 2) {
    cout << "NO\n";
    return 0;
  }


  if (even.size() >= 3 || (odd.size() >= 2 && even.size())) {
    int x, y, z;
    if (even.size() >= 3) {
      x = even[0], y = even[1], z = even[2];
    } else {
      x = odd[0], y = odd[1], z = even[0]; 
    }
    int T = (x + y - z) / 2;
    a[0] = T;
    int now = 1;
    for (int x : sb) {
      if (x == z) {
        continue;
      }
      a[now++] = x - T;
    }
    cout << "YES\n";
    for (int x : a) {
      cout << x << " ";
    }
    cout << "\n";
    return 0;
  }

  if (n == 3) {
    cout << "NO\n";
    return 0;
  }
  assert(!even.size());

  set<int> bad;

  auto t = find(b);
  //per(t.x.size(), t.y.size());

  int sum1 = 0, sum2 = 0;
  for (int x : t.x) {
    sum1 += x;
    assert(bad.find(x) == bad.end());
    bad.insert(x);
  }
  for (int y : t.y) {
    sum2 += y;
    assert(bad.find(y) == bad.end());
    bad.insert(y);
  }
  assert(sum1 == sum2);
  assert(t.x.size() == t.y.size());
  if (!t.x.size()) {
    cout << "NO\n";
    return 0;
  }

  int now = 0;
  int sz = bad.size() / 2;

  a[now++] = 0;
  for (int i = 0; i < sz; ++i) {
    a[now++] = t.x[i] - a[now - 1];
    if (i != sz - 1) a[now++] = t.y[i] - a[now - 1];
  }

  for (int i = 0; i < n; ++i) {
    if (bad.find(b[i]) != bad.end()) continue;
    a[now++] = b[i];
  }
  cout << "YES\n";
  for (int x : a) {
    cout << x << " ";
  }
  cout << "\n";
}