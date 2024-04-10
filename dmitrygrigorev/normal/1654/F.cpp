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
  freopen("F_input.txt", "r", stdin);
  //freopen("F_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string s;

  cin >> n >> s;
  n = (1<<n);
  
  vector<int> code;
  for (int i = 0; i < n; ++i) {
    code.pb(s[i] - 'a');
  }

  for (int sz = 2; sz <= n; sz *= 2) {
    vector<tuple<int, int, int> > tt;
    for (int start = 0; start < n; start += sz) {
      for (int g = 0; g < sz; ++g) {
        int small_part = g & (sz / 2 - 1);
        int a, b;
        if (g == small_part) {
          a = code[start + small_part], b = code[start + sz/2 + small_part];
        }
        else {
          b = code[start + small_part], a = code[start + sz/2 + small_part];
        }
        tt.pb(make_tuple(a, b, start + g));
      }
    }

    sort(all(tt));
    int start = 0;
    int ptr = 0;

    while (start < n) {
      int finish = start;
      auto p = mp(get<0>(tt[start]), get<1>(tt[start]));
      while (finish < n) {
        auto pp = mp(get<0>(tt[finish]), get<1>(tt[finish]));
        if (pp == p) finish++;
        else break;
      }
      for (int e = start; e < finish; ++e) {
        int gg = get<2>(tt[e]);
        code[gg] = ptr;
      }
      ptr++;
      start = finish;
    }
  }

  int Z = -1;
  for (int i = 0; i < n; ++i) if (code[i] == 0) Z = i;
  for (int i = 0; i < n; ++i) cout << s[Z^i];

}