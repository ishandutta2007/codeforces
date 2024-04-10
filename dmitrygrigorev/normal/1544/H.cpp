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
const int INF = 1e9;

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

vector<int> rmq;
int regime;

int n;

void state_rmq(int x) {
  
  regime = x;
  if (regime == 0) rmq.assign(4*n, INF);
  else rmq.assign(4*n, -INF);
}

void upd(int i, int l, int r, int index, int x) {
  if (r - l == 1) {
    rmq[i] = x;
    return;
  }

  int mid = (l+r)/2;
  if (index < mid) upd(2*i+1, l, mid, index, x);
  else upd(2*i+2, mid, r, index, x);

  if (regime == 0) rmq[i] = min(rmq[2*i+1], rmq[2*i+2]);
  else rmq[i] = max(rmq[2*i+1], rmq[2*i+2]);
}

int get(int i, int l, int r, int l1, int r1) {
  if (l1 >= r1) {
    if (regime == 0) return INF;
    return -INF;
  }

  if (l == l1 && r == r1) return rmq[i];
  int mid = (l+r)/2;

  int A = get(2*i+1, l, mid, l1, min(r1, mid)), B = get(2*i+2, mid, r, max(l1, mid), r1);
  if (regime == 0) return min(A, B);
  return max(A, B);

}

int go_down(int i, int l, int r, int x) {
  if (i == 0) {
    if (regime == 0 && rmq[0] > x) return -INF;
    if (regime == 1 && rmq[0] < x) return INF;
  }
  if (r - l == 1) return l;
  int mid = (l+r)/2;

  if (regime == 0) {

    if (rmq[2*i+2] <= x) return go_down(2*i+2, mid, r, x);
    return go_down(2*i+1, l, mid, x);

  }

  if (rmq[2*i+1] >= x) return go_down(2*i+1, l, mid, x);
  return go_down(2*i+2, mid, r, x);

}

int solve(vector<int> v, int place) {

  vector<int> dpl(n, INF), dpr(n, -INF);
  for (int i = 0; i < n; ++i) {
    if (place == 2 || (place == 1 && i == n - 1)) {
      dpl[i] = v[i];
      dpr[i] = v[i];
    }
  }

  int ans = 1;

  while (true) {
    int A = INF, B = -INF;
    for (auto x : dpl) A = min(A, x);
    for (auto x : dpr) B = max(B, x);
    if (A == INF && B == -INF) {
      return ans - 1;
    }
    ans++;

    vector<int> tpdl(n, INF);
    vector<int> tpdr(n, -INF);

    state_rmq(0);
    int between = ans + (place - 2) - 1;
   // cout << ans << " " << between << " " << place << endl;

    ////////////////////////////////// v[i] < x, take minimum
    for (int i = n - 1; i >= 0; --i) {
      tpdl[i] = get(0, 0, n, v[i], n);
      upd(0, 0, n, v[i], dpl[i]);
    }

    ////////////////////////////////// x < v[i], take_maximum

    state_rmq(1);
    for (int i = n - 1; i >= 0; --i) {
      tpdr[i] = get(0, 0, n, 0, v[i]);
      upd(0, 0, n, v[i], dpr[i]);
    }

    ///////////////////////////////// v[i] < f(x), minimize x

    state_rmq(1);
    for (int i = n - 1; i >= 0; --i) {
      tpdl[i] = min(tpdl[i], go_down(0, 0, n, v[i]));
      if (i + between < n) upd(0, 0, n, v[i + between], dpr[i + between]);
    }

    ///////////////////////////////// f(x) < v[i], maximize x

    state_rmq(0);
    for (int i = n - 1; i >= 0; --i) {
      tpdr[i] = max(tpdr[i], go_down(0, 0, n, v[i]));
      if (i + between < n) upd(0, 0, n, v[i + between], dpl[i + between]);
    }

    dpl = tpdl;
    dpr = tpdr;



  }

}

void solve() {

  cin >> n;

  vector<int> v(n);
  for (auto &x : v) {
    cin >> x;
    x--;
  }

  cout << max(solve(v, 1), solve(v, 2)) << '\n';

}

int main(){
#ifdef LOCAL
	freopen("M_input.txt", "r", stdin);
	//freopen("M_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}