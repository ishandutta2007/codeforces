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
int a[33];

bool dp[2][62][61 * 30 + 7];
int pr[32][62][61 * 30 + 7];

int mat[66][66];

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);


  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];

  sort(a, a + n);

  int uk = 0;
  dp[0][0][0] = 1;

  for (int i = 0; i < n; ++i) {

    for (int was = 0; was <= 61; ++was) for (int w = 0; w <= was * 30; ++w) dp[uk ^ 1][was][w] = 0;

    for (int was = 0; was <= 61; ++was) for (int w = 0; w <= was * 30; ++w) if (dp[uk][was][w] != 0) {

      // per(i, was, w);

//      dp[uk ^ 1][was][w] = 1; pr[i + 1][was][w] = 1;
  

      if (w + a[i] >= was * (was + 1) / 2) {
        dp[uk][was + 1][w + a[i]] = 1;
        pr[i][was + 1][w + a[i]] = 1;

        dp[uk ^ 1][was + 1][w + a[i]] = 1;
        pr[i + 1][was + 1][w + a[i]] = 2;
      }

    }

    uk ^= 1; 
  }

  int ans = -1;

  for (int nodes = 1; nodes <= 61; ++nodes) {
    if (dp[uk][nodes][nodes * (nodes - 1) / 2]) {
      ans = nodes;
      break;
    }
  }

  if (ans == -1) {
    cout << "=("; exit(0);
  }

  cout << ans << endl;

  vector<int> t;


  int w1 = n, w2 = ans, w3 = ans * (ans - 1) / 2;

  while (t.size() < ans) {
    if (pr[w1][w2][w3] == 1) {

      t.pb(a[w1]);
      --w2;
      w3 -= a[w1];

    } else if (pr[w1][w2][w3] == 2) {

      --w1;
      t.pb(a[w1]);
      --w2;
      w3 -= a[w1];

    }
  }

  sort(all(t)); // reverse(all(t));

//  pper(t);
//  cout << t.size() << endl;

 // set<int> se;
//  for (int x : t) se.insert(x);

 //   cout << se.size() << endl;
/*
  int s = 0;
  for (int i = 0; i < t.size(); ++i) {
    s += t[i];
    assert(s >= i * (i + 1) / 2);
    per(s, i * (i + 1) / 2);
  }
  */

  vector<pair<int, int>> q;


  for (int i = 0; i < ans; ++i) {
    q.pb(mp( t[i], i ));
  }


  for (int i = ans - 1; i >= 0; --i) {

    sort(all(q));

  //  pper(q);

    int v = q.back().y;

    int dd = q.back().x;

  //  pper(q);


    for (int j = 0; j + 1 < q.size(); ++j) {

      if (j < dd) {

        mat[v][q[j].y] = 1;
       

     //   pper(j)

      } else {

       q[j].x--;

        mat[q[j].y][v] = 1;
      }     

    }

    q.pop_back();

  }


  for (int i = 0; i < ans; ++i) {
    for (int j = 0; j < ans; ++j) {
      cout << mat[i][j];
    }
    cout << "\n";
  }

}