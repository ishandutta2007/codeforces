#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

const int K = 14;
const int N = (1<<6);
const int NN = (1<<13);

ll T[2*N][N];
ll D[K][N];
ll R[NN];
vvi A;

void fes(int n, vi V, int id) {
  do {
    int mask = 0;
    for (int i = 0; i < n-1; ++i) {
      if (A[V[i]][V[i+1]]) mask |= (1<<i);
    }
    if (id) D[V[0]][mask]++;
    else D[V.back()][mask]++;
  } while (next_permutation(V.begin(), V.end()));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  A = vvi(n, vi(n,0));
  for (int i = 0; i < n; ++i) {
    string a;
    cin >> a;
    for (int j = 0; j < n; ++j) {
      if (a[j] == '1') A[i][j] = 1;
    }
  }
  int m = n/2;
  for (int mask = 0; mask < (1<<n); ++mask) {
    if (__builtin_popcount(mask) != m) continue;
    vi V1,V2;
    memset(D,0, sizeof(D));
    memset(T,0, sizeof(T));
    for (int i = 0; i < n; ++i) {
      if ((1<<i)&mask) V1.push_back(i);
      else V2.push_back(i);
    }
    int n1 = (int)V1.size();
    int n2 = (int)V2.size();
    fes(n1, V1, 1);
    fes(n2, V2, 0);
    for (int ma = 0; ma < (1<<n2); ++ma) {
      for (int i = 0; i < n2; ++i) {
        if (((1<<i)&ma) == 0) continue;
        for (int mask2 = 0; mask2 < (1<<(n2-1)); ++mask2) {
          T[ma][mask2] += D[V2[i]][mask2];
        }
      }
    }
    int ext = (1<<(n2-1));
    for (auto x1 : V1) { 
      int maska1 = 0;
      int maska0 = 0;
      for (int i = 0; i < n2; ++i) {
        if (A[x1][V2[i]]) maska1 |= (1<<i);
        else maska0 |= (1<<i);
      }
      for (int mask1 = 0; mask1 < (1<<(n1-1)); ++mask1) {
        for (int mask2 = 0; mask2 < (1<<(n2-1)); ++mask2) {
          int mass = mask2 | (mask1<<n2);
          R[mass] += D[x1][mask1]*T[maska0][mask2];
          mass |= ext;
          R[mass] += D[x1][mask1]*T[maska1][mask2];
        }
      }
    }
  }
  for (int mask = 0; mask < (1<<(n-1)); ++mask) {
    if (mask) cout << ' ';
    cout << R[mask];
  }
  cout << '\n';
}