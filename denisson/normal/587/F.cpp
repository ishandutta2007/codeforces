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

// After all add's call buildSuf and then call buildAu

struct Aho {
    struct Vert {
        int to[26]; // tree edge
        int au[26]; // automata edge
        int suf;    // suf link
        int p;      // parent
        int c;      // edge char between vertex and parent
        vector<int> z;
        Vert() { for (int i = 0; i < 26; i++) to[i] = -1, au[i] = 0; suf = 0; }
    };

    Vert t[100007];
    int sz;
    vector<int> ord;
    vector<int> s[100007];

    Aho() { sz = 1; }

    int add(const string& s) {
        int v = 0;
        for (char c : s){
            int now = c - 'a';
            if (t[v].to[now] == -1) t[sz].p = v, t[sz].c = now, t[v].to[now] = sz++;
            v = t[v].to[now];
        }
        return v;
    }

    void buildSuf() {
        vector<int> st;
        int uk = 0;
        st.push_back(0);
        while(uk < st.size()){
            int v = st[uk++];
            if (v == 0 || t[v].p == 0) t[v].suf = 0;
            else {
                int cur = t[t[v].p].suf;
                while(1){
                    if (t[cur].to[t[v].c] != -1){
                        t[v].suf = t[cur].to[t[v].c];
                        break;
                    }
                    if (cur == 0) break;
                    cur = t[cur].suf;
                }
            }
            for (int i = 0; i < 26; i++) if (t[v].to[i] != -1) st.pb(t[v].to[i]);
        }
        ord = st; reverse(all(ord));
        for (int i = 1; i < sz; ++i) s[t[i].suf].pb(i);
    }

    void buildAu() {
        vector<int> st;
        int uk = 0;
        st.push_back(0);
        while(uk < st.size()){
            int v = st[uk++];
            for (int i = 0; i < 26; i++){
                if (t[v].to[i] != -1) t[v].au[i] = t[v].to[i];
                else {
                    t[v].au[i] = t[t[v].suf].au[i];
                }
            }
            for (int i = 0; i < 26; i++) if (t[v].to[i] != -1) st.pb(t[v].to[i]);
        }
    }
} ah;


struct KEKOSINA {
  const int JU = 350;
  ll su[355];
  ll a[110007];

  void add(int v, ll val) {
    for (int i = v / JU; i < 355; ++i) su[i] += val;
    while (1) {
      a[v] += val;
      ++v;
      if (v % JU == 0) break;
    }
  }

  ll get(int v) {
    ll val = a[v];
    if (v / JU) val += su[(v / JU) - 1];
    return val;
  }

  ll get(int vl, int vr) {
    ll res = get(vr);
    if (vl) res -= get(vl - 1);
    return res;
  }
} ke;

int n, q;
string a[100007];
ll ans[100007];
vector<pair<int, pair<int, int>>> d[100007];

ll f[100007];
ll g[100007];
vector<int> p[100007];

void dfs(int v = 0) {

  // per(v);

  for (auto c : ah.t[v].z) ke.add(c, 1);

  for (auto c : p[v]) for (auto z : d[c]) ans[z.x] += ke.get(z.y.x, z.y.y);

/*
  pper(v);
  pper(ah.t[v].z);
  pper(p[v]);
  pper(ke.get(0, 3));
  cout << endl;
  cout << endl;
*/

  for (int to : ah.s[v]) dfs(to);

  for (auto c : ah.t[v].z) ke.add(c, -1);
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> q;
  readArr(a, a + n);

  for (int i = 0; i < n; ++i) {
    int v = ah.add(a[i]);
    ah.t[v].z.pb(i);
    // per("i, v: ", i, v, a[i]);
  }

  for (int i = 0; i < q; ++i) {
    int l, r, k;
    cin >> l >> r >> k;
    --l; --r; --k;
    d[k].pb(mp(i, mp(l, r)));
  }

  ah.buildSuf();
  ah.buildAu();

  const int MAG = sqrt(1e5) + 7;

  for (int i = 0; i < n; ++i) if (a[i].size() > MAG) {
    fill(f, f + 100007, 0);
    fill(g, g + 100007, 0);
    int v = 0;
    for (char c : a[i]) v = ah.t[v].au[c - 'a'], f[v]++; //, per(i, v);

    for (int j : ah.ord) {
      f[ah.t[j].suf] += f[j];
      for (auto c : ah.t[j].z) g[c] = f[j];
    }

    for (int j = 1; j < 100007; ++j) g[j] += g[j - 1];


    for (auto c : d[i]) {
      ans[c.x] = g[c.y.y];
      if (c.y.x) ans[c.x] -= g[c.y.x - 1];
    } 
  } else {
    int v = 0;
    for (char c : a[i]) v = ah.t[v].au[c - 'a'], p[v].pb(i);
  }
  
  dfs();

  for (int i = 0; i < q; ++i) cout << ans[i] << '\n';

}