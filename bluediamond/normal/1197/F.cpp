#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M=998244353;
int add(int a,int b){
  a+=b;
  if(a>=M)return a-M;
  if(a<0)return a+M;
  return a;
}
int mul(int a,int b){
  return a*(ll)b%M;
}
int add(int a,int b,int c){
  return add(add(a,b),c);
}
int mul(int a,int b,int c){
  return mul(mul(a,b),c);
}
int add(int a,int b,int c,int d){
  return add(add(a,b,c),d);
}
int mul(int a,int b,int c,int d){
  return mul(mul(a,b,c),d);
}
int add(int a,int b,int c,int d,int e){
  return add(add(a,b,c,d),e);
}
int mul(int a,int b,int c,int d,int e){
  return mul(mul(a,b,c,d),e);
}
int add(int a,int b,int c,int d,int e,int f){
  return add(add(a,b,c,d,e),f);
}
int mul(int a,int b,int c,int d,int e,int f){
  return mul(mul(a,b,c,d,e),f);
}
int add(int a,int b,int c,int d,int e,int f,int g){
  return add(add(a,b,c,d,e,f),g);
}
int mul(int a,int b,int c,int d,int e,int f,int g){
  return mul(mul(a,b,c,d,e,f),g);
}
int add(int a,int b,int c,int d,int e,int f,int g,int h){
  return add(add(a,b,c,d,e,f,g),h);
}
int mul(int a,int b,int c,int d,int e,int f,int g,int h){
  return mul(mul(a,b,c,d,e,f,g),h);
}
int pw(int a,int b){
  int r=1;
  while(b){
    if(b&1)r=mul(r,a);
    a=mul(a,a);
    b/=2;
  }
  return r;
}
int dv(int a,int b){
  return mul(a,pw(b,M-2));
}
void addup(int &a,int b){
  a=add(a,b);
}
void mulup(int &a,int b){
  a=mul(a,b);
}
void dvup(int &a,int b){
  a=dv(a,b);
}

struct modMatrix {
  int n;
  int m;
  int mod;
  vector<vector<int>> a;

  void init(int _n, int _m, int _mod) {
    n = _n;
    m = _m;
    mod = _mod;
    a.resize(n);
    for (int i = 0; i < n; i++) {
      a[i].resize(m, 0);
    }
  }
  modMatrix operator * (modMatrix b) {
    if (mod != b.mod) {
      cout << "error the mods do not correspond (when wanting to multiply)\n";
      exit(0);
    }
    if (m != b.n) {
      cout << "error on (mod) matrix sizes (when wanting to multiply)\n";
      exit(0);
    }
    modMatrix c;
    c.init(n, m, mod);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < m; k++) {
          c.a[i][j] = (c.a[i][j] + (long long) a[i][k] * b.a[k][j]) % mod;
        }
      }
    }
    return c;
  }
  modMatrix operator ^ (long long p) {
    if (n != m) {
      cout << "error on (mod) matrix size (when wanting to rise to the power)\n";
      exit(0);
    }
    modMatrix c, cur;
    c.init(n, m, mod);
    cur.init(n, m, mod);
    cur.a = a;
    for (int i = 0; i < n; i++) {
      c.a[i][i] = 1;
    }
    while (p) {
      if (p & 1) {
        c = c * cur;
      }
      cur = cur * cur;
      p /= 2;
    }
    return c;
  }
};


int codif(int a, int b, int c) {
  assert(0 <= a && a < 4);
  assert(0 <= b && b < 4);
  assert(0 <= c && c < 4);
  return 16 * a + 4 * b + c;
}

const int N = 1000 + 7;
int n, m, len[N];
int f[3][3];
vector<pair<int, int>> what[N];
vector<modMatrix> given_color;
modMatrix all_colors;
vector<modMatrix> pws;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  all_colors.init(64, 64, M);

  ////freopen ("___input___.txt", "r", stdin);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> len[i];
  }

  cin >> m;
  for (int i = 1; i <= m; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    assert(1 <= x && x <= n);
    assert(1 <= y && y <= len[x]);
    assert(1 <= c && c <= 3);
    what[x].push_back({y, c - 1});
  }
  for (int i = 1; i <= n; i++) {
    sort(what[i].begin(), what[i].end());
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> f[i][j];
    }
  }

  for (int color = 0; color < 3; color++) {
    modMatrix mtr;
    mtr.init(64, 64, M);
    for (int g0 = 0; g0 < 4; g0++) {
      for (int g1 = 0; g1 < 4; g1++) {
        for (int g2 = 0; g2 < 4; g2++) {
          set<int> s;
          if (f[color][0]) s.insert(g2);
          if (f[color][1]) s.insert(g1);
          if (f[color][2]) s.insert(g0);
          int g3 = 0;
          while (s.count(g3)) g3++;
          mtr.a[codif(g0, g1, g2)][codif(g1, g2, g3)]++;
          all_colors.a[codif(g0, g1, g2)][codif(g1, g2, g3)]++;
        }
      }
    }
    given_color.push_back(mtr);
  }
  {
    pws.push_back(all_colors);
    for (int k = 1; k <= 30; k++) {
      pws.push_back(pws.back() * pws.back());
    }
  }
  vector<int> ways(8, 0);
  ways[0] = 1;

  for (int index = 1; index <= n; index++) {
    int sz_what = (int) what[index].size();
    modMatrix current;
    current.init(1, 64, M);
    current.a[0][codif(3, 3, 3)]++;
    for (int i = 0; i <= sz_what; i++) {
      if (i < sz_what) {
        int last;
        if (i == 0) {
          last = 0;
        } else {
          last = what[index][i - 1].first;
        }
        int l = what[index][i].first - last - 1;
        for (int bit = 0; (1 << bit) <= l; bit++) {
          if (l & (1 << bit)) {
            current = current * pws[bit];
          }
        }
        current = current * given_color[what[index][i].second];
      } else {
        int last;
        if (i == 0) {
          last = 0;
        } else {
          last = what[index][i - 1].first;
        }
        int l = len[index] - last;
        for (int bit = 0; (1 << bit) <= l; bit++) {
          if (l & (1 << bit)) {
            current = current * pws[bit];
          }
        }
      }
    }
    vector<int> new_ways(8, 0);
    for (int g2 = 0; g2 < 4; g2++) {
      int sol = 0;
      for (int g0 = 0; g0 < 4; g0++) {
        for (int g1 = 0; g1 < 4; g1++) {
          addup(sol, current.a[0][codif(g0, g1, g2)]);
        }
      }
      for (int i = 0; i < 8; i++) {
        int j = i ^ g2;
        assert(0 <= j && j < 8);
        addup(new_ways[j], mul(sol, ways[i]));
      }
    }
    ways = new_ways;
  }
  cout << ways[0] << "\n";
}