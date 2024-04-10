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


int n, m;
ll a[100007];
vector<int> t[100007];
ll sum[100007];

vector<int> tg[100007];
ll sumg[100007];

int now[100007];
int nx[100007];
int pr[100007];

vector<int> res[100007];
vector<int> dd[100007];

bool chk(int* a, int vl, int vr) {
  if (vl > vr) return 1;
  int now = a[vr];
  if (vl) now -= a[vl - 1];
  return now == vr - vl + 1;
}

void solve() {
  cin >> n >> m;

  readArr(a, a + n);
  sort(a, a + n);
  reverse(a, a + n);

  vector<int> ord;

  for (int i = 0; i < m; ++i) {
    res[i].clear();
    ord.pb(i);
    int sz;
    cin >> sz;
    t[i].resize(sz);
    readArr(all(t[i]));
    sum[i] = 0;
    for (int x : t[i]) sum[i] += x;
  }
  
  sort(all(ord), [](int w1, int w2) {
    return sum[w1] * (ll)t[w2].size() > sum[w2] * (ll)t[w1].size();
  });

  for (int i = 0;i  < m; ++i) {
    tg[i] = t[ord[i]];
    sumg[i] = sum[ord[i]];
  }

  for (int i = 0;i  < m; ++i) {
    t[i] = tg[i];
    sum[i] = sumg[i];
  }

  pr[0] = 0;
  for (int i = 0; i < m; ++i) {
    now[i] = a[i] * t[i].size() >= sum[i];
    if (i > 0) pr[i] = a[i - 1] * t[i].size() >= sum[i];
    nx[i] = a[i + 1] * t[i].size() >= sum[i];

    if (i) {
      now[i] += now[i - 1];
      pr[i] += pr[i - 1];
      nx[i] += nx[i - 1];
    }
  }


  for (int i = 0; i < m; ++i) {

    for (int j = 0; j < t[i].size(); ++j) {
      ll w1 = sum[i] - t[i][j];
      ll w2 = (int)t[i].size() - 1;

      ll p1 = sum[i];
      ll p2 = t[i].size();

     // per(w1, w2, p1, p2);

      if (w1 * p2 <= w2 * p1) {

        int vl = i, vr = m;
        while (vl + 1 < vr) {
          int vm = (vl + vr) >> 1;
          if (w1 * (ll)t[vm].size() < sum[vm] * w2) vl = vm; else vr = vm;
        }

        res[i].pb(chk(now, 0, i - 1) && chk(now, vr, m - 1) && chk(pr, i + 1, vr - 1) && a[vl] * w2 >= w1);


      } else {

       // pper("ASDSADSAD");
        int vl = -1, vr = i;
        while (vl + 1 < vr) {
          int vm = (vl + vr) >> 1;
        //  per("====", t[vm].size(), sum[vm], w1, w2);
          if (w1 * (ll)t[vm].size() <= sum[vm] * w2) vl = vm; else vr = vm;
        }

       // per(vl, vr);
       // pper(chk(now, 0, vl))

        res[i].pb(chk(now, 0, vl) && chk(now, i + 1, m - 1) && chk(nx, vl + 1, i - 1) && a[vr] * w2 >= w1);


      }

    }

  }

 // pper(ord);

 // pper(ord);

  for (int i = 0; i < ord.size(); ++i) {
    dd[ord[i]] = res[i];
  }

  for (int i = 0; i < m; ++i) for (int y : dd[i]) cout << y;

  cout << "\n";


}


int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

}