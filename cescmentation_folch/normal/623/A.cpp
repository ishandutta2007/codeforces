#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi G;
vi V;
int n;

bool xec = true;

int C[3] = {0,0,0};

void dfs(int x) {
  C[V[x]]++;
  for (int i = 0; i < n; ++i) {
    if (G[x][i] == 1 and i != x) {
      if (V[i] != -1 and V[i] == V[x]) xec = false;
      else if (V[i] == -1) {
	V[i] = V[x]^3;
	dfs(i);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int  m;
  cin >> n >> m;
   G = vvi(n, vi(n, 1));
   
   for (int i = 0; i < m; ++i ) {
     int x, y;
     cin >> x >> y;
     --x;
     --y;
     G[x][y] = 0;
     G[y][x] = 0;
  }
  int ttpa = 0;

  V = vi(n, -1);
  for (int i = 0; i < n; ++i) {
    if (V[i] == -1) {
      for (int j = 0; j < n; ++j) {
	if (G[i][j] == 1 and i != j){
	  //cerr << i << endl;
	  V[i] = 1;
	  dfs(i);
	  ++ttpa;
	  //cerr << xec << endl;
	  break;
	}
      }
    }
  }
  
  //cerr << ttpa << endl;
  if (ttpa == 1) {
    int ak1 = -1, ak2 = -1;
    for (int i = 0; i < n; ++i) {
      int s = 0;
      for (int j = 0; j < n; ++j) {
	if (G[i][j] == 1 and i != j) ++s;
      }
      if (V[i] == 1) {
	if (ak1 == -1) ak1 = s;
	else if (ak1 != s) xec = false;
      }
      if (V[i] == 2) {
	if (ak2 == -1) ak2 = s;
	else if (ak2 != s) xec = false;
      }
      //cerr << i << ' ' << V[i] << ' ' << xec << endl;
    }
    //cerr << C[1] << ' ' << ak1 << ' ' << C[2] << ' ' << ak2 << endl;
    if (ak1 != C[2] or ak2 != C[1]) xec = false;
  }
  else if (ttpa > 1) xec = false;
  
  if (xec) {
    cout << "Yes" << endl;
    for (int i = 0; i < n; ++i) {
      if (V[i] == -1) cout << "b";
      if (V[i] == 1) cout << "a";
      if (V[i] == 2) cout << "c";
    }
    cout << endl;
  }
  else cout << "No" << endl;
  
}