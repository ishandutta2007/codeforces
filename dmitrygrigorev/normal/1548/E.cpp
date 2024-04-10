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

vector<int> rmq;
const int INF = 1e9;

void build(int i, int l, int r, vector<int> &v) {

  if (r - l == 1) {
    rmq[i] = v[l];
    return;
  }

  int mid = (l+r)/2;
  build(2*i+1, l, mid, v);
  build(2*i+2, mid, r, v);

  rmq[i] = max(rmq[2*i+1], rmq[2*i+2]);

}

int get(int i, int l, int r, int l1, int r1) {

  if (l1 >= r1) return -INF;
  if (l == l1 && r == r1) return rmq[i];

  int mid = (l+r)/2;
  return max(get(2*i+1, l, mid, l1, min(r1, mid)), get(2*i+2, mid, r, max(l1, mid), r1));

} 

vector<int> calc(vector<int> a) {

  vector<pair<int, int> > sa;
  int n = a.size();

  rmq.assign(4*n, -INF);
  build(0, 0, n, a);

  for (int i = 0; i < n; ++i) sa.pb(mp(a[i], i));
  sort(all(sa));
  
  vector<int> rel_val(n);
  for (int i = 0; i < n; ++i) rel_val[sa[i].y] = i;

  vector<int> ans(n, INF);
  vector<pair<int, int> > st;

  for (int i = 0; i < n; ++i) {
    while (st.size() && st.back().x > rel_val[i]) st.pop_back();
    //per(st, i, rel_val[i]);
    if (st.size()) ans[i] = min(ans[i], get(0, 0, n, st.back().y + 1, i + 1));
    st.pb(mp(rel_val[i], i));
  }

  st.clear();

  for (int i = n - 1; i >= 0; --i) {
    while (st.size() && st.back().x > rel_val[i]) st.pop_back();
    if (st.size()) ans[i] = min(ans[i], get(0, 0, n, i, st.back().y));
    st.pb(mp(rel_val[i], i));
  }

  return ans;
  

}

struct Vertex{int l; int r; int pr; int sz; int value;};
vector<Vertex> decart;
pair<int, int> SP = make_pair(-1, -1);

void update(int vertex){
    if (vertex == -1) return;
    int sz = 1;
    if (decart[vertex].l != -1){
        sz += decart[decart[vertex].l].sz;
    }
    if (decart[vertex].r != -1){
        sz += decart[decart[vertex].r].sz;
    }
    decart[vertex].sz = sz;
}


pair<int, int> split(int father, int number){
    if (father == -1) return SP;
    int l = 1;
    if (decart[father].l != -1){
        l += decart[decart[father].l].sz;
    }
    if (l <= number){
        pair<int, int> p = split(decart[father].r, number - l);
        decart[father].r = p.first;
        p.first = father;
        update(father);
        return p;
    }
    pair<int, int> p = split(decart[father].l, number);
    decart[father].l = p.second;
    p.second = father;
    update(father);
    return p;
}

int merg(int first, int second){
    if (first == -1) return second;
    if (second == -1) return first;
    if (decart[first].pr >= decart[second].pr){
        int v = merg(decart[first].r, second);
        decart[first].r = v;
        update(first);
        return first;
    }
    int v = merg(first, decart[second].l);
    decart[second].l = v;
    update(second);
    return second;
}

int get_left(int base, int number){
    if (base == -1) return 0;
    int lb = 1;
    if (decart[base].l != -1) lb += decart[decart[base].l].sz;
    if (decart[base].value < number){
        return lb + get_left(decart[base].r, number);
    }
    return get_left(decart[base].l, number);
}

int base = -1;

void insert(int x) {
  int t = get_left(base, x);
  auto p = split(base, t);
  decart.pb({-1, -1, rand()%30000, 1, x});
  base = merg(p.x, decart.size() - 1);
  base = merg(base, p.y);
}

void erase(int x) {

  int t = get_left(base, x);

  auto p = split(base, t);
  auto q = split(p.y, 1);

  base = merg(p.x, q.y);

}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, m, x;
  cin >> n >> m >> x;

  vector<int> a(n);
  vector<int> b(m);

  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;

  vector<int> na = calc(a);
  vector<int> nb = calc(b);

  //per(na);
  //per(nb);

  ///////////////// a + b <= x
  ///////////////// a + nb > x
  ///////////////// na + b > x

  vector<pair<int, int> > va, vb;
  for (int i = 0; i < n; ++i) va.pb(mp(a[i], na[i]));
  for (int i = 0; i < m; ++i) vb.pb(mp(b[i], nb[i]));

  sort(all(va), greater<pair<int, int> >());
  sort(all(vb));

  int u = 0;
  ll ans = 0;

  multiset<pair<int, int> > sorted_nb;
  for (int i = 0; i < n; ++i) {

    while (u < vb.size() && vb[u].x + va[i].x <= x) {
      sorted_nb.insert(mp(vb[u].y, vb[u].x));
      insert(vb[u].x);
      u++;
    }

    while (sorted_nb.size()) {
      auto p = (*sorted_nb.begin());
      if (p.x + va[i].x <= x) {
        erase(p.y);
        sorted_nb.erase(sorted_nb.begin());
      }
      else break;
    }

    int S = 0;
    if (base != -1) S = decart[base].sz;

    ans += S - get_left(base, x + 1 - va[i].y);
  }

  cout << ans;

}