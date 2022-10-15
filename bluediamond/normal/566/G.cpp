#include <bits/stdc++.h>

using namespace std;

bool home = 1;
#define int ll

typedef long long ll;
typedef long double ld;

struct ve {
  int x, y;
};

/**
int dot(ve a, ve b) {
  return a.x * b.x + a.y * b.y;
}
**/
ve operator - (ve a) {
  return {-a.x, -a.y};
}

int cross(ve a, ve b) {
  return a.x * b.y - a.y * b.x;
}

ve operator + (ve a, ve b) {
  return {a.x + b.x, a.y + b.y};
}

ve operator - (ve a, ve b) {
  return {a.x - b.x, a.y - b.y};
}

bool yy(ve a, ve b) {
  return a.y < b.y;
}

bool xx(ve a, ve b) {
  return a.x < b.x;
}

ve getxx(ve a, ve b) {
  if (xx(a, b)) return b;
  return a;
}

ve getyy(ve a, ve b) {
  if (yy(a, b)) return b;
  return a;
}

bool operator == (ve a, ve b) {
  return (a.x == b.x && a.y == b.y);
}

bool cmp(ve a, ve b) {
  if (a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}

const int N = (int) 1e5 + 7;
int n, m;
ve a[N], b[N];

void print() {
  for (int i = 1; i <= n; i++) {
    cout << a[i].x << " " << a[i].y << " " << i << "\n";
  }
  for (int i = 1; i <= m; i++) {
   // cout << b[i].x << " " << b[i].y << " min" << i << "\n";
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ///
  }

  {
    int _;
    cin >> n >> m >> _ >> _;
  }

  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i].x >> b[i].y;
  }

  if (home) {
    print();
  }

  sort(b + 1, b + m + 1, cmp);

  vector<ve> all;

  {
    vector<ve> stk;
    function<int()> sz = [&] () {
      return (int) stk.size();
    };
    for (int i = 1; i <= m; i++) {
      while (sz() >= 2 && cross(stk[sz() - 2] - b[i], stk[sz() - 1] - b[i]) > 0) {
        stk.pop_back();
      }
      stk.push_back(b[i]);
    }
    {
      ve first = stk[0];
      for (int i = 1; i < (int) stk.size(); i++) {
        first = getyy(first, stk[i]);
      }

      for (int i = 0; i < (int) stk.size(); i++) {
        if (stk[i] == first) {
          for (int j = i; j < (int) stk.size(); j++) {
            all.push_back(stk[j]);
          }
          break;
        }
      }
      assert(!all.empty());
    }
    {
      vector<ve> newAll;
      newAll.push_back({0, all[0].y});
      for (auto &it : all) {
        newAll.push_back(it);
      }
      newAll.push_back({all.back().x, 0});

      all = newAll;
    }
  }
  if (home) {
    cout << "\n\n\n";
    for (int i = 0; i < (int) all.size(); i++) {
      cout << all[i].x << " " << all[i].y << " all" << i << "\n";
    }
    cout << "\n\n\n";
  }


  int sz = (int) all.size();

  for (int i = 1; i <= n; i++) {
    int l = 0, r = (int) all.size() - 2;
    while (l <= r) {
      int j = (l + r) / 2;
      int cr = cross(all[j] - a[i], all[j + 1] - a[i]);
      if (cr == 0) {
        bool inside = (all[j].x <= a[i].x && a[i].x <= all[j + 1].x);

        if (!inside) cr = -1;
        /**if (cr == 0) {
          cout << all[j].x << " " << all[j].y << "\n";

          cout << all[j + 1].x << " " << all[j + 1].y << "\n";
          cout << a[i].x << " " << a[i].y << "\n";

          cout << "cr = " << cr << "\n";
          //exit(0);
        }**/
      }
      if (cr >= 0) {
        cout << "Max\n";
        return 0;
      }
      if (a[i].x >= all[j].x) {
        l = j + 1;
      } else {
        r = j - 1;
      }
    }
  }

  cout << "Min\n";

  return 0;
}