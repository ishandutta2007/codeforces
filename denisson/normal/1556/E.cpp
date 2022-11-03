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
     
    const int MAXN = 1e5 + 7;
    const int LOGN = 18;
     
    template<class T>
    class SparseTableMin {
    public:
      int lg[MAXN];
      T f[LOGN][MAXN];
     
      void build(T* a, int sz) {
        for (int i = 2; i < MAXN; ++i) lg[i] = lg[i / 2] + 1;
     
        for (int lvl = 0; lvl < LOGN; ++lvl) {
          int len = 1 << lvl;
          for (int vl = 0, vr = len - 1; vr < sz; ++vl, ++vr) {
            if (lvl == 0) {
              f[lvl][vl] = a[vl];
            } else {
              f[lvl][vl] = min(f[lvl - 1][vl], f[lvl - 1][vl + (len >> 1)]);
            }
          }
        }
      }
     
      T get(int vl, int vr) const {
        int lvl = lg[vr - vl + 1];
        return min(f[lvl][vl], f[lvl][vr - (1 << lvl) + 1]);
      }
     
    };
     
    SparseTableMin<ll> ST_min;
     
    template<class T>
    class SparseTableMAX {
    public:
      int lg[MAXN];
      T f[LOGN][MAXN];
     
      void build(T* a, int sz) {
        for (int i = 2; i < MAXN; ++i) lg[i] = lg[i / 2] + 1;
     
        for (int lvl = 0; lvl < LOGN; ++lvl) {
          int len = 1 << lvl;
          for (int vl = 0, vr = len - 1; vr < sz; ++vl, ++vr) {
            if (lvl == 0) {
              f[lvl][vl] = a[vl];
            } else {
              f[lvl][vl] = max(f[lvl - 1][vl], f[lvl - 1][vl + (len >> 1)]);
            }
          }
        }
      }
     
      T get(int vl, int vr) const {
        int lvl = lg[vr - vl + 1];
        return max(f[lvl][vl], f[lvl][vr - (1 << lvl) + 1]);
      }
     
    };
     
    SparseTableMAX<ll> ST_max;
     
    int n;
    ll a[100007];
     
    int main(){
    #ifdef LOCAL
    	freopen("E_input.txt", "r", stdin);
    	//freopen("E_output.txt", "w", stdout);
    #endif
    	ios_base::sync_with_stdio(0);
    	cin.tie(0);
     
      int m;
      cin >> n >> m;
      readArr(a, a + n);
      for (int i = 0; i < n; ++i) {
        ll x; cin >> x; a[i] -= x;
      }
     
      for (int i = 1; i < n; ++i) a[i] += a[i - 1];
     
     
      ST_min.build(a, n);
      ST_max.build(a, n);
     
      while (m--) {
        int vl, vr;
        cin >> vl >> vr;
        --vl; --vr;
        ll pr = 0;
        if (vl) pr = a[vl - 1];
     
        if (a[vr] != pr) {
          cout << "-1\n"; continue;
        }
     
        if (ST_max.get(vl, vr) - pr > 0) {
          cout << "-1\n"; continue;
        }
     
        cout << -(ST_min.get(vl, vr) - pr) << "\n";
     
      }
     
    }