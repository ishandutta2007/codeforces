#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

vvi D;

bool comp(pi a, pi b) {
  if (D[a.first][b.first]) return (D[a.first][b.first] == 1);
  cout << "? " << a.first << ' ' << b.first << endl;
  char aa;
  cin >> aa;
  if (aa == '>') {
    D[a.first][b.first] = 1;
    D[b.first][a.first] = -1;
  }
  else {
    D[a.first][b.first] = -1;
    D[b.first][a.first] = 1;
  }
  return (D[a.first][b.first] == 1);
}

bool com2(int a, int b) {
  if (D[a][b]) return (D[a][b] == 1);
  cout << "? " << a << ' ' << b << endl;
  char aa;
  cin >> aa;
  if (aa == '>') {
    D[a][b] = 1;
    D[b][a] = -1;
  }
  else {
    D[a][b] = -1;
    D[b][a] = 1;
  }
  return (D[a][b] == 1);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    D = vvi(2*n+2, vi(2*n+2, 0));
    vpi V(n);
    for (int i = 0; i < n; ++i) {
      V[i] = pi(2*i +1, 2*i+2);
      cout << "? " << V[i].first << ' ' << V[i].second << endl;
      char a;
      cin >> a;
      if (a == '>') swap(V[i].first , V[i].second);
    }
    for (int i = 0; i < n; ++i) {
      swap(V[0], V[i]);
      int kk = 0;
      for (int j = 1; j < n; ++j) {
        if (comp(V[0], V[j])) ++kk;
      }
      if (kk == n-1) break;
    }
    vi H(2*n -2);
    for (int i = 0; i < n-1; ++i) {
      H[2*i] = V[i+1].first;
      H[2*i+1] = V[i+1].second;
    }
    for (int i = 0; i < 2*n-2; ++i) {
      swap(H[0], H[i]);
      int kk = 0;
      for (int j = 1; j < 2*n-2; ++j) 
        if (com2(H[0], H[j])) ++kk;
      if (kk == n-1) break;
    }
    com2(V[0].first, H[0]);
    cout << "!" << endl;
  }
}