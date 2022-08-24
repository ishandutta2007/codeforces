#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

struct Matrix {
  int a[2][2];

 // Matrix() { a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0; }
};

Matrix mult(Matrix a, Matrix b) {
  Matrix c;
  c.a[0][0] = c.a[0][1] = c.a[1][0] = c.a[1][1] = 0;
 //  for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) c.a[i][j] = 0;

  add(c.a[0][0], mult(a.a[0][0], b.a[0][0]));
  add(c.a[0][1], mult(a.a[0][0], b.a[0][1]));

  add(c.a[0][0], mult(a.a[0][1], b.a[1][0]));
  add(c.a[0][1], mult(a.a[0][1], b.a[1][1]));

  add(c.a[1][0], mult(a.a[1][0], b.a[0][0]));
  add(c.a[1][1], mult(a.a[1][0], b.a[0][1]));

  add(c.a[1][0], mult(a.a[1][1], b.a[1][0]));
  add(c.a[1][1], mult(a.a[1][1], b.a[1][1]));

/*
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        add(c.a[i][k], mult(a.a[i][j], b.a[j][k]));
      }
    }
  }
*/

  return c;
}

Matrix add(Matrix a, Matrix b) {
  Matrix c;
 // for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) c.a[i][j] = 0;
  c.a[0][0] = c.a[0][1] = c.a[1][0] = c.a[1][1] = 0;
 
  add(c.a[0][0], a.a[0][0]);
  add(c.a[0][0], b.a[0][0]);

  add(c.a[0][1], a.a[0][1]);
  add(c.a[0][1], b.a[0][1]);

  add(c.a[1][0], a.a[1][0]);
  add(c.a[1][0], b.a[1][0]);

  add(c.a[1][1], a.a[1][1]);
  add(c.a[1][1], b.a[1][1]);
 
/*
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      add(c.a[i][j], a.a[i][j]);
      add(c.a[i][j], b.a[i][j]);
    }
  }
*/
  return c;
}

const int M = 5000007;
Matrix res2[M];
bool was2[M];

Matrix bp2(ll y) {
  if (y < M && was2[y]) return res2[y];
  if (y == 0) {
    Matrix ans;
    ans.a[0][0] = 1;
    ans.a[0][1] = 0;
    ans.a[1][0] = 0;
    ans.a[1][1] = 1;

    if (y < M) was2[y] = true, res2[y] = ans;

    return ans;
  }
  if (y == 1) {
    Matrix ans;
    ans.a[0][0] = 0;
    ans.a[0][1] = 1;
    ans.a[1][0] = 1;
    ans.a[1][1] = mod - 1;

    if (y < M) was2[y] = true, res2[y] = ans;

    return ans;
  }

  if (y % 2 == 1) {
    auto ans = mult(bp2(y - 1), bp2(1));
    if (y < M) was2[y] = true, res2[y] = ans;
    return ans;
  }

  Matrix w = bp2(y/2);
  auto ans = mult(w, w);

  if (y < M) was2[y] = true, res2[y] = ans;
  return ans;

}
const int N = 5000007;
Matrix res[N];
bool was[N];

Matrix bp(ll y) {
  if (y < 0) {
    return bp2(-y);
  }
  if (y < N) if (was[y]) return res[y];
  if (y == 0) {
    Matrix ans;
    ans.a[0][0] = 1;
    ans.a[0][1] = 0;
    ans.a[1][0] = 0;
    ans.a[1][1] = 1;

    if (y < N) was[y] = true, res[y] = ans;

    return ans;
  }
  if (y == 1) {
    Matrix ans;
    ans.a[0][0] = 1;
    ans.a[0][1] = 1;
    ans.a[1][0] = 1;
    ans.a[1][1] = 0;

    if (y < N) was[y] = true, res[y] = ans;

    return ans;
  }

  if (y % 2 == 1) {
    auto ans = mult(bp(y - 1), bp(1));
    if (y < N) was[y] = true, res[y] = ans;
    return ans;
  }

  Matrix w = bp(y/2);
  auto ans = mult(w, w);

  if (y < N) was[y] = true, res[y] = ans;
  return ans;

}

Matrix multiply(Matrix a, int t) {
  Matrix c = a;

  c.a[0][0] = mult(c.a[0][0], t);
  c.a[0][1] = mult(c.a[0][1], t);
  c.a[1][0] = mult(c.a[1][0], t);
  c.a[1][1] = mult(c.a[1][1], t);

/*
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      c.a[i][j] = mult(c.a[i][j], t);
    }
  } */
  return c;
}

struct Subvertex {
  Matrix m;
  ll push_sum;
  ll push_ass;
  ll min;
  ll max;
};

struct Vertex {
  
  Subvertex s[2];
  Matrix total;

};

vector<Vertex> rmq;
vector<int> a;
vector<int> b;

void perform_assignment(int j, int a, int t, int l) {
  if (t == -1) return;
  Matrix tt = bp(t);
  rmq[j].s[a].m = multiply(tt, l);
  rmq[j].s[a].push_sum = 0;
  rmq[j].s[a].push_ass = t;
  rmq[j].s[a].min = t;
  rmq[j].s[a].max = t;
  rmq[j].total = mult(rmq[j].s[1 - a].m, tt);
}

