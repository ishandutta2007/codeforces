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

const int N = 1007;

int matrix[N][N];
int tatrix[N][N];

int get_diagonal(int n) {

  int X = 0;
  for (int sum = 0; sum < n; sum += 2) {
    for (int i = 0; i <= sum; i += 2) {
      X ^= matrix[i][sum - i];
    }
  }

 // per(X);

  return X;

}

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> matrix[i][j];
    }
  }

  vector<int> xors(n/2, 0);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int A = min(i, n - 1 - i);
      int B = min(j, n - 1 - j);
      A = (n / 2 - 1 - A);
      B = (n / 2 - 1 - B);
      xors[max(A, B)] ^= matrix[i][j];
    }
  }

  for (int i = 1; i < n/2; ++i) xors[i] ^= xors[i - 1];

  int S = 0;
  int last = 0;

  for (int i = n/2-1; i >= 0; --i) {
    int tut = xors[i] ^ last;
    S ^= tut;
    last = tut;
  }

  S ^= get_diagonal(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      tatrix[i][j] = matrix[n - i - 1][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      matrix[j][i] = tatrix[j][i];
    }
  }

  S ^= get_diagonal(n);
  cout << S << '\n';



}

int main(){
#ifdef LOCAL
  freopen("C_input.txt", "r", stdin);
  //freopen("C_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}