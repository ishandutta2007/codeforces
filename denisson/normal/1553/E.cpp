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
    int a[300007];
     
    int cnt[300007];
     
    bool can(int sh) {
     
     // pper(sh);
     
      vector<int> t(n);
      for (int i = 0; i < n; ++i) t[i] = i;
      std::rotate(t.begin(), t.begin() + n - sh, t.end());
     
      vector<int> w1, w2;
     
      for (int i = 0; i < n; ++i) if (a[i] != t[i]) {
        w1.pb(a[i]);
        w2.pb(t[i]);
      }
     
      map<int, int> to;
     
      for (int i = 0; i < w2.size(); ++i) to[w2[i]] = i;
     
      for (int& x : w1) x = to[x];
     
      int need = 0;
     
      vector<bool> was(w1.size(), 0);
     
      for (int i = 0; i < w1.size(); ++i) if (!was[i]) {
        int v = i;
        int now = 0;
        while (!was[v]) {
          was[v] = 1;
          ++now;
          v = w1[v];
        }
        need += now - 1;
      } 
      
      return need <= m;
    }
     
    void solve() {
      cin >> n >> m;
      readArr(a, a + n);
     
      fill(cnt, cnt + n, 0);
     
      for (int i = 0; i < n; ++i) {
        --a[i];
        if (a[i] == i) {
          ++cnt[0];      
        } else if (a[i] < i) {
          ++cnt[i - a[i]];
        } else {
          ++cnt[i - a[i] + n];
        }
      }
     
      vector<pair<int, int>> tryy;
      for (int i = 0; i < n; ++i) tryy.pb(mp(cnt[i], i));
      sort(all(tryy));
      reverse(all(tryy));
     
      vector<int> res;
      for (int i = 0; i < min(4, (int)tryy.size()); ++i) if (can(tryy[i].y)) res.pb(tryy[i].y);
     
     
      cout << res.size() << " ";
      sort(all(res));
      for (int x : res) cout << x << ' ';
      cout << "\n";
    }
     
     
     
    int main(){
    #ifdef LOCAL
    	freopen("E_input.txt", "r", stdin);
    	//freopen("E_output.txt", "w", stdout);
    #endif
    	ios_base::sync_with_stdio(0);
    	cin.tie(0);
     
      int tt;
      cin >> tt;
      while (tt--) {
        solve();
      }
     
    }