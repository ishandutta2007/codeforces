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

const int mod = 998244353;

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

struct Vertex{int l; int r; int pr; int sz; int value; int sum;};
vector<Vertex> decart;
pair<int, int> SP = make_pair(-1, -1);
void update(int vertex){
    if (vertex == -1) return;
    int sz = 1;
    int S = decart[vertex].value;
    if (decart[vertex].l != -1){
        sz += decart[decart[vertex].l].sz;
        S += decart[decart[vertex].l].sum;
    }
    if (decart[vertex].r != -1){
        sz += decart[decart[vertex].r].sz;
        S += decart[decart[vertex].r].sum;
    }
    decart[vertex].sz = sz;
    decart[vertex].sum = S;
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

int gl(int base) {
  int L = decart[base].l;
  if (L != -1) return gl(L);
  return decart[base].value;
}

void dlt(int& base, int ticks) {

  while (ticks > 0) {
    
    auto p = split(base, 1);

  //(ticks);

    if (decart[p.x].value <= ticks) {
      ticks -= decart[p.x].value;
      base = p.y;
    }
    else {
      //if (p.y != -1) per("??? ", decart[p.y].sum);
      decart[p.x].value -= ticks;
      decart[p.x].sum -= ticks;

      base = merg(p.x, p.y);
      return;

    }

  }

}

int gg(int base, int sum) {

  if (base == -1) return 0;

  int L = decart[base].l, R = decart[base].r;
  int s1 = 0, s2 = decart[base].value, s3 = 0;

  if (L != -1) s1 = decart[L].sum;
  if (R != -1) s3 = decart[R].sum;

  if (s1 + s2 <= sum) {
    int T = 1;
    if (L != -1) T += decart[L].sz;
    return T + gg(R, sum - s1 - s2);
  }

  else if (s1 <= sum) {
    int T = 0;
    if (L != -1) T += decart[L].sz;
    return T;
  }

  return gg(L, sum);

}

int process(int &base, int x) {

  int num = gg(base, x);
  auto p = split(base, num);

  if (p.x != -1 && decart[p.x].sum == x) {
    auto q = split(p.y, 1);
    if (decart[q.x].value != 1) {
      decart[q.x].value--;
      decart[q.x].sum--;
      q.y = merg(q.x, q.y);
    }
    base = merg(p.x, q.y);
    return 0;
  }

  auto q = split(p.y, 1);
  base = p.x;

  int D = x;
  if (p.x != -1) D -= decart[p.x].sum;

  decart.pb({-1, -1, rand()%30000, 1, D, D});
  base = merg(base, decart.size() - 1);

  int rem = decart[q.x].sum - D - 1;
  if (rem > 0) {
    decart.pb({-1, -1, rand()%30000, 1, rem, rem});
    base = merg(base, decart.size() - 1);
  }

  base = merg(base, q.y);
  return 1;

}

const int N = 400007;
int fact[N];
int rv[N];

int C(int n, int k) {
  return mult(fact[n], mult(rv[k], rv[n-k]));
}

void solve() {

  int n, m;
  cin >> n >> m;

  vector<pair<int, int> > v(m);
  for (auto &x : v) {
    cin >> x.x >> x.y;
  }

  reverse(all(v));

  decart.clear();
  int base = -1;

  decart.pb({-1, -1, rand()%30000, 1, n, n});
  base = merg(base, decart.size() - 1);

  int last = n + 1;
  int tot = 0;

  for (int i = 0; i < v.size(); ++i) {

    int ticks = last - v[i].x - 1;
    dlt(base, ticks);

   // per(decart[base].sum);

    int smaller = v[i].x - v[i].y;
    tot += process(base, smaller);

    last = v[i].x;

  }

  int ans = C(2*n - 1 - tot, n);

  cout << ans << '\n';



}


int main(){
#ifdef LOCAL
  freopen("C_input.txt", "r", stdin);
  //freopen("C_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  fact[0] = 1;
  for (int i = 1; i < N; ++i) fact[i] = mult(i, fact[i - 1]);
  for (int i = 0; i < N; ++i) rv[i] = bp(fact[i], mod - 2);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}