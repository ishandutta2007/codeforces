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
    static const int SZ = 4e5 + 7;

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


const size_t MAX_BIT = 18;
const size_t MAX_SIZE = 1 << MAX_BIT;

/*
 * Fenwick tree on range [0..MAX_SIZE-1]
 *
 *   Range sum    [vl..vr]    - get(vl, vr)
 *   Point update t[v] += val - up(v, val)
 */

struct FenwickTree1 {
  ll t[MAX_SIZE];

  // Sum [0..v]
  ll get(int v) {
    ll res = 0;
    for (; v >= 0; v = (v & (v + 1)) - 1) {
      res += t[v];
    }
    return res;
  }

  // Sum [vl..vr]
  ll get(int vl, int vr) {
    ll res = get(vr);
    if (vl > 0) {
      res -= get(vl - 1);
    }
    return res;
  }

  // Get the leftmost position with a sum >= k
  int getKth(int k) {
    int i = 0;
    for (int bit = MAX_BIT; bit >= 0; bit--) {
      int x = i + (1 << bit) - 1;
      if (x >= MAX_SIZE) {
        continue;
      }
      if (t[x] <= k) {
        i += (1 << bit);
        k -= t[x];
      }
    }
    return i;
  }

  // Update t[v] += val;
  void up(int v, int val) {
    for (; v < MAX_SIZE; v = v | (v + 1)) {
      t[v] += val;
    }
  }
} ff;

int lg[500007];
int f[18][500007];
 
inline int getF(int vl, int vr) {
  int lvl = lg[vr - vl + 1];
  return min(f[lvl][vl], f[lvl][vr - (1 << lvl) + 1]);
}
 

int n, q;
string a[500007];
int ans[500007];
int pos[500007];
int start[500007];

vector<pair<pair<int, int>, pair<int, int>>> z[500007];

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> q;
  readArr(a, a + n);

  vector<int> t;
  vector<int> d;
  for (int i = 0; i < n; ++i) {
    start[t.size()] = i + 1;
    for (char c : a[i]) t.pb(c - 'a' + n), d.pb(i);
    t.pb(i); d.pb(-1);
  }

  auto sa = SA.buildSA(t);
  auto lcp = SA.buildLCP(t, sa);

  // pper(sa);
  // pper(lcp);

  for (int i = 0; i < sa.size(); ++i) {
    if (start[sa[i]] > 0) {
      // per(start[sa[i]], i);
      pos[start[sa[i]] - 1] = i;
    }
    // cout << i << ' ' << d[sa[i]] << ' ' << lcp[i] << endl;
  }


  for (int i = 2; i < 500007; ++i) lg[i] = lg[i >> 1] + 1;

  for (int lvl = 0; lvl < 18; ++lvl) {
    int len = (1 << lvl);
    for (int vl = 0; ; ++vl) {
      int vr = vl + len - 1;
      if (vr >= lcp.size()) break;
      if (vl == vr) {
        f[lvl][vl] = lcp[vl];
      } else {
        f[lvl][vl] = min(f[lvl - 1][vl], f[lvl - 1][vl + (len >> 1)]);
      }
    }
  }

  for (int i = 0; i < q; ++i) {
    int l, r, k;
    cin >> l >> r >> k;
    --l; --r; --k;

    int v = pos[k];

    int vl = -1, vr = v;
    while (vl + 1 < vr) {
      int vm = (vl + vr) >> 1;
      if (getF(vm, v - 1) < a[k].size()) vl = vm; else vr = vm;
    }

    int le = vr;

    vl = v, vr = sa.size();
    while (vl + 1 < vr) {
      int vm = (vl + vr) >> 1;
      if (getF(v, vm - 1) < a[k].size()) vr = vm; else vl = vm;
    }

    int ri = vl;

    // per(le, ri, v);

    if (le > 0)
    z[le - 1].pb(mp(mp(i, -1), mp(l, r)));
    z[ri].pb(mp(mp(i, 1), mp(l, r)));

  }

  for (int i = 0; i < sa.size(); ++i) {
    if (d[sa[i]] != -1) {
      ff.up(d[sa[i]], 1);
    }
    for (auto c : z[i]) {
      ans[c.x.x] += c.x.y * ff.get(c.y.x, c.y.y);
    }
  }

  for (int i = 0; i < q; ++i) cout << ans[i] << ' ';

}