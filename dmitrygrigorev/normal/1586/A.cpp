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

const int N = 100007;
bool bad[N];

vector<int> cand;

bool check(vector<int> &v, vector<bool> &take) {
  cand.clear();
  int num = 0;
  for (int i = 0; i < v.size(); ++i) {
    if (take[i]) {
      num += v[i];
      cand.pb(i);
    }
  }

  return bad[num];

}

void solve() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (auto &x : v) cin >> x;

  vector<bool> take(n, true);
  vector<int> ans;

  if (check(v, take)) {
    if (cand.size() > ans.size()) ans = cand;
  }

  for (int i = 0; i < take.size(); ++i) {
    take[i]= false;
    if (check(v, take)) {
      if (cand.size() > ans.size()) ans = cand;
    }
    take[i] = true;
  }

  for (int i = 0; i < take.size(); ++i) {
    for (int j = i + 1; j < take.size(); ++j) {
      take[i] = false, take[j] = false;
      if (check(v, take)) {
        if (cand.size() > ans.size()) ans = cand;
      }
      take[i] = true, take[j] = true;
    }
  }

  cout << ans.size() << '\n';
  for (auto x : ans) cout << x+1 << " ";
  cout << '\n';

}

int main(){
#ifdef LOCAL
  freopen("A_input.txt", "r", stdin);
  //freopen("A_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 2; i < N; ++i) {
    if (!bad[i]) {
      for (int j = i + i; j < N; j += i) bad[j] = true;
    }
  }

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}