#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pi, int> ppi;
typedef vector<ppi> vppi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

const int N = 1000010;
const int mida = 1000000;
const ll INF = 3e9;

ll T[4*N];
ll lazy[4*N];

void actu(int node, bool t) {
  T[node] += lazy[node];
  if (!t) {
    lazy[2*node] += lazy[node];
    lazy[2*node+1] += lazy[node];
  }
  lazy[node] = 0;
}

void add(int node, int a, int b, int x, int y, ll val) {
  actu(node, a == b);
  if (b < x or y < a) return;
  if (x <= a and b <= y) {
    T[node] += val;
    if (a != b) {
      lazy[2*node] += val;
      lazy[2*node+1] += val;
    }
    return;
  }
  int mid = (a+b)/2;
  add(2*node, a, mid, x, y, val);
  add(2*node+1, mid+1, b, x,y , val);
  T[node] = max(T[2*node], T[2*node+1]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, p;
  cin >> n>> m >>p;
  vpi A(n), B(m);
  for (int i = 0; i < n; ++i) cin >> A[i].first >> A[i].second;
  for (int i = 0; i < m; ++i) cin >> B[i].first >> B[i].second;
  sort(A.begin(), A.end());
  map<int, int> M;
  for (auto a : B) {
    --a.first;
    if (M.count(a.first) == 0) M[a.first] = a.second;
    else M[a.first] = min(M[a.first], a.second);
  }
  for (auto it : M) {
    add(1, 0, mida, it.first, it.first, INF -it.second);
  }
  vppi V(p);
  for (int i = 0; i < p; ++i) {
    cin >> V[i].first.first >> V[i].first.second >> V[i].second;
  }
  sort(V.begin(), V.end());
  int ind = 0;
  ll res = -INF;
  for (auto a : A) {
    while (ind < p and V[ind].first.first < a.first) {
      add(1, 0 , mida, V[ind].first.second, mida, V[ind].second);
      ++ind;
    }
    res = max(res, T[1] - a.second);
  }
  cout <<res-INF << '\n';

}