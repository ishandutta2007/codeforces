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
	//freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, k;
  cin >> n >> k;

  vector<int> ors, ands;
  for (int i = 0; i + 1 < n; ++i) {
    cout << "or " << i+1 << " " << i+2 << endl;
    int x;
    cin >> x;

    ors.pb(x);

    cout << "and " << i+1 << " " << i+2 << endl;
    cin >> x;

    ands.pb(x);
  }

  cout << "or " << 1 << " " << 3 << endl;
  int x;
  cin >> x;

  ors.pb(x);

  cout << "and " << 1 << " " << 3 << endl;
  cin >> x;

  ands.pb(x);

  vector<int> num(n, 0);
  for (int i = 0; i < 30; ++i) {
    for (int start = 0; start < 2; ++start) {
      vector<int> t(n, 0);
      t[0] = start;
      bool good = true;

      for (int j = 1; j < n; ++j) {
        bool was = false;

        int res_or = (((1<<i)&ors[j - 1]) > 0);
        int res_and = (((1<<i)&ands[j - 1]) > 0);

        for (int e = 0; e < 2; ++e) {
          if ((e | t[j - 1]) == res_or && (e&t[j-1]) == res_and) {
            t[j] = e;
            was = true;
          }
        }

        if (!was) {
          good = false;
          break;
        }
      }

      int res_or = (((1<<i)&ors.back()) > 0);
      int res_and = (((1<<i)&ands.back()) > 0);

      if (!((t[0] | t[2]) == res_or && (t[0] & t[2]) == res_and)) {
        good = false;
      }

      if (good) {
        for (int j = 0; j < n; ++j) num[j] += (1<<i) * t[j];
      }

    }
  }

  sort(all(num));

  cout << "finish " << num[k - 1] << endl;



}