void perform_add(int j, int a, int t) {
  if (t == 0) {
    return;
  }
  Matrix tt = bp(t);
  rmq[j].s[a].m = mult(rmq[j].s[a].m, tt);

  rmq[j].s[a].push_sum += t;
  rmq[j].s[a].min += t;
  rmq[j].s[a].max += t;
  rmq[j].total = mult(rmq[j].total, tt);
}

void push(int i, int l, int r) {

  if (r - l <= 1) return;
  int mid = (l+r)/2;

  vector<int> lens = {mid - l, r - mid};
  int start = 2*i+1;

  for (int j = 2 * i + 1; j <= 2 * i + 2; ++j) {
    for (int a = 0; a < 2; ++a) {
      perform_assignment(j, a, rmq[i].s[a].push_ass, lens[j - (2 * i + 1)]);
      perform_add(j, a, rmq[i].s[a].push_sum);
    }
  }

  for (int j = 0; j < 2; ++j) {
    rmq[i].s[j].push_ass = -1;
    rmq[i].s[j].push_sum = 0;
  }

}

void recalc(int i) {

  for (int j = 0; j < 2; ++j) {
    rmq[i].s[j].m = add(rmq[2*i+1].s[j].m, rmq[2*i+2].s[j].m);
    rmq[i].s[j].push_ass = -1;
    rmq[i].s[j].push_sum = 0;
    rmq[i].s[j].min = min(rmq[2*i+1].s[j].min, rmq[2*i+2].s[j].min);
    rmq[i].s[j].max = max(rmq[2*i+1].s[j].max, rmq[2*i+2].s[j].max);
  }

  rmq[i].total = add(rmq[2*i+1].total, rmq[2*i+2].total);
}

void build(int i, int l, int r) {
  if (r - l == 1) {
    rmq[i].s[0].m = bp(a[l]);
    rmq[i].s[1].m = bp(b[l]);
    rmq[i].total = bp(a[l] + b[l]);
   // per(rmq[i].total.a[0][1]);
    for (int j = 0; j < 2; ++j) {
      int W = a[l];
      if (j == 1) W = b[l];

      rmq[i].s[j].push_sum = 0, rmq[i].s[j].push_ass = -1;
      rmq[i].s[j].min = W, rmq[i].s[j].max = W;
    }
    return;
  }

  int mid = (l+r)/2;
  build(2*i+1, l, mid);
  build(2*i+2, mid, r);

  recalc(i);

}

void min_query(int i, int l, int r, int l1, int r1, int t, int val) {
  push(i, l, r);
  if (l1 >= r1) return;
  if (l == l1 && r == r1) {
    if (rmq[i].s[t].min >= val) {
      perform_assignment(i, t, val, r - l);
      return;
    }
    if (rmq[i].s[t].max <= val) {
      return;
    }
  }

  int mid = (l+r)/2;
  min_query(2*i+1, l, mid, l1, min(r1, mid), t, val);
  min_query(2*i+2, mid, r, max(l1, mid), r1, t, val);
  recalc(i);
}

void max_query(int i, int l, int r, int l1, int r1, int t, int val) {
  push(i, l, r);
  if (l1 >= r1) return;
  if (l == l1 && r == r1) {
    if (rmq[i].s[t].max <= val) {
      perform_assignment(i, t, val, r - l);
      return;
    }
    if (rmq[i].s[t].min >= val) {
      return;
    }
  }

  int mid = (l+r)/2;
  max_query(2*i+1, l, mid, l1, min(r1, mid), t, val);
  max_query(2*i+2, mid, r, max(l1, mid), r1, t, val);
  recalc(i);
}

void add_query(int i, int l, int r, int l1, int r1, int t, int val) {
  push(i, l, r);
  if (l1 >= r1) return;
  if (l == l1 && r == r1) {
    perform_add(i, t, val);
    return;
  }

  int mid = (l+r)/2;
  add_query(2*i+1, l, mid, l1, min(r1, mid), t, val);
  add_query(2*i+2, mid, r, max(l1, mid), r1, t, val);
  recalc(i);
}

int get(int i, int l, int r, int l1, int r1) {
  push(i, l, r);
  if (l1 >= r1) return 0;
  if (l == l1 && r == r1) {
    return rmq[i].total.a[0][1];
  }

  int mid = (l+r)/2;
  int A = get(2*i+1, l, mid, l1, min(r1, mid));
  int B = get(2*i+2, mid, r, max(l1, mid), r1);
  add(A, B);
  return A;
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

  a.assign(n, -1);
  b.assign(n, -1);

  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;

  rmq.assign(4*n, {});
  build(0, 0, n);

  for (int i = 0; i < q; ++i) {
    int t;
    cin >> t;
    if (t == 1) {
      int k, l, r, x;
      cin >> k >> l >> r >> x;
      k--, l--, r--;
      min_query(0, 0, n, l, r + 1, k, x);
    }
    else if (t == 2) {
      int k, l, r, x;
      cin >> k >> l >> r >> x;
      k--, l--, r--;
      max_query(0, 0, n, l, r + 1, k, x);
    }
    else if (t == 3) {
      int k, l, r, x;
      cin >> k >> l >> r >> x;
      k--, l--, r--;
      add_query(0, 0, n, l, r + 1, k, x);
    }
    else {
      int l, r;
      cin >> l >> r;
      l--, r--;
      cout << get(0, 0, n, l, r + 1) << '\n';
    }
  }
  

}