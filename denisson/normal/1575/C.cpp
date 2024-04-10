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


#define db long double

class cn {
public:
  db x, y;
  cn(){}
  cn(db xx, db yy): x(xx), y(yy) {}
  cn(db xx): x(xx), y(0) {}
  db real() { return x; }
  void operator /= (double f) { x /= f; y /= f; }
};

cn operator + (cn a, cn b) { return cn(a.x + b.x, a.y + b.y); }
cn operator - (cn a, cn b) { return cn(a.x - b.x, a.y - b.y); }
cn operator * (cn a, cn b) { return cn(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }

class FFT {
public:
  constexpr static db pi = acos(-1.0);
  const static int MAX_SIZE = 1 << 21;

  //#define cn complex<db>

  int n;
  cn a[MAX_SIZE * 2 + 7], b[MAX_SIZE * 2 + 7];

  int getReverse(int a, int k){
    int ans = 0;
    for (int i = 0; i < k; i++) if ((a >> i) & 1) ans ^= (1 << (k - i - 1));
    return ans;
  }

  void fft(cn *a, int type){
    int k = -1;
    for (int i = 0; i < 25; i++) if ((n >> i) & 1){ 
      k = i;
      break;
    }
    for (int i = 0; i < n; i++){
      int j = getReverse(i, k);
      if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len *= 2){
      cn w(cos(2 * pi / (db)len), sin(2 * pi / (db)len) * type);
      for (int i = 0; i < n; i += len){
        cn g = cn(1, 0);
        for (int j = 0; j < len / 2; j++){
          cn x = a[i + j];
          cn y = a[i + j + len / 2] * g;
          a[i + j] = x + y;
          a[i + j + len / 2] = x - y;
          g = g * w;
        }
      }
    }
    if (type == -1) for (int i = 0; i < n; i++) a[i] /= n; 
  }

  vector<int> mult(vector<int> &w1, vector<int> &w2){
    n = 1;
    while(n < w1.size() + w2.size()) n <<= 1;
    std::copy(w1.begin(), w1.end(), a);
    std::copy(w2.begin(), w2.end(), b);
    std::fill(a + w1.size(), a + n, 0);
    std::fill(b + w2.size(), b + n, 0);
    fft(a, 1);
    fft(b, 1);
    for (int i = 0; i < n; i++) a[i] = a[i] * b[i];
    fft(a, -1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) ans[i] = (ll)floor((db)a[i].real() + 0.5) % mod;
    while(ans.size() && ans.back() == 0) ans.pop_back();
    return ans;
  }
} fft;


int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] %= k;
  }

  int res = 0;
  vector<int> cnt(k, 0);
  cnt[0] = 1;

  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum = (sum + a[i]) % k;
    add(res, cnt[sum]);
    ++cnt[sum];
  }
  if (m == 1 && !sum) {
    dec(res, 1);
  }

  --cnt[0];
  --cnt[sum];
  int full = (m - 1) * (ll) sum % k;
  int nsum = 0;
  int wsum = sum;

  for (int i = n - 1; i > 0; --i) {
    nsum = (nsum + a[i]) % k;
    int need = (2 * k - nsum - full) % k;
    wsum = (wsum - a[i] + k) % k;
    --cnt[wsum];

    add(res, cnt[need]);
  }


  /////////////

  vector <int> ca(k, 0);
  vector <int> cb(k, 0);

  int now = 0;
  for (int i = 0; i < n; ++i) {
    now = (now + a[i]) % k;
    ++ca[now];
  }
  now = 0;
  for (int i = n - 1; i >= 0; --i) {
    now = (now + a[i]) % k;
    ++cb[now];
  }

  auto d = fft.mult(ca, cb);
  while (d.size() > k) {
    add(d[(d.size() - 1) % k], d.back());
    d.pop_back();
  }

  for (int blocks = 0; blocks <= m - 2; ++blocks) {
    int full = sum * (ll) blocks % k;
    int need = (k - full) % k;

    add(res, d[need]);
    if (blocks == m - 2 && (!sum || m % k == 0)) {
      dec(res, 1);
    }
  }

  /////////////



  res = mult(res, m);
  if (!sum || m % k == 0) {
    add(res, 1);
  }
  cout << res << "\n";
}