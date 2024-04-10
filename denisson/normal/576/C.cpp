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
pair<int, int> a[1000007];

vector<int> t[1007][1007];

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  readArr(a, a + n);

  for (int i = 0; i < n; ++i) {
    t[a[i].x / 1000][a[i].y / 1000].pb(i);
  }

  vector<int> d;

  for (int i = 0; i <= 1000; ++i) {
    if (i % 2 == 0) {


      for (int j = 0; j <= 1000; ++j) {

        sort(all(t[i][j]), [](int w1, int w2) {
          return a[w1] < a[w2];
        });

        for (int v : t[i][j]) d.pb(v);
      } 
    } else { 
     

      for (int j = 1000; j >= 0; --j) {

      sort(all(t[i][j]), [](int w1, int w2) {
        return a[w1] > a[w2];
      });
        
        for (int v : t[i][j]) d.pb(v);
      } 
    }
      
  }

  db res = 0;

  for (int i = 0; i + 1 < d.size(); ++i) {
    res += sqrtl((a[d[i]].x - a[d[i + 1]].x) * (ll)(a[d[i]].x - a[d[i + 1]].x) + (a[d[i]].y - a[d[i + 1]].y) * (ll)(a[d[i]].y - a[d[i + 1]].y));
  }

//  pper(res);

  for (int v : d) {
    cout << v + 1 << ' ';
  }

}