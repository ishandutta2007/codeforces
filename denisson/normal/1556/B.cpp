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
    ll a[100007];
     
     
    void solve() {
     
      cin >> n;
      readArr(a, a + n);
     
      int c0 = 0, c1 = 0;
      vector<int> d[2];
      for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) ++c0; else c1++;
        d[a[i] % 2].pb(i);
      }
     
      if (abs(c0 - c1) > 1) {
        cout << "-1\n"; return;
      }
     
      ll res = 1e18;
     
      if (n % 2 == 0) {
     
        ll now1 = 0;
        ll now2 = 0;
        int j = 0;
        for (int i = 0; i < n; i += 2) {
          now1 += abs(i - d[0][j]);
          now2 += abs(i - d[1][j++]);
        }
     
        res = min(now1, now2);
     
      } else {
     
        res = 0;
        int j = 0;
        if (c0 > c1) {
     
          for (int i = 0; i < n; i += 2) {
            res += abs(i - d[0][j++]);
          }
     
        } else {
     
     
          for (int i = 0; i < n; i += 2) {
            res += abs(i - d[1][j++]);
          }
        }
     
      }
     
      cout << res << "\n";
    }
     
    int main(){
    #ifdef LOCAL
    	freopen("B_input.txt", "r", stdin);
    	//freopen("B_output.txt", "w", stdout);
    #endif
    	ios_base::sync_with_stdio(0);
    	cin.tie(0);
     
      int tt;
      cin >> tt;
      while (tt--) {
        solve();
      }
     
    }