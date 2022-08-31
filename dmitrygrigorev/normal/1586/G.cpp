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

struct Seg {
  pair<int, int> p;
  int index;
};

const int MAX_SIZE = 400007;

struct FenwickTree1 {
  int t[MAX_SIZE];

  int get(int v) {
    int res = 0;
    for (; v >= 0; v = (v & (v + 1)) - 1) {
      add(res, t[v]);
    }
    return res;
  }

  // Sum [vl..vr]
  int get(int vl, int vr) {
    if (vl > vr) return 0; 
    int res = get(vr);
    if (vl > 0) {
      dec(res, get(vl - 1));
    }
    return res;
  }

  // Update t[v] += val;
  void up(int v, int val) {
    for (; v < MAX_SIZE; v = v | (v + 1)) {
      add(t[v], val);
    }
  }
};

FenwickTree1 f;

bool cmp2(Seg &a, Seg &b) {
  return (a.p < b.p);
}

int main(){
#ifdef LOCAL
  freopen("G_input.txt", "r", stdin);
  //freopen("G_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<Seg> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].p.x >> v[i].p.y;
    v[i].index = i;
  }

  vector<bool> need(n, false);
  int k;

  cin >> k;
  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    need[x - 1] = true;
  }

  vector<int> steps(n);
  sort(all(v), cmp2);

  for (int i = n - 1; i >= 0; --i) {
    int S = f.get(v[i].p.x, v[i].p.y);
    add(S, 1);
    steps[v[i].index] = S;
    f.up(v[i].p.y, S);
  }

  set<int> have;

  for (auto x : v) {
    if (need[x.index]) {
      have.insert(x.p.y);
    }
  }

  int ans = 0;

  for (int i = 0; i < n; ++i) {

    auto it = have.end();
    it--;

    int mx = (*it);

    if (v[i].p.y <= mx) {
      add(ans, steps[v[i].index]);
      if (need[v[i].index]) {
        k--;
        have.erase(have.find(v[i].p.y));
        if (k == 0) {
          cout << ans;
          exit(0);
        }
      }
    }
  }
}