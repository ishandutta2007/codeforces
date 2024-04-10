#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef int llint;
typedef vector<llint> vi;
typedef vector<vi> vvi;
typedef pair<llint, llint> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

const int INF = 1e9+10;
vi T;
void add(int node, int a, int b, int x, int val) {
  if (b < x or x < a)  return;
  if (a == b) {
    T[node] = val;
    return;
  }
  add(2*node, a, (a+b)/2, x, val);
  add(2*node+1, 1+(a+b)/2, b, x, val);
  T[node] = min(T[2*node],T[2*node+1]);
}

int que(int node, int a, int b, int x, int y) {
  if (b < x or y < a) return INF;
  if (x <= a and b <= y) return T[node];
  return min(
      que(2*node, a, (a+b)/2, x, y),
      que(2*node+1, 1+(a+b)/2, b, x, y));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  
  cin >> n;
  T = vi(8*n, INF);
  int mii = INF;
  int maa = 0;
  vpi V(n);
  vi S(2*n);
  vi K(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    S[i] = S[i+n] = x;
    V[i] = pi(x, i);
    mii = min(x, mii);
    maa = max(x, maa);
    add(1, 0, 2*n, i, x);
    add(1, 0, 2*n, i+n, x);
  }
  stack<pi> ff;
  for (int i = 2*n-1; i >= 0; --i) {
    while (ff.size() and ff.top().first <= S[i]) ff.pop();
    if (i < n) {
      if (ff.size()) K[i] = ff.top().second;
      else K[i] = 2*n-1;
    }
    ff.push(pi(S[i],i));
  }
  if (2*mii >= maa) {
    for (int i = 0; i < n; ++i) {
      if (i) cout << ' ';
      cout << -1;
    }
    cout << '\n';
    return 0;
  }

  vi R(n);
  sort(V.rbegin(), V.rend());
  for (int i = 0; i < n; ++i) {
    int ind = V[i].second;
    int a = ind;
    int lll = K[ind];
    int b = lll+1;
    while (a + 1 < b) {
      int c = (a+b)/2;
      if (que(1,0,2*n,ind,c)*2 < V[i].first) b = c;
      else a = c;
    }
    R[ind] = b - ind;
    if (a == lll and S[ind] < S[K[ind]]) R[ind] += R[K[ind]%n] - 1;
  }
  for (int i = 0; i < n; ++i) {
    if (i) cout << ' ' ;
    cout << R[i];
  }
  cout << '\n';


}