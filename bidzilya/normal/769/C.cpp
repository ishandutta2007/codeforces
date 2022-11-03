#include <algorithm>
#include <queue>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

const int LIM = 1e+3 + 1;
const string impossible = "IMPOSSIBLE";
const char EMPTY = '.';
const char START = 'X';

vector<string> f(LIM);
int n, m, k;

const vector<int>  di   = {  1,   0,   0,  -1};
const vector<int>  dj   = {  0,  -1,   1,   0};
const vector<char> name = {'D', 'L', 'R', 'U'};

bool can_move(int i, int j) {
  for (size_t dir = 0; dir < di.size(); ++dir) {
    int ni = i + di[dir];
    int nj = j + dj[dir];
    if (ni >= 0 && ni < n && nj >= 0 && nj < m && f[ni][nj] == EMPTY)
      return true;
  }
  return false;
}

int main() {
  auto start = high_resolution_clock::now();

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i)
    cin >> f[i];

  int si = -1, sj = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (f[i][j] == START) {
        si = i;
        sj = j;
      }
    }
  }

  if ((k & 1) || !can_move(si, sj)) {
    cout << impossible << endl;
    return 0;
  }

  f[si][sj] = EMPTY;

  vector<vector<int>> dist(n, vector<int>(m, -1));
  dist[si][sj] = 0;
  queue<pair<int, int>> q;
  q.emplace(si, sj);
  while (!q.empty()) {
    int ci = q.front().first;
    int cj = q.front().second;
    q.pop();

    for (size_t dir = 0; dir < di.size(); ++dir) {
      int ni = ci + di[dir];
      int nj = cj + dj[dir];
      if (ni >= 0 && ni < n && nj >= 0 && nj < m && f[ni][nj] == EMPTY && dist[ni][nj] == -1) {
        dist[ni][nj] = dist[ci][cj] + 1;
        q.emplace(ni, nj);
      }
    }
  }

  int ci = si, cj = sj;
  string ans = "";
  while (k > 0) {
    if (dist[ci][cj] == k) {
      for (size_t dir = 0; dir < di.size(); ++dir) {
        int ni = ci + di[dir];
        int nj = cj + dj[dir];
        if (ni >= 0 && ni < n && nj >= 0 && nj < m && dist[ni][nj] == k - 1) {
          ans += name[dir];
          ci = ni;
          cj = nj;
          break;
        }
      }
    } else {
      for (size_t dir = 0; dir < di.size(); ++dir) {
        int ni = ci + di[dir];
        int nj = cj + dj[dir];
        if (ni >= 0 && ni < n && nj >= 0 && nj < m && f[ni][nj] == EMPTY) {
          ans += name[dir];
          ci = ni;
          cj = nj;
          break;
        }
      }
    }
    --k;
  }

  cout << ans << endl;

  cerr << "Total execution time : " << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " ms" << endl;

  return 0;
}