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



int main(){
#ifdef LOCAL
  freopen("B_input.txt", "r", stdin);
  //freopen("B_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> a(n);
  vector<int> b(n);

  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;

  set<int> unused;
  for (int i = 0; i < n; ++i) unused.insert(i);

  vector<int> last(n + 1, -1);
  
  queue<int> q;
  q.push(n);

  while (q.size()) {
    int W = q.front();
    q.pop();

    if (W == 0) break;

    int st = W;

    W += b[W - 1];
    while (unused.size()) {
      auto it = unused.upper_bound(W);
      if (it == unused.begin()) break;
      it--;

      int Q = (*it);
      if (W - Q > a[W - 1]) break;

      unused.erase(it);
      last[Q] = st;
      q.push(Q);
    }
  }

  if (last[0] == -1) cout << -1;
  else {
    vector<int> path;
    int cur = 0;

    while (cur != n) {
      path.pb(cur);
      cur = last[cur];
    }

    cout << path.size() << '\n';
    reverse(all(path));

    for (auto x : path) cout << x << " ";

  }

}