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

const int mod = 998244353;

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

int n, m, k;
  
int sh1 = 0, sh2 = 0;

int a[2][1000007];
int b[2][1000007];

int cnt1[3];
int cnt2[3];

map<pair<int, int>, int> was;

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> m >> k;

  cnt1[2] = n;
  cnt2[2] = m;

 // was.resize(n);
 // for (int i = 0; i < n; ++i) {
 //   was[i].resize(m, -1);
 // }

  for (int i = 0; i < k; ++i) {

    int x, y, ty;
    cin >> x >> y >> ty;
    --x; --y;

    cnt1[(int)(a[0][x] == 0) + (int)(a[1][x] == 0)]--;
    cnt2[(int)(b[0][y] == 0) + (int)(b[1][y] == 0)]--;

    if (was.find(mp(x, y)) == was.end()) was[mp(x, y)] = -1;

    int val = was[mp(x, y)];

    if (val != -1) {
      if ((x + y) % 2 != val) --sh1;
      if ((x + y + 1) % 2 != val) --sh2;
    }

    if (val == 0) {
      a[y % 2][x]--;
      b[x % 2][y]--;
    }

    if (val == 1) {
      a[(y % 2) ^ 1][x]--;
      b[(x % 2) ^ 1][y]--;
    }


    was[mp(x, y)] = ty;


    if (ty != -1) {
      if ((x + y) % 2 != ty) ++sh1;
      if ((x + y + 1) % 2 != ty) ++sh2;
    }


    if (ty == 0) {
      a[y % 2][x]++;
      b[x % 2][y]++;
    }

    if (ty == 1) {
      a[(y % 2) ^ 1][x]++;
      b[(x % 2) ^ 1][y]++;
    }


    cnt1[(int)(a[0][x] == 0) + (int)(a[1][x] == 0)]++;
    cnt2[(int)(b[0][y] == 0) + (int)(b[1][y] == 0)]++;


   // per(sh1, sh2);
   // per(cnt1[0], cnt1[1], cnt1[2]);
   // per(cnt2[0], cnt2[1], cnt2[2]);

    int res = 0;
    if (sh1 == 0) dec(res, 1);
    if (sh2 == 0) dec(res, 1);

    if (cnt1[0] == 0)
    add(res, bp(2, cnt1[2]));

    if (cnt2[0] == 0)
    add(res, bp(2, cnt2[2]));

    cout << res << "\n";

  }


}