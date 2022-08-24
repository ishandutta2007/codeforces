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

struct Vertex {
  int ans[4][4];
};

vector<Vertex> rmq;

void recalc(Vertex &a, Vertex &b, Vertex &c) {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      a.ans[i][j] = 1e9;
    }
  }

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      for (int k = 0; k < 4; ++k) {
        a.ans[i][k] = min(a.ans[i][k], b.ans[i][j] + c.ans[j][k]);
      }
    }
  }

}

void build(int i, int l, int r, string& s) {
  if (r - l == 1) {
    for (int e = 0; e < 4; ++e) {
      for (int f = 0; f < 4; ++f) {
        if (e <= f) rmq[i].ans[e][f] = 1;
        else rmq[i].ans[e][f] = 1e9;
      }
      rmq[i].ans[e][e] = 0;
    }
    if (s[l] == 'a') {
      rmq[i].ans[0][0] = 1;
      rmq[i].ans[0][1] = 0;
    }
    else if (s[l] == 'b') {
      rmq[i].ans[1][1] = 1;
      rmq[i].ans[1][2] = 0;
    }
    else {
      rmq[i].ans[2][2] = 1;
      rmq[i].ans[2][3] = 0;
    }
    return;
  }

  int mid = (l+r)/2;
  build(2*i+1, l, mid, s);
  build(2*i+2, mid, r, s);

  recalc(rmq[i], rmq[2*i+1], rmq[2*i+2]);
}

void upd(int i, int l, int r, int index, char c) {
  if (r - l == 1) {
    for (int e = 0; e < 4; ++e) {
      for (int f = 0; f < 4; ++f) {
        if (e <= f) rmq[i].ans[e][f] = 1;
        else rmq[i].ans[e][f] = 1e9;
      }
      rmq[i].ans[e][e] = 0;
    }
    if (c == 'a') {
      rmq[i].ans[0][0] = 1;
      rmq[i].ans[0][1] = 0;
    }
    else if (c == 'b') {
      rmq[i].ans[1][1] = 1;
      rmq[i].ans[1][2] = 0;
    }
    else {
      rmq[i].ans[2][2] = 1;
      rmq[i].ans[2][3] = 0;
    }
    return;
  }

  int mid = (l+r)/2;
  if (index < mid) upd(2*i+1, l, mid, index, c);
  else upd(2*i+2, mid, r, index, c);

  recalc(rmq[i], rmq[2*i+1], rmq[2*i+2]);
}

int main(){
#ifdef LOCAL
  freopen("E_input.txt", "r", stdin);
  //freopen("E_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  cin >> n >> q;

  string s;
  cin >> s;

  rmq.resize(4*n);
  build(0, 0, n, s);

  for (int i = 0; i < q; ++i) {
    int a;
    char c;
    cin >> a >> c;

    upd(0, 0, n, a - 1, c);
    cout << min({rmq[0].ans[0][0], rmq[0].ans[0][1], rmq[0].ans[0][2]}) << '\n';

  }

}