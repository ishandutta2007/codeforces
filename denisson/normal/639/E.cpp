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
ll p[222222];
ll t[222222];

vector<int> d;
ll T = 0;

bool can(db c) {
  vector<pair<ll, pair<db, db> > > q;
  ll sum = 0;

  int i = 0;
  while (i < n) {
    int j = i;
    while (j + 1 < n) {
      ll w1 = p[ d[j] ] * t[ d[j + 1] ];
      ll w2 = p[ d[j + 1] ] * t[ d[j] ];
      if (w1 != w2) break;
      ++j; 
    }

    ll cur_sum = 0;
    for (int s = i; s <= j; ++s) cur_sum += t[ d[s] ];

    for (int s = i; s <= j; ++s) {

      q.pb(mp( p[d[s]], mp(  p[d[s]] * (1 - c * (sum + cur_sum) / (db)T), p[d[s]] * (1 - c * (sum + t[d[s]]) / (db)T)  ) ));

    }

    sum += cur_sum;

    i = j + 1;
  }

/*
  for (int i = 0; i < n; ++i) {
    int v = d[i];
    sum += t[v];
    q.pb(mp( p[v], p[v] * (1 - c * sum / (db)T) ));
  }
*/

  sort(all(q));
  for (int i = 0; i + 1 < q.size(); ++i) {
   
    if (q[i].x < q[i + 1].x) {

      if (q[i].y.y > q[i + 1].y.x) return 0;

    }

  }
  return 1;
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  readArr(p, p + n);
  readArr(t, t + n);

  for (int i = 0; i < n; ++i) d.pb(i), T += t[i];

  sort(all(d), [](int a, int b) {
    ll w1 = p[a] * t[b];
    ll w2 = p[b] * t[a];
    if (w1 == w2) return p[a] < p[b];
    return w1 > w2;
  });

  db vl = 0, vr = 1;
  for (int it = 0; it < 35; ++it) {
    db vm = (vl + vr) / 2;
    if (can(vm)) vl = vm; else vr = vm;
  }

  cout.precision(10);
  cout << fixed << vl;

}