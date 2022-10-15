#include <bits/stdc++.h>

bool home = 1;

using namespace std;

const int N = 20 + 7;
const int INF = (int) 1e9 + 7;
int n;
int m;
int maximum;
int like[2][N][N];
int a[N][N];
int Type[N];
vector<int> u, v, p, way;
vector<vector<vector<int>>> isto;

int getValueInMatrix(int i, int j) {
  return a[i - 1][j - 1];
}

void hungary_step(int n, int i) {
  isto.push_back({u, v, p, way});
  {
    p[0] = i;
    int j0 = 0;
    vector<int> minv(m + 1, INF);
    vector<bool> used(m + 1, false);
    do {
      used[j0] = true;
      int i0 = p[j0], delta = INF, j1;
      for (int j = 1; j <= m; j++) {
        if (!used[j]) {
          int cur = getValueInMatrix(i0, j) - u[i0] - v[j];
          if (cur < minv[j]) {
            minv[j] = cur;
            way[j] = j0;
          }
          if (minv[j] < delta) {
            delta = minv[j];
            j1 = j;
          }
        }
      }
      for (int j = 0; j <= m; j++) {
        if (used[j]) {
          u[p[j]] += delta;
          v[j] -= delta;
        } else {
          minv[j] -= delta;
        }
      }
      j0 = j1;
    } while (p[j0] != 0);
    do {
      int j1 = way[j0];
      p[j0] = p[j1];
      j0 = j1;
    } while (j0);
  }
}

void revert() {
  assert(!isto.empty());
  u = isto.back()[0];
  v = isto.back()[1];
  p = isto.back()[2];
  way = isto.back()[3];
  isto.pop_back();
}

void bkt(int position, int cnt0, int cnt1) {
  if (position == n) {
    assert(cnt0 == n / 2 && cnt1 == n / 2);


    maximum = max(maximum, v[0]);



    return;
  }
  assert(position < n);
  if (cnt0 + 1 <= n / 2) {
    Type[position] = 0;

    int i = position;
    for (int j = 0; j < n; j++) {
      a[i][j] = -like[Type[i]][i][j];
    }
    hungary_step(n, position + 1);

    bkt(position + 1, cnt0 + 1, cnt1);
    revert();
  }
  if (cnt1 + 1 <= n / 2) {
    Type[position] = 1;

    int i = position;
    for (int j = 0; j < n; j++) {
      a[i][j] = -like[Type[i]][i][j];
    }
    hungary_step(n, position + 1);

    bkt(position + 1, cnt0, cnt1 + 1);
    revert();
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  if (home) {
    freopen("I_am_iron_man", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin >> n;
  m = n;
  assert(n % 2 == 0);

  u.resize(n + 1, 0);
  v.resize(n + 1, 0);
  p.resize(n + 1, 0);
  way.resize(n + 1, 0);

  for (int IT = 0; IT < 2; IT++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> like[IT][i][j];
      }
    }
  }



  bkt(0, 0, 0);
  cout << maximum << "\n";
}