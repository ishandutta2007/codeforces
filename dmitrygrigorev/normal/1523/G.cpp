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

const int MAXN = 20000000;
const int INF = 1e9;

struct InnerVertex {
  int l;
  int r;
  int mini;
};

InnerVertex allv[MAXN];
int ptr = 0;

vector<int> rmq;

struct Seg {
  int l;
  int r;
  int index;
};

bool cmp(Seg &a, Seg &b) {
  return (a.r - a.l > b.r - b.l);
}

void build(int i, int l, int r) {

  allv[ptr] = {-1, -1, INF};
  rmq[i] = ptr++;

  if (r - l == 1) return;
  int mid = (l+r) / 2;
  build(2*i+1, l, mid);
  build(2*i+2, mid, r);

}

int n, m;

void upd2(int w, int l, int r, int c2, int index) {

  allv[w].mini = min(allv[w].mini, index);
  if (r - l == 1) return;

  int mid = (l+r)/2;
  if (c2 < mid) {
    if (allv[w].l == -1) {
      allv[ptr] = {-1, -1, INF};
      allv[w].l = ptr++;
    }
    upd2(allv[w].l, l, mid, c2, index);
  }

  else {
    if (allv[w].r == -1) {
      allv[ptr] = {-1, -1, INF};
      allv[w].r = ptr++;
    }
    upd2(allv[w].r, mid, r, c2, index);
  }


}

void upd(int i, int l, int r, int c1, int c2, int index) {

  upd2(rmq[i], 0, n, c2, index);
  if (r - l == 1) {
    return;
  }

  int mid = (l+r)/2;
  if (c1 < mid) upd(2*i+1, l, mid, c1, c2, index);
  else upd(2*i+2, mid, r, c1, c2, index);

}

int get2(int w, int l, int r, int l1, int r1) {
  if (w == -1) return INF;
  if (l1 >= r1) return INF;
  if (l == l1 && r == r1) return allv[w].mini;

  int mid = (l+r)/2;
  return min(get2(allv[w].l, l, mid, l1, min(r1, mid)), get2(allv[w].r, mid, r, max(l1, mid), r1));

}

int get(int i, int l, int r, int l1, int r1, int a, int b) {
  if (l1 >= r1) return INF;
  if (l == l1 && r == r1) {
    return get2(rmq[i], 0, n, a, b + 1);
  }

  int mid = (l+r)/2;
  return min(get(2*i+1, l, mid, l1, min(r1, mid), a, b), get(2*i+2, mid, r, max(l1, mid), r1, a, b));
}

int restore_ans(vector<Seg> &vv, int l, int r) {

  if (l > r) return 0;

  int index = get(0, 0, n, l, r + 1, l, r);
  if (index == INF) return 0;

  int res = vv[index].r - vv[index].l + 1;

  res += restore_ans(vv, l, vv[index].l - 1);
  res += restore_ans(vv, vv[index].r + 1, r);

  return res;

}

int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> m;

  vector<Seg> v(m);

  for (int i = 0; i < m; ++i) {
    v[i].index = i;
    cin >> v[i].l >> v[i].r;
    v[i].l--, v[i].r--;
  }

  auto cv = v;

  sort(all(v), cmp);
  
  int u = 0;
  rmq.resize(4*n);

  build(0, 0, n);
  vector<int> ans;

  for (int i = n; i >= 1; --i) {
    while (u < m && v[u].r - v[u].l + 1 >= i) {
      upd(0, 0, n, v[u].l, v[u].r, v[u].index);
      u++;
    }

    ans.pb(restore_ans(cv, 0, n - 1));
  }

  reverse(all(ans));
  for (auto x : ans) cout << x << " ";



}