#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
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
  int f;
  int r;
};

vector<Vertex> snm;

int get(int v) {
  if (snm[v].f != v) snm[v].f = get(snm[v].f);
  return snm[v].f;
}

void unite(int u, int v) {

  if (snm[u].r > snm[v].r) swap(u, v);
  snm[u].f = v;
  if (snm[u].r == snm[v].r) snm[v].r++;
}

const int N = 1000007;

int pos[N];
int cmp[N];
vector<int> divisors[N];

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, q;
  cin >> n >> q;

  for (int i = 0; i < n; ++i) snm.pb({i, 1});

  for (int i = 0; i < N; ++i) {
    pos[i] = -1;
    cmp[i] = -1;
  }
  vector<int> v(n);

  for (auto &x : v) cin >> x;
  for (int i = 0; i < n; ++i) pos[v[i]] = i;

  for (int i = 2; i < N; ++i) {

    if (divisors[i].size() == 0) {
      for (int j = i; j < N; j += i) divisors[j].pb(i);
    } 

    int last = -1;
    for (int j = i; j < N; j += i) {
      if (pos[j] != -1 && last != -1) {
        int A = get(pos[j]), B = get(last);
        if (A!=B) unite(A, B);
      }
      if (pos[j] != -1) {
        last = pos[j];
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    int G = get(i);
    for (auto x : divisors[v[i]]) {
      cmp[x] = G;
    }
  }

  set<pair<int, int> > united;
  vector<bool> used(n, false);


  for (int i = 0; i < n; ++i) {
    int A = v[i], B = v[i] + 1;

    vector<int> allc;

    allc.pb(get(i));
    for (auto x : divisors[B]) {
      if (cmp[x] != -1) {
        allc.pb(cmp[x]);
      }
    }

    vector<int> T;
    for (auto x : allc) if (!used[x]) {
      used[x] = true;
      T.pb(x);
    }

    for (auto x : allc) used[x] = false;

    for (auto x : T) for (auto y : T) if (x < y) united.insert(mp(x, y));
  }

  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    x--, y--;

    if (get(x) == get(y)) {
      cout << "0\n";
      continue;
    }
    
    int A = get(x), B = get(y);
    if (A>B) swap(A, B);
    if (united.count(mp(A, B))) cout << "1\n";
    else cout << "2\n"; 

  }

}