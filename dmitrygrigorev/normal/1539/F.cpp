#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Vertex {
  int sum;
  int max_sum;
};

vector<Vertex> rmq;
int n;

void recalc(Vertex &a, Vertex b, Vertex c) {
  a.sum = b.sum + c.sum;
  a.max_sum = max(b.max_sum, b.sum + c.max_sum);
}

void build(int i, int l, int r) {
  if (r - l == 1) {
    rmq[i].max_sum = -1, rmq[i].sum = -1;
    return;
  }

  int mid = (l+r)/2;
  build(2*i+1, l, mid);
  build(2*i+2, mid, r);

  recalc(rmq[i], rmq[2*i+1], rmq[2*i+2]);
}

Vertex base;

void upd(int i, int l, int r, int index) {
  if (r - l == 1) {
    rmq[i].max_sum = 1, rmq[i].sum = 1;
    return;
  }

  int mid = (l+r)/2;
  if (index < mid) upd(2*i+1, l, mid, index);
  else upd(2*i+2, mid, r, index);

  recalc(rmq[i], rmq[2*i+1], rmq[2*i+2]);
}

void get(int i, int l, int r, int l1, int r1) {
  if (l1 >= r1) return;
  if (l == l1 && r == r1) {
    recalc(base, base, rmq[i]);
    return;
  }

  int mid = (l+r)/2;
  get(2*i+1, l, mid, l1, min(r1, mid));
  get(2*i+2, mid, r, max(l1, mid), r1);

}

vector<int> solve2(vector<int> v) {

  vector<pair<int, int> > elements;
  for (int i = 0; i < n; ++i) {
    elements.pb(mp(v[i], i));
  }

  sort(all(elements));
  vector<int> ans(n, 0);

  rmq.assign(4*n, {0, 0});
  build(0, 0, n);

  for (int i = n-1; i >= 0; --i) {
    int index = elements[i].y;
    base = {0, 0};

    get(0, 0, n, index + 1, n);
    ans[index] = base.max_sum;

    upd(0, 0, n, index);

  }

  return ans;

}

vector<int> solve(vector<int> v) {

  auto A = solve2(v);
  reverse(all(v));
  auto B = solve2(v);
  reverse(all(B));

  for (int i = 0; i < n; ++i) A[i] += B[i];
  return A;

}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;

  vector<int> v(n);
  for (auto &x : v) cin >> x;

  auto A = solve(v);
  for (auto &x : v) x *= -1;
  auto B = solve(v);

  for (int i = 0; i < n; ++i) cout << (max(A[i], B[i] - 1) + 1) / 2 << " ";

}