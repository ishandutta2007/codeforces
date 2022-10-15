#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 7;
int n;

struct T {
  int a, b;
} v[N];

struct Move {
  T before;
  T after;
};


int getid(int x, int y) {
  if (min(x, y) + 1 == max(x, y)) return 0;
  if (min(x, y) == 1 && max(x, y) == n) return 0;

  for (int i = 1; i <= n - 3; i++) {
    if (min(v[i].a, v[i].b) == min(x, y) && max(v[i].a, v[i].b) == max(x, y)) {
      return i;
    }
  }

}

vector<Move> sol;

void upd(int i, T value) {
  sol.push_back({v[i], value});
  v[i] = value;
}

vector<Move> algo(T lol[]) {
  for (int i = 1; i <= n - 3; i++) {
    v[i] = lol[i];
  }
  sol.clear();
  while (1) {
    vector<int> ones;
    for (int i = 1; i <= n - 3; i++) {
      if (v[i].a == 1 || v[i].b == 1) {
        ones.push_back(v[i].a + v[i].b - 1);
      }
    }
    ones.push_back(2);
    ones.push_back(n);
    if ((int) ones.size() == n - 1) {
      break;
    }

    sort(ones.begin(), ones.end());

    int x = -1, y = -1;
    for (int i = 0; i + 1 < (int) ones.size(); i++) {
      if (ones[i] + 1 != ones[i + 1]) {
        x = ones[i];
        y = ones[i + 1];
        break;
      }
    }
    int i1 = getid(1, x);
    int i2 = getid(1, y);
    int i3 = getid(x, y);


    int cx = 0, cy = 0;
    for (int i = 1; i <= n - 3; i++) {
      if (x == v[i].a || x == v[i].b) {
        int other = v[i].a + v[i].b - x;
        cx += (x < other && other < y);
      }
      if (y == v[i].a || y == v[i].b) {
        int other = v[i].a + v[i].b - y;
        cy  += (x < other && other < y);
      }
    }
    if (cx == 0 && cy == 0) {
      upd(i3, {1, x + 1});
      continue;
    }
    if (cx) {
      int val = -(int) 1e9;
      for (int i = 1; i <= n - 3; i++) {

        if (x == v[i].a || x == v[i].b) {
          int other = v[i].a + v[i].b - x;
          if (x < other && other < y) {
            val = max(val, other);
          }
        }
      }
      upd(i3, {1, val});
    } else {
      int val = (int) 1e9;
      for (int i = 1; i <= n - 3; i++) {

        if (y == v[i].a || y == v[i].b) {
          int other = v[i].a + v[i].b - y;
          if (x < other && other < y) {
            val = min(val, other);
          }
        }
      }
      upd(i3, {1, val});
    }
  }
  return sol;
}

T now[N], want[N];


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;

  for (int i = 1; i <= n - 3; i++) cin >> now[i].a >> now[i].b;
  for (int i = 1; i <= n - 3; i++) cin >> want[i].a >> want[i].b;


  vector<Move> ff = algo(now);
  vector<Move> ss = algo(want);


  cout << (int) ff.size() + (int) ss.size() << "\n";
  for (auto &it : ff) {
    cout << it.before.a << " " << it.before.b << "\n";
  }
  reverse(ss.begin(), ss.end());
  for (auto &it : ss) {
    swap(it.before, it.after);
    cout << it.before.a << " " << it.before.b << "\n";
  }

  return 0;
}