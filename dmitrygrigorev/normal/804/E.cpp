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

vector<int> v;
vector<pair<int, int> > ans;

void apply(int x, int y) {
  swap(v[x], v[y]);
  ans.pb(mp(x, y));
}

void finish() {
  cout << "YES\n";
  for (auto x : ans) cout << x.x+1 << " " << x.y+1 << '\n';
  exit(0);
}

int main(){
#ifdef LOCAL
  freopen("A_input.txt", "r", stdin);
  //freopen("A_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  if (n%4 == 2 || n % 4 == 3) {
    cout << "NO";
    exit(0);
  }

  for (int i = 0; i < n; ++i) v.pb(i);

  while (n > 5) {
    for (int i = n - 2; i > 0; --i) apply(i, n - 1);
    apply(0, n - 2);
    apply(0, n - 1);
    for (int i = 1; i < n - 2; ++i) apply(i, n - 2);
    n -= 2;
  //per(v);
  }

  vector<pair<int, int> > vp;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) vp.pb(mp(i, j));
  }

  vector<int> perm;
  for (int i = 0; i < vp.size(); ++i) perm.pb(i);

  do {
    vector<int> v;
    for (int i = 0; i < n; ++i) v.pb(i);
    for (auto x : perm) swap(v[vp[x].x], v[vp[x].y]);
    vector<int> t = v;
    sort(all(t));
    if (t == v) {
      for (auto x : perm) {
        apply(vp[x].x, vp[x].y);
      }
      finish();
    }
  }
  while (next_permutation(all(perm)));

}