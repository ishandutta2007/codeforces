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


string s;


int id[32];
vector<int> masks;

struct Tree {
  int t[100007 * 4][15];

  void merg(int v) {
    fill(t[v], t[v] + 15, 1e9);
    for (int i = 0; i < masks.size(); ++i) {
      for (int j = 0; j < masks.size(); ++j) {
        int m1 = masks[i];
        int m2 = masks[j];
        int m = m1 | m2;

        if ((m1 >> 0) & 1) if ((m2 >> 4) & 1) continue;
        if ((m1 >> 3) & 1) if ((m2 >> 2) & 1) continue;
        if ((m1 >> 0) & 1) if ((m2 >> 1) & 1) m |= 1 << 3;
        if ((m1 >> 1) & 1) if ((m2 >> 2) & 1) m |= 1 << 4;

        uin(t[v][id[m]], t[v * 2 + 1][i] + t[v * 2 + 2][j]);
      }
    }
  }

  void build(int v, int vl, int vr) {
    if (vl == vr) {
      fill(t[v], t[v] + 15, 0);

      int now = s[vl] - 'a'; 
      int ss = 0;
      for (int m : masks) {
        if (!((m >> now) & 1)) t[v][ss] = 1;
        ++ss;
      }

    } else {
      int vm = (vl + vr) >> 1;
      build(v * 2 + 1, vl, vm);
      build(v * 2 + 2, vm + 1, vr);
      merg(v);
    }
  }

  void up(int v, int vl, int vr, int pos, char c) {
    if (vl == vr) {
      s[vl] = c;
      fill(t[v], t[v] + 15, 0);

      int now = s[vl] - 'a'; 
      int ss = 0;
      for (int m : masks) {
        if (!((m >> now) & 1)) t[v][ss] = 1;
        ++ss;
      }
    } else {
      int vm = (vl + vr) >> 1;
      if (pos <= vm) up (v * 2 + 1, vl, vm, pos, c);
      else up(v * 2 + 2, vm + 1, vr, pos, c);
      merg(v);
    }
  }
} tr;


int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  for (int i = 0; i < 32; ++i) {
    if (!((i >> 0) & 1)) {
      if ((i >> 3) & 1) continue;
    }

    if (!((i >> 1) & 1)) {
      if ((i >> 3) & 1) continue;
      if ((i >> 4) & 1) continue;
    }

    if (!((i >> 2) & 1)) {
      if ((i >> 4) & 1) continue;
    }
    id[i] = masks.size();
    masks.pb(i);
  }

  int q;
  int n;
  cin >> n >> q >> s;

  tr.build(0, 0, n - 1);

  while (q--) {
    int pos; char c;
    cin >> pos >> c;
    --pos;
    tr.up(0, 0, n - 1, pos, c);
    int res = 1e9;
    for (int i = 0; i < 15; ++i) uin(res, tr.t[0][i]);
    cout << res << "\n";
  }
}