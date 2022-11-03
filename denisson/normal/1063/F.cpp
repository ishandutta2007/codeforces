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

// It's strictly forbidden to use buildSA() and not 
// to add a fictitious integer, which should be smaller 
// than all other integers representing a string, to the end!!!
struct SuffixArray {
    static const int SZ = 5e5 + 7;

    int c[SZ];
    int cnt[SZ];
    int p[SZ];
    int pn[SZ];
    int cn[SZ];

    vector<int> buildSA(const vector<int>& s) {
        int n = s.size();
        int alpha = (*max_element(s.begin(), s.end())) + 1;
        memset(cnt, 0, alpha * sizeof(int));
        for (int c : s) ++cnt[c];
        for (int i = 1; i < alpha; ++i) cnt[i] += cnt[i - 1];
        for (int i = 0; i < n; ++i) p[--cnt[s[i]]] = i;
        c[p[0]] = 0;
        int cs = 1;
        for (int i = 1; i < n; ++i) {
            if (s[p[i]] != s[p[i - 1]]) ++cs;
            c[p[i]] = cs - 1;
        }

        for (int h = 0; (1 << h) < n; ++h) {
            for (int i = 0; i < n; ++i) {
                pn[i] = p[i] - (1 << h);
                if (pn[i] < 0) pn[i] += n;
            }
            memset(cnt, 0, cs * sizeof(int));
            for (int i = 0; i < n; ++i) ++cnt[c[pn[i]]];
            for (int i = 1; i < cs; ++i) cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; --i) p[--cnt[c[pn[i]]]] = pn[i];
            cn[p[0]] = 0;
            cs = 1;
            for (int i = 1; i < n; ++i) {
                int mid1 = (p[i] + (1 << h)) % n, mid2 = (p[i-1] + (1 << h)) % n;
                if (c[p[i]] != c[p[i-1]] || c[mid1] != c[mid2]) ++cs;
                cn[p[i]] = cs - 1;
            }
            memcpy (c, cn, n * sizeof(int));
        }

        vector<int> result(p, p + n);
        return result;
    }

    // suf = sa from func above
    vector<int> buildLCP(const vector<int>& s, const vector<int>& suf) const {
        int n = s.size();
        vector<int> rsuf(n);
        vector<int> lcp(n);
        for (ll i = 0; i < n; i++) {
            rsuf[suf[i]] = i;
        }

        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (k > 0) --k;
            if (rsuf[i] == n - 1) {
                lcp[n - 1] = -1;
                k = 0;
                continue;
            } else {
                int j = suf[rsuf[i] + 1];
                while (max(i + k, j + k) < n && s[i + k] == s[j + k]) ++k;
                lcp[rsuf[i]] = k;
            }
        }

        return lcp;
    }
} SA;

const int MAXN = 5e5 + 7;
const int LOGN = 19;

template<class T>
class SparseTable {
public:
  int lg[MAXN];
  int f[LOGN][MAXN];

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

SparseTable<int> st_lcp;

struct Tree {

  int t[4 * 500007];

  void build(int v, int vl, int vr) {
    t[v] = -1;
    if (vl == vr) {

    } else {
      int vm = (vl + vr) >> 1;
      build(v * 2 + 1, vl, vm);
      build(v * 2 + 2, vm + 1, vr);
    }
  }

  void up(int v, int vl, int vr, int pos, int val) {
    if (vl == vr) {
      t[v] = val;
    } else {
      int vm = (vl + vr) >> 1;
      if (pos <= vm) up(v * 2 + 1, vl, vm, pos, val);
      else up(v * 2 + 2, vm + 1, vr, pos, val);
      t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
    }
  }

  int get(int v, int vl, int vr, int l, int r) {
    if (r < vl || l > vr) return -1;
    if (vl >= l && vr <= r) return t[v];
    int vm = (vl + vr) >> 1;
    return max(get(v * 2 + 1, vl, vm, l, r), get(v * 2 + 2, vm + 1, vr, l, r)); 
  }

} tr;

string s;

int dp[500007];
vector<int> sa, lcp;
int to_pos[500007];

bool check(int v, int k) {
  if (v >= s.size()) return 0;

  int le, ri;

  int vl = -1, vr = to_pos[v];
  while (vl + 1 < vr) {
    int vm = (vl + vr) >> 1;
    if (st_lcp.get(vm, to_pos[v] - 1) < k) vl = vm; else vr = vm;
  }

  le = vr;

  vl = to_pos[v], vr = sa.size();
  while (vl + 1 < vr) {
    int vm = (vl + vr) >> 1;
    if (st_lcp.get(to_pos[v], vm - 1) < k) vr = vm; else vl = vm;
  }

  ri = vl;

  // per("===", v, k, le, ri, tr.get(0, 0, sa.size(), le, ri), "===");

  return tr.get(0, 0, sa.size(), le, ri) >= k; 
}

int ok(int v, int k) {
  if (k == 1) return 1;
  return check(v, k - 1) || check(v - 1, k - 1);
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> s >> s; // reverse(all(s));

  vector<int> t;
  for (char c : s) t.pb(c - 'a' + 1); t.pb(0);

  sa = SA.buildSA(t);
  lcp = SA.buildLCP(t, sa);

  // pper(sa);
  // pper(lcp);
  // pper(s);

  for (int i = 1; i < sa.size(); ++i) to_pos[(int)s.size() - 1 - sa[i]] = i;

  tr.build(0, 0, sa.size());
  st_lcp.build(lcp.data(), lcp.size());

  int le = 0;
  dp[0] = 1;
  for (int i = 1; i < s.size(); ++i) {

    dp[i] = dp[i - 1] + 1;

    while (!ok(i, dp[i])) {
      tr.up(0, 0, sa.size(), to_pos[le], dp[le]); ++le;
      --dp[i];
    }

    // per(i, dp[i]);
  }


  cout << (*max_element(dp, dp + 500007));
}