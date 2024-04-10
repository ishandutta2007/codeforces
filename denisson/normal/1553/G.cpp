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
     
    struct Node {
      int p, r, f;
    };
     
    struct DSU {
      static const int SZ = 200007;
      Node t[SZ];
     
      DSU() { reset(SZ); }
     
      void reset(int n) {
        for (int i = 0; i < n; ++i) {
          t[i].p = i;
          t[i].r = 0;
          t[i].f = 1;
        }
      }
     
      int get(int v) {
        if (t[v].p == v) return v;
        return t[v].p = get(t[v].p);
      }
     
      int get_func(int v) {
        return t[get(v)].f;
      }
     
      void merge(int a, int b) {
        a = get(a), b = get(b);
        if (a != b) {
          if (t[a].r < t[b].r) swap(a, b);
          t[b].p = a;
          t[a].f += t[b].f;
          if (t[a].r == t[b].r) ++t[a].r;
        }
      }
    } dsu;
     
     
    int n, q;
    int a[150087];
     
    int need[1000087];
     
    vector<int> was[1000087];
     
    int la[1000087];
     
    vector<int> save[1000087];
     
    int main(){
    #ifdef LOCAL
    	freopen("G_input.txt", "r", stdin);
    	//freopen("G_output.txt", "w", stdout);
    #endif
    	ios_base::sync_with_stdio(0);
    	cin.tie(0);
     
      cin >> n >> q;
      readArr(a, a + n);
     
      for (int i = 0; i < n; ++i) was[a[i]].pb(i);
     
      for (int i = 2; i <= 1000007; ++i) if (!need[i]) {
        int last = -1;
        for (int j = i; j <= 1000007; j = j + i) {
     
          save[j].pb(i);
     
          need[j] = 1;
     
          for (int v : was[j]) {
            if (last != -1) {
              dsu.merge(last, v);
            } else {
              last = v;
            }
          }
        }
        la[i] = last;
      }
     
      vector<pair<int, int> > kek;
     
      for (int i = 0; i < n; ++i) {
     
        int ex = save[a[i]][0];
     
        for (int x : save[a[i] + 1]) if (la[x] != -1) {
          for (int y : save[a[i] + 1]) if (la[y] != -1) {
     
            int w1 = dsu.get(la[x]), w2 = dsu.get(la[y]);
     
            if (w1 > w2) swap(w1, w2);
            if (w1 != w2) kek.pb(mp(w1, w2));
          } 
        }
     
     
        for (int x : save[a[i] + 1]) if (la[x] != -1 && la[ex] != -1) {
          int w1 = dsu.get(la[x]), w2 = dsu.get(la[ex]);
     
          if (w1 > w2) swap(w1, w2);
          if (w1 != w2) kek.pb(mp(w1, w2));
        }
      }
     
      sort(all(kek));
     
      while (q--) {
        int w1, w2;
        cin >> w1 >> w2;
        --w1; --w2;
     
        w1 = dsu.get(w1);
        w2 = dsu.get(w2);
     
     //   pper(w1);
    //    pper(w2);
     
        if (w1 == w2) {
          cout << "0\n";
        } else {
     
          if (w1 > w2) swap(w1, w2);
     
          int vl = -1, vr = kek.size();
          while (vl + 1 < vr) {
            int vm = (vl + vr) >> 1;
            if (kek[vm] <= mp(w1, w2)) vl = vm;
            else vr = vm;
          }
     
          if (vl != -1 && kek[vl] == mp(w1, w2)) cout << "1\n"; else cout << "2\n";
     
        }
      }
     
    }