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

int n, m;
int a[1007][1007];
int b[1007][1007];

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

    cin >> n >> m;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j], --a[i][j];

    string s;
    cin >> s;

    vector<int> t = {0, 1, 2};
    int ex[] = {0, 0, 0};

    for (char c : s) {
      if (c == 'R') {
        ex[1]++;
      } else if (c == 'L'){
        ex[1] += n - 1;
      } else if (c == 'D') {
        ex[0]++;
      } else if (c == 'U') {
        ex[0] += n - 1;
      } else if (c == 'C') {
        swap(t[0], t[2]);
        swap(ex[0], ex[2]);
      } else {
        swap(t[1], t[2]);
        swap(ex[1], ex[2]);
      }
    }

    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
      int dd[] = {i, j, a[i][j]};
      
      int ddd[3];
      ddd[0] = (dd[t[0]] + ex[0]) % n;
      ddd[1] = (dd[t[1]] + ex[1]) % n;
      ddd[2] = (dd[t[2]] + ex[2]) % n;

      b[ddd[0]][ddd[1]] = ddd[2];

    }


    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << b[i][j] + 1 << ' ';
      }
      cout << "\n";
    }

   // cout << "\n";

  }
}