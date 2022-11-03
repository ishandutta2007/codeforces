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

int n;
string s1, s2;

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt;
  cin >> tt;

  while (tt--) {
    cin >> n >> s1 >> s2;


    if (s1 == s2) {
      cout << "0\n";
      continue;
    }

    int a1 = 0, b1 = 0, a2 = 0 , b2 = 0;

    for (char c : s1) {
      if (c == '1') ++a1; else ++b1;
    }

    for (char c : s2) {
      if (c == '1') ++a2; else ++b2;
    }

    if (a1 == 0) {
      cout << "-1\n"; continue;
    }


    const int INF = 1e9 + 7;
    int res = INF;
    

    if (a1 == a2 && b1 == b2) {
      int cc = 0;
      for (int i = 0; i < n; ++i) {
        cc += s1[i] != s2[i];
      }
      uin(res, cc);
    }

    if (a2 == b1 + 1 && b2 == a1 - 1) {
      int cc = 0;

      for (int i = 0; i < n; ++i) {
        cc += s1[i] == s2[i];
      }

      for (int i = 0; i < n; ++i) {
        cc -= s1[i] == s2[i];

        cc += s1[i] != s2[i];

        uin(res, 1 + cc);

        cc -= s1[i] != s2[i];

        cc += s1[i] == s2[i];
      }
    }

    if (res == INF) res = -1;
  cout << res << "\n";
  }

}