#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool home = true;

struct Cell {
  int x;
  int y;
  int type;
};

bool cmp1(Cell a, Cell b) {
  return a.x < b.x;
}

bool cmp2(Cell a, Cell b) {
  return a.y < b.y;
}

const int N = (int) 1e5 + 7;
int n;

bool okLR(vector<Cell> &cells, int need, vector<int> ord) {
  int first = ord[0], second = ord[1], third = ord[2];
  int cntFirst = 0;
  for (int i = 0; i < n; i++) {
    if (cells[i].type == first) {
      cntFirst++;
      if (cntFirst == need) {
        int cntSecond = 0;
        for (int j = i + 1; j < n; j++) {
          if (cells[j].x > cells[i].x && cells[j].type == second) {
            cntSecond++;
            if (cntSecond == need) {
              int cntThird = 0;
              for (int k = j + 1; k < n; k++) {
                if (cells[k].x > cells[j].x && cells[k].type == third) {
                  cntThird++;
                  if (cntThird == need) {
                    return true;
                  }
                }
              }
              return false;
            }
          }
        }
        return false;
      }
    }
  }
  assert(false);
}

struct Bbox {
  int xmin = (int) 1e9, ymin = (int) 1e9;
  int xmax = -(int) 1e9, ymax = -(int) 1e9;
  int ind;

  void add(int x, int y) {
    xmin = min(xmin, x);
    xmax = max(xmax, x);

    ymin = min(ymin, y);
    ymax = max(ymax, y);
  }
};

bool okUD(vector<Cell> &cells, vector<Cell> &cells2, int need, vector<int> ord) {
  int first = ord[0], second = ord[1], third = ord[2];
  int cntFirst = 0;
  for (int i = 0; i < n; i++) {
    if (cells[i].type == first) {
      cntFirst++;
      if (cntFirst == need) {
        int cntSecond = 0;
        for (int j = 0; j < n; j++) {
          if (cells2[j].x > cells[i].x && cells2[j].type == second) {
            cntSecond++;
            if (cntSecond == need) {
              int cntThird = 0;
              for (int k = j + 1; k < n; k++) {
                if (cells2[k].y > cells2[j].y && cells2[k].x > cells[i].x && cells2[k].type == third) {
                  cntThird++;
                  if (cntThird == need) {
                    return true;
                  }
                }
              }
              return false;
            }
          }
        }
        return false;
      }
    }
  }
  assert(false);
}

void upd(int invx, int invy, vector<int> ord, int &bestK, vector<Cell> cells, vector<Cell> cells2) {

  int low = bestK + 1, high = n / 3;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (okLR(cells, mid, ord)) {
      bestK = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  low = bestK + 1;
  high = n / 3;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (okUD(cells, cells2, mid, ord)) {
      bestK = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
}

signed main() {

#ifndef ONLINE_JUDGE

  home = true;
  freopen ("input", "r", stdin);

#endif // ONLINE_JUDGE

  if (!home) {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin >> n;
  vector<Cell> cells(n);

  for (auto &cell : cells) {
    cin >> cell.x >> cell.y >> cell.type;
  }

  int bestK = 0;

  for (int swp = 0; swp < 2; swp++) {
    for (int invx = 0; invx < 2; invx++) {
      for (int invy = 0; invy < 2; invy++) {
        vector<Cell> cells2;
        if (invx) {
          for (auto &cell : cells) {
            cell.x *= -1;
          }
        }
        if (invy) {
          for (auto &cell : cells) {
            cell.y *= -1;
          }
        }
        sort(cells.begin(), cells.end(), cmp1);
        cells2 = cells;
        sort(cells2.begin(), cells2.end(), cmp2);

        vector<int> ord = {1, 2, 3};
        upd(invx, invy, ord, bestK, cells, cells2);
        while (next_permutation(ord.begin(), ord.end())) {
          upd(invx, invy, ord, bestK, cells, cells2);
        }

        if (invx) {
          for (auto &cell : cells) {
            cell.x *= -1;
          }
        }
        if (invy) {
          for (auto &cell : cells) {
            cell.y *= -1;
          }
        }
      }
    }
    for (auto &cell : cells) {
      swap(cell.x, cell.y);
    }
  }

  cout << 3 * bestK << "\n";

}