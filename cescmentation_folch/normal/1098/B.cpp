#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ld, ld> pld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<ld> vld;
typedef vector<vld> vvld;
typedef vector<pld> vpld;
typedef vector<vpld> vvpld;

const int N = 300010;

int col[N][4][2];
int fil[N][4][2];
char C[4] = {'A', 'G', 'C', 'T'};

int solucio_colum(int a, int b, int c, int d, int n) {
  int res = 0;
  for (int i = 0; i < n; i += 2) {
    res += max(col[i][a][0] + col[i][b][1], col[i][a][1] + col[i][b][0]);
  }
  for (int i = 1; i < n; i += 2) {
    res += max(col[i][c][0] + col[i][d][1], col[i][c][1] + col[i][d][0]);
  }
  return res;
}


int solucio_fila(int a, int b, int c, int d, int n) {
  int res = 0;
  for (int i = 0; i < n; i += 2) {
    res += max(fil[i][a][0] + fil[i][b][1], fil[i][a][1] + fil[i][b][0]);
  }
  for (int i = 1; i < n; i += 2) {
    res += max(fil[i][c][0] + fil[i][d][1], fil[i][c][1] + fil[i][d][0]);
  }
  return res;
}

void print_column(int a, int b, int c, int d, int n, int m) {
  char M[n][m];
  for (int i = 0; i < n; i += 2) {
    int a1 = col[i][a][0] + col[i][b][1]; 
    int a2 = col[i][a][1] + col[i][b][0];
    for (int j = 0; j < m; ++j) {
      if ((j%2 and a1 > a2) or (j%2 == 0 and a1 <= a2)) M[i][j] = C[b];
      else M[i][j] = C[a];
    }
  }
  for (int i = 1; i < n; i += 2) {
    int a1 = col[i][c][0] + col[i][d][1]; 
    int a2 = col[i][c][1] + col[i][d][0];
    for (int j = 0; j < m; ++j) {
      if ((j%2 and a1 > a2) or (j%2 == 0 and a1 <= a2)) M[i][j] = C[d];
      else M[i][j] = C[c];
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) cout << M[j][i];
    cout << '\n';
  }
}

void print_fila(int a, int b, int c, int d, int n, int m) {
  char M[n][m];
  for (int i = 0; i < n; i += 2) {
    int a1 = fil[i][a][0] + fil[i][b][1]; 
    int a2 = fil[i][a][1] + fil[i][b][0];
    for (int j = 0; j < m; ++j) {
      if ((j%2 and a1 > a2) or (j%2 == 0 and a1 <= a2)) M[i][j] = C[b];
      else M[i][j] = C[a];
    }
  }
  for (int i = 1; i < n; i += 2) {
    int a1 = fil[i][c][0] + fil[i][d][1]; 
    int a2 = fil[i][c][1] + fil[i][d][0];
    for (int j = 0; j < m; ++j) {
      if ((j%2 and a1 > a2) or (j%2 == 0 and a1 <= a2)) M[i][j] = C[d];
      else M[i][j] = C[c];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cout << M[i][j];
    cout << '\n';
  } 
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  map<char, int> M;
  M['A'] = 0;
  M['G'] = 1;
  M['C'] = 2;
  M['T'] = 3;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char a;
      cin >> a;
      int k = M[a];
      col[j][k][i%2]++;
      fil[i][k][j%2]++;
    }
  }
  vi resc;
  vi resf;
  int valc = -1;
  int valf = -1;
  vi S({0,1,2,3});
  for (int i = 0; i < 24; ++i) {
    int k = solucio_colum(S[0], S[1],S[2], S[3], m);
    int t = solucio_fila(S[0], S[1],S[2], S[3], n);
    if (k > valc) {
      valc = k;
      resc = S;
    }
    if (t > valf) {
      valf = t;
      resf = S;
    }
    next_permutation(S.begin(), S.end());
  }
  if (valc > valf) {
    print_column(resc[0], resc[1], resc[2], resc[3], m, n);
  }
  else {
    print_fila(resf[0], resf[1], resf[2], resf[3], n, m);
  }
}