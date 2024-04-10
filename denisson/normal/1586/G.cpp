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
     
     
    const size_t MAX_BIT = 19;
    const size_t MAX_SIZE = 1 << MAX_BIT;
     
    /*
     * Fenwick tree on range [0..MAX_SIZE-1]
     *
     *   Range sum    [vl..vr]    - get(vl, vr)
     *   Point update t[v] += val - up(v, val)
     */
     
    struct FenwickTree1 {
      int t[MAX_SIZE];
     
      // Sum [0..v]
      int get(int v) {
        int res = 0;
        for (; v >= 0; v = (v & (v + 1)) - 1) {
          add(res, t[v]);
        }
        return res;
      }
     
      // Sum [vl..vr]
      int get(int vl, int vr) {
        int res = get(vr);
        if (vl > 0) {
          dec(res, get(vl - 1));
        }
        return res;
      }
     
      // Update t[v] += val;
      void up(int v, int val) {
        for (; v < MAX_SIZE; v = v | (v + 1)) {
          add(t[v], val);
        }
      }
    } f;
     
    int n;
    pair<int, int> a[400007];
     
    vector<int> ord;
     
    vector<pair<int, int>> zap[400007];
     
    int main(){
    #ifdef LOCAL
    	freopen("G_input.txt", "r", stdin);
    	//freopen("G_output.txt", "w", stdout);
    #endif
    	ios_base::sync_with_stdio(0);
    	cin.tie(0);
     
      cin >> n;
      readArr(a, a + n);
     
      int sz;
      cin >> sz;
      ord.resize(sz);
      readArr(all(ord));
      for (int& x : ord) --x;
     
      int res = 0;
      vector<int> t;
      for (int i = 0; i < n; ++i) t.pb(i);
     
      sort(all(t), [](int w1, int w2) {
        return a[w1].y < a[w2].y;
      });
     
      
      sort(all(ord), [](int w1, int w2) {
        return a[w1].y > a[w2].y;
      });
     
      int last = 0;
     
      for (int i = 0; i < ord.size(); ++i) {
        int v = ord[i];
     
      //  per("====", last, a[v].y);
     
        if (a[v].y < last) break;
        if (a[v].x < last) continue;
     
        zap[a[v].y].pb(mp(last, a[v].y));
     
        last = a[v].x;
     
      }
     
     
      for (int v : t) {
     
        for (auto c : zap[a[v].y]) {
          add(res, 1);
          add(res, f.get(c.x, c.y));
        }
     
        int val = 1;
        add(val, f.get(a[v].x, 2 * n));
        f.up(a[v].x, val);
     
       // cout << a[v].y << ' ' << val << endl;
     
     
      }
     
      cout << res;
     
     
    }