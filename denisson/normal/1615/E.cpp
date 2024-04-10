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

ll n, k;
vector<int> g[200007];

multiset<int> se[200007];
// int ad[200007];


void dfs(int v, int p = -1) {
  int go = 0;
  
  for (int to : g[v]) if (to != p) {
    dfs(to, v);
    go = 1;

   // ad[to] += 1;
    if (se[v].size() < se[to].size()) {
      swap(se[v], se[to]);
   //   swap(ad[v], ad[to]);
    }
/*
    while (se[to].size() && se[v].size()) {
      int le =  (*se[v].begin());
      int ri = (*prev(se[to].end()));
      if (le < ri) {
        se[v].erase(se[v].begin());
        se[v].insert( (*prev(se[to].end())));
        se[to].erase(prev(se[to].end()));
      } else break;
    }
*/
    for (int x : se[to]) se[v].insert(x);

    se[to].clear();

  }


  if (go == 0) {
    se[v].insert(0);
  } else {
    if (se[v].size()) {
      int last = *prev(se[v].end());
      se[v].erase(prev(se[v].end()));
      se[v].insert(last + 1);
    }
  }

//  per(v, se[v]);
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);


  cin >> n >> k;
  for (int i = 1; i < n; ++i) {
    int w1 ,w2;
    cin >> w1 >> w2;
    --w1; --w2;
    g[w1].pb(w2);
    g[w2].pb(w1);
  }

  dfs(0);
  vector<int> t;
  for (auto c : se[0]) t.pb(c);
  sort(all(t));
  reverse(all(t));

 // pper(se[0]);

  ll res = -1e18;

  ll r = 0, w = 0;
  for (int i = 0; i < min((ll)t.size(), k); ++i) {
    ++r;
    w += t[i];
    ll b = min(n - w - r, (ll)(n >> 1));

    uax(res, (n - b - r) * (ll)(r - b));

  }

  if (t.size() < k) {
    ll r = min(k, (ll)(n >> 1));
    uax(res, (n - r) * (ll)r);
  }

  cout << res;
}