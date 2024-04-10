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

ll ge(ll v) {
  if (v < 0) return 0;
  return v * (v + 1) / 2;
}

ll sum(ll vl, ll vr) { 
  return ge(vr) - ge(vl - 1);
}

const int N = 207;
int dist[N][N];

int main(){
#ifdef LOCAL
  freopen("I_input.txt", "r", stdin);
  //freopen("I_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll k;
  int n;

  cin >> k >> n;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    dist[a + N/2][b + N/2] = -1;
  }

  dist[0+N/2][0+N/2] = 0;
  queue<pair<int, int> > q;
  q.push(mp(0, 0));

  while (q.size()) {
    auto W = q.front();
    q.pop();
    for (int a = -2; a <= 2; ++a) {
      for (int b = -2; b <= 2; ++b) {
        if (abs(a) + abs(b) != 3) continue;
        if (abs(a) == 3 || abs(b) == 3) continue;
        int x = W.x + a, y = W.y + b;
        if (x < -N/2 || x > N/2 || y < -N/2 || y > N/2) continue;
        if (mp(x, y) == mp(0, 0) || dist[x + N/2][y + N/2] != 0) continue;
        dist[x + N/2][y + N/2] = dist[W.x + N/2][W.y + N/2] + 1;
        q.push(mp(x, y));
      }
    }
  }


  vector<int> ans(40, 0);
  for (int i = -N/2; i <= N/2; ++i) {
    for (int j = -N/2; j <= N/2; ++j) {
      if ((dist[i + N/2][j + N/2] > 0 || mp(i, j) == mp(0, 0)) && dist[i + N/2][j + N/2] < 40) {
       // if (dist[i + N/2][j + N/2] == 1) per(i, j);
        ans[dist[i + N/2][j + N/2]]++;
      } 
    }
  }

 //per(ans);

  for (int i = 1; i < 40; ++i) add(ans[i], ans[i - 1]);
  if (ans[39] == ans[38]) {
    cout << ans[39];
    exit(0);
  }

  if (k < 40) cout << ans[k];
  else {
    int t = (k - 39) % mod;
    int progress = mult(28, mult(t, mult((t+1)%mod, (mod + 1) / 2)));
   // per(progress);
    add(progress, mult((ans[39] - ans[38]), t));
    add(progress, ans[39]);
    cout << progress;
  }



}