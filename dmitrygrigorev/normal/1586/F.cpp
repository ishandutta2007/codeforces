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

int n, k;
vector<vector<int> > allw;

void gen(vector<int> &a, int can) {
  if (allw.size() == n) return;
  allw.pb(a);

  for (int i = can; i < a.size(); ++i) {
    if (a[i] + 1 < k) {
      a[i]++;
      gen(a, i);
      a[i]--;
    }
  }

}

int sum(vector<int> &a) {
  int t = 0;
  for (auto x : a) t += x;
  return t;
}

bool cmp(vector<int> &a, vector<int> &b) {
  int A = sum(a), B = sum(b);
  return (A<B);
}

int main(){
#ifdef LOCAL
  freopen("F_input.txt", "r", stdin);
  //freopen("F_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;

  int tut = 1;
  int ans = 0;

  while (tut < n) {
    tut *= k;
    ans++;
  }

  cout << ans << '\n';

  vector<int> a;
  a.assign(ans, 0);

  gen(a, 0);

  sort(all(allw), cmp);

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
     // per(allw[i], allw[j]);
      for (int e = 0; e < ans; ++e) {
        if (allw[i][e] < allw[j][e]) {
          cout << e+1 << " ";
          break;
        }
      }
    }
  }


}