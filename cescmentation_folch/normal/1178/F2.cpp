#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef ll llint;
typedef vector<llint> vi;
typedef vector<vi> vvi;
typedef pair<llint, llint> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

const int N = 1000010;
int T[4*N];
int M[4*N];
const ll mod = 998244353;

void actu(int node, int a, int b, int x, ll val) {
  if (x < a or b < x) return;
  if (a == b) {
    T[node] = M[node] = (int)val;
    return;
  }
  actu(2*node,a, (a+b)/2,x,val);
  actu(2*node+1,1+(a+b)/2,b,x,val);
  T[node] = min(T[2*node],T[2*node+1]);
  M[node] = max(M[2*node],M[2*node+1]);
  
}

int que(int node, int a, int b, ll x, ll y) {
  if (y < a or b < x) return 10000;
  if (x <= a and b <= y) return T[node];
  return min(
      que(2*node,a,(a+b)/2,x,y),
      que(2*node+1,1+(a+b)/2,b,x,y)
      );
}
int que2(int node, int a, int b, ll x, ll y) {
  if (y < a or b < x) return 0;
  if (x <= a and b <= y) return M[node];
  return max(
      que2(2*node,a,(a+b)/2,x,y),
      que2(2*node+1,1+(a+b)/2,b,x,y)
      );
}

vi C, L, R;
vpi I;

int leftind(int i) {
  int pos = (int)L[i] - 1;
  if (pos < 0) return -1;
  int val = (int)C[pos];
  if ((int)R[I[val].second] == pos)
    return (int)I[val].second;
  return -1;
}

int rightind(int i) {
  int pos = (int)R[i] + 1;
  if (pos >= (int)C.size()) return -1;
  int val = (int)C[pos];
  if ((int)L[I[val].first] == pos)
    return (int)I[val].first;
  return -1;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  memset(T, 0x7f, sizeof(T));
  int n, m;
  cin >> n >> m;
  C = vi(m);
  for (int i = 0; i < m; ++i) {
    cin >> C[i];
    actu(1, 0, m, i, C[i]);
  }
  I = vpi(n+1, pi(-1,-1));
  for (int i = 0; i < m; ++i) {
    if (I[C[i]].first == -1) I[C[i]].first = i;
    I[C[i]].second = i;
  }
  L = R = vi(n);
  for (int i = 1; i <= n; ++i) {
    L[i-1] = I[i].first;
    R[i-1] = I[i].second;
  }
  sort(L.begin(), L.end());
  sort(R.begin(), R.end());

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (L[j] == I[i].first) {
        I[i].first = j;
        break;
      }
    }
    for (int j = 0; j < n; ++j) {
      if (R[j] == I[i].second) {
        I[i].second = j;
        break;
      }
    }
  }

  vi F(n);
  int j = 0;
  for (int i = 0; i < n; ++i) {
    while (R[j] < L[i]) ++j;
    F[i] = j;
  }

  vvi D(n, vi(n, 0));

  for (int l = 0; l < n; ++l) {
    for (int i = 0; i < n; ++i) {
      int j = (int)F[i] + l;
      if (j >= n) break;

      int mi = que(1, 0, m, L[i], R[j]);
      if (i > I[mi].first or j < I[mi].second) {
        D[i][j] = 0;
        continue;
      }

      if (i == I[mi].first and I[mi].second == j) {
        D[i][j] = 1;
        int w = i+1;
        int ant = L[i];
        while (w < n and L[w] <= R[j]) {
          if (que2(1,0,m,ant,L[w]-1) != mi) {
            D[i][j] = 0;
            break;
          }
          int a = L[w];
          int b = R[j];
          while (a+1 < b) {
            int c = (a+b)/2;
            if (que(1,0,m,L[w],c) == mi) b = c;
            else a = c;
          }
          int val = C[a];
          if (R[I[val].second] != a) {
            D[i][j] = 0;
            break;
          }
          D[i][j] = (D[i][j]*D[w][I[val].second])%mod;
          while (w < n and L[w] <= a) ++w;
          ant = a + 1;
        }
        if (ant < R[j] and que2(1,0,m,ant,R[j]) != mi) {
          D[i][j] = 0;
        }
        //cerr << mi << ' ' << D[i][j] << endl;
        continue;
      }

      ll left = 0;
      int t = leftind((int)I[mi].first);
      for (int w = i; w <= I[mi].first and t != -1; ++w) {
        if (w == i or w == I[mi].first) {
          left = (left + D[i][t])%mod;
        } else {
          int t2 = leftind(w);
          if (t2 == -1) continue;
          left = (left + D[i][t2]*D[w][t])%mod;
        }
      }
      if (i == I[mi].first) left = 1;

      ll right = 0;
      int s = rightind((int)I[mi].second);
      for (int w = (int)I[mi].second; w <= j and s != -1; ++w) {
        if (w == I[mi].second or w == j) {
          right = (right + D[s][j])%mod;
        } else {
          int s2 = rightind(w);
          if (s2 == -1) continue;
          right = (right + D[s][w]*D[s2][j])%mod;
        }
      }
      if (j == I[mi].second) right = 1;

      ll extra = left*right%mod;

      D[i][j] = D[I[mi].first][I[mi].second]*extra%mod;
      //cerr << L[i] << ' ' << R[j] << endl;
      //cerr << left << ' ' << right << endl;
      //cerr << i << ' ' << j << ' ' << D[i][j] << endl;
    }
  }
  cout << D[0][n-1] << endl;
}