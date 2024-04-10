#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 

bool home = true;
using namespace std;
#define int long long

typedef long long ll;
typedef long double ld;

const int N = (int)1e5 + 7;
int n;
int l;
int wmax;

ld dv(ld a, ld b) {
  return a / b;
}

signed main() {

#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    FILE* stream;
    freopen_s(&stream, "iron_man.txt", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }


  cin >> n >> l >> wmax;

  vector<vector<int>> clouds(2);
  clouds[0].reserve(n);
  clouds[1].reserve(n);
  for (int i = 0; i < n; i++) {
    int x, v;
    cin >> x >> v;
    assert(v == -1 || v == +1);
    if (v == +1) {
      clouds[0].push_back(x);
    }
    else {
      clouds[1].push_back(x);
    }
  }
  sort(clouds[0].begin(), clouds[0].end());
  sort(clouds[1].begin(), clouds[1].end());
  int dim = (int)clouds[1].size();
  vector<int> x(dim), y(dim);
  for (int i = 0; i < (int)clouds[1].size(); i++) {
    x[i] = clouds[1][i] * (wmax - 1);
    y[i] = clouds[1][i] * (wmax + 1);
  }
  
  ll sol = 0;

  for (auto& x1 : clouds[0]) {

    int vx = x1 * (wmax + 1) + l * (1 - wmax) + 1, vy = x1 * (wmax - 1) + l * (-1 - wmax) + 1;

    int low = 0, high = dim - 1, start = dim;
    while (low <= high) {
      int i = (low + high) / 2;
      if (clouds[1][i] >= -(x1 + l)) {
        start = i;
        high = i - 1;
      }
      else {
        low = i + 1;
      }
    }

    {
      int low = 0, high = start - 1, cnt = 0;
      while (low <= high) {
        int i = (low + high) / 2;
        if (y[i] >= vy) {
          cnt = start - i;
          high = i - 1;
        }
        else {
          low = i + 1;
        }
      }
      sol += cnt;
    }

    {
      int low = start, high = dim - 1, cnt = 0;
      while (low <= high) {
        int i = (low + high) / 2;
        if (x[i] >= vx) {
          cnt = dim - i;
          high = i - 1;
        }
        else {
          low = i + 1;
        }
      }
      sol += cnt;
    }

  }

  cout << sol << "\n";

}