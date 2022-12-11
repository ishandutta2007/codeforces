#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

const int N = 85;

int D[N][N];
vpi V[N][N];
int U[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> D[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int w = 0; w < n; ++w) {
        if (w == i or w == j) continue;
        V[i][j].push_back(pi(D[i][w] + D[w][j], w));
      }
      sort(V[i][j].begin(), V[i][j].end());
    }
  }
  U[0] = 1;
  int i[6];
  i[0] = 0;
  i[5] = 0;
  int resu = 1e9;
  for (i[1] = 0; i[1] < n; ++i[1]) {
    if (k <= 2 and i[1]) break;
    ++U[i[1]];
    for (i[2] = 0; i[2] < n; ++i[2]) {
      if (k <= 4 and i[2]) break;
      ++U[i[2]];
      for (i[3] = 0; i[3] < n; ++i[3]) {
        if (k <= 6 and i[3]) break;
        ++U[i[3]];
        for (i[4] = 0; i[4] < n; ++i[4]) {
          if (k <= 8 and i[4]) break;
          ++U[i[4]];
          int res = 0;
          for (int ind = 0; ind < k/2; ++ind) {
            int id = 0;
            while (id < (int)V[i[ind]][i[ind+1]].size() and U[V[i[ind]][i[ind+1]][id].second]) ++id;
            if (id == (int)V[i[ind]][i[ind+1]].size()) {
              res = 1e9;
              break;
            }
            res += V[i[ind]][i[ind+1]][id].first;
            //cerr << res << ' ' << i[ind] << ' ' << i[ind+1] << endl;
          }
          resu = min(res, resu);
          --U[i[4]];
        }
        --U[i[3]];
      }
      --U[i[2]];
    }
    --U[i[1]];
  }
  cout << resu << endl;
}