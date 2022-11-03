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
int a[200007];
int cnt[200007];
vector<int> t[200007];

int pr[200007];

int EX = 2e5 + 1;

int last[400007];

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  readArr(a + 1, a + 1 + n);

  int v = 0;
  for (int i = 1; i <= n; ++i) {
    cnt[a[i]]++;
    if (cnt[a[i]] > cnt[v]) {
      v = a[i];
    }
    t[a[i]].pb(i);
  }

  t[v].pb(0);
  t[v].pb(n + 1);
  sort(all(t[v]));

  int res = 0;

  for (int c = 1; c <= n; ++c) if (v != c && (int)t[c].size() > 450) {

    fill(last, last + 400007, -2);
    last[EX] = 0;

    for (int i = 1; i <= n; ++i) {
      pr[i] = 0;
      if (a[i] == v) ++pr[i];
      if (a[i] == c) --pr[i];
      if (i) pr[i] += pr[i - 1];
      
      if (last[pr[i] + EX] != -2) {
        uax(res, i - last[pr[i] + EX]);
      } else last[pr[i] + EX] = i;
    }

  }

  // pper(t[v]);

  for (int c = 1; c <= n; ++c) if (v != c && (int)t[c].size() <= 450) {

    vector<int> d;
    for (int w : t[c]) {
      int vl = -1, vr = t[v].size();
      while (vl + 1 < vr) {
        int vm = (vl + vr) >> 1;
        if (t[v][vm] > w) vr = vm;
        else vl = vm;
      }
      d.pb(vl);
    }    

    // per(c, d);

    int i = 0;
    while (i < t[c].size()) {
      int j = (int)t[c].size() - 1;
      while (d[j] - d[i] > j - i + 1) {
        --j;
      }

      for (int s = max(0, d[i] - (j - i) - 3); s <= d[i]; ++s) {
        int nxt = min((int)t[v].size() - 1, s + (j - i) + 2);
        if (nxt > d[j]) {
          uax(res, t[v][nxt] - 1 - (t[v][s] + 1) + 1);
        }
      }

      ++i;
    }

  }



  cout << res;
}