#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
const int N = 5e5 + 10;
int P[N], M[N];
struct aresta{
  int x, y, w;
  int ind;
};

aresta A[N];
pi R[N];

bool comp(aresta a, aresta b) {
  return a.w < b.w;
}

int pare(int x) {
  if (P[x] == 0) return x;
  return P[x] = pare(P[x]);
}

int mare(int x) {
  if (M[x] == 0) return x;
  return M[x] = mare(M[x]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> A[i].x >> A[i].y >> A[i].w;
    A[i].ind = i+1;
  }
  sort(A, A + m, comp);
  int j = 0;
  while (j < m) {
    int W = A[j].w;
    int i = j;
    while (j < m and A[j].w == W) {
      if (pare(A[j].x) != pare(A[j].y)) R[A[j].ind] = pi(pare(A[j].x), pare(A[j].y));
      else R[A[j].ind] = pi(-1,-1);
      ++j;
    }
    while (i < j) {
      if (pare(A[i].x) != pare(A[i].y)) P[pare(A[i].x)] = pare(A[i].y);
      ++i;
    }
  }
  int q;
  cin >> q;
  while (q--) {
    bool res = 1;
    int k;
    cin >> k;
    queue<int> Q;
    while (k--) {
      int x;
      cin >> x;
      if (R[x].first == -1) {
        res = 0;
      }
      else {
        if (mare(R[x].first) == mare(R[x].second)) {
          res = 0;
        }
        else {
          Q.push(mare(R[x].first));
          M[mare(R[x].first)] = mare(R[x].second);
        }
      }
    }
    while (!Q.empty()){
      M[Q.front()] = 0;
      Q.pop();
    }
    if (res) cout << "YES\n";
    else cout << "NO\n";
  }
}