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


struct Tree {
  int t[400007 * 4];
  int p[400007 * 4];

  void push(int v) {
    if (p[v]) {
      t[v] += p[v];

      if (v * 2 + 1 < 400007 * 4) p[v * 2 + 1] += p[v];
      if (v * 2 + 2 < 400007 * 4) p[v * 2 + 2] += p[v];

      p[v] = 0;    
    }
  }

  void add(int v, int vl, int vr, int l, int r, int val) {
    push(v);
    if (l > r) return;
    if (r < vl || l > vr) return;
    if (vl >= l && vr <= r) {
      p[v] += val;
      push(v);
    } else {
      int vm = (vl + vr) >> 1;
      add(v * 2 + 1, vl, vm, l, r, val);
      add(v * 2 + 2, vm + 1, vr, l, r, val);
      t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
    }
  }

  int get(int v, int vl, int vr, int l, int r) {
    if (r < vl || l > vr) return -1;
    if (vl >=l && vr <= r) return t[v];
    int vm = (vl + vr) >> 1;
    return max(get(v * 2 + 1, vl, vm, l, r), get(v * 2 + 2, vm + 1, vr, l, r));
  }
} tr;




struct Tree2 {
  pair<int, int> t[400007 * 4];

  void up(int v, int vl, int vr, int pos, int val) {
    if (vl == vr) {
      t[v] = mp(val, vl);
    } else {
      int vm = (vl + vr) >> 1;
      if (pos <= vm)
      up(v * 2 + 1, vl, vm, pos, val);
      else
      up(v * 2 + 2, vm + 1, vr, pos, val);
      t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
    }
  }

  pair<int, int> get(int v, int vl, int vr, int l, int r) {
    if (r < vl || l > vr) return mp(1e9, -1);
    if (vl >=l && vr <= r) return t[v];
    int vm = (vl + vr) >> 1;
    return min(get(v * 2 + 1, vl, vm, l, r), get(v * 2 + 2, vm + 1, vr, l, r));
  }
} f2;



int n;
int a[400007];

void build(int vl, int vr) {
  if (vl != vr) {
    auto [_, vm] = f2.get(0, 0, n, vl, vr);
    if (vl < vm) tr.add(0, 0, 2 * n, vl, vm - 1, 1), build(vl, vm - 1);
    if (vm + 1 <= vr) tr.add(0, 0, 2 * n, vm + 1, vr, 1), build(vm + 1, vr);
  }
}

int prv[400007];
int nxt[400007];

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  readArr(a, a + n);


  for (int i = 0; i < n; ++i) --a[i], f2.up(0, 0, n, i, a[i]);

  copy(a, a + n, a + n);


  int best = 1e9, best_pos = -1;




  fill(prv, prv + 400007, -1);
  fill(nxt, nxt + 400007, -1);


  vector<pair<int, int> > st;

  for (int i = 0; i < n * 2; ++i) {

    while (st.size()) {
      if (st.back().x >= a[i]) st.pop_back(); else {
        prv[i] = st.back().y;
        break;
      }
    }

    st.pb(mp(a[i], i));

  }

  st.clear();



  for (int i = 2 * n - 1; i >= 0; --i) {

    while (st.size()) {
      if (st.back().x >= a[i]) st.pop_back(); else {
        nxt[i] = st.back().y;
        break;
      }
    }

    st.pb(mp(a[i], i));

  }



  build(0, n - 1);

  for (int i = 0; i < n; ++i) {
    auto now = tr.get(0, 0, 2 * n, i, i + n - 1);

   // for (int j = i; j < i + n; ++j) cout << tr.get(0, 0, 2 * n, j, j) << ' ';
  //  cout << endl;



    if (now < best) {
      best = now;
      best_pos = i;
    }

    if (a[i] == 0) continue;
  

    int nx = nxt[i];
    int pr = prv[i + n];

    tr.add(0, 0, 2 * n, i + 1, nx - 1, -1);
    tr.add(0, 0, 2 * n, pr + 1, i + n - 1, 1);

    tr.add(0, 0, 2 * n, i + n, i+ n, tr.get(0, 0, 2 * n, pr, pr) + 1);

  }


  cout << best + 1 << ' ' << best_pos;

}