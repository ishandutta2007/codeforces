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
    set<int> se[200007];
     
    int getk(int v) {
      if (se[v].size() == 0) return 0;
      if ((*prev(se[v].end())) > v) return 1;
      return 0;
    }
     
    int main(){
    #ifdef LOCAL
    	freopen("A_input.txt", "r", stdin);
    	//freopen("A_output.txt", "w", stdout);
    #endif
    	ios_base::sync_with_stdio(0);
    	cin.tie(0);
     
      cin >> n >> m;
      for (int i = 0; i < m; ++i) {
        int w1, w2;
        cin >> w1 >> w2;
        --w1; --w2;
        se[w1].insert(w2);
        se[w2].insert(w1);
      }
     
      int ans = 0;
     
      for (int v = 0; v < n; ++v) {
        if (se[v].size() && (*prev(se[v].end()) > v)) ++ans;
      }
     
      int q; cin >> q;
      while (q--) {
        
        int ty;
        cin >> ty;
        if (ty == 3) {
          cout << n - ans << "\n";
        }  else if (ty == 1) {
     
          int w1, w2; cin >> w1 >> w2; --w1; --w2;
     
          ans -= getk(w1);
          ans -= getk(w2);
          se[w1].insert(w2);
          se[w2].insert(w1);
     
          ans += getk(w1);
          ans += getk(w2);
     
     
        }  else {
     
          int w1, w2; cin >> w1 >> w2; --w1; --w2;
          
          ans -= getk(w1);
          ans -= getk(w2);
          se[w1].erase(w2);
          se[w2].erase(w1);
     
          ans += getk(w1);
          ans += getk(w2);
        }  
      }
     
     
    }