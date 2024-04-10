#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

// #define int ll
#define int ll

struct point {
  int x;
  int y;
  int i;
};

int f(point a, point b) {
  return (a.x - b.x) * (a.y + b.y);
}

int f(point a, point b, point c) {
  return f(a, b) + f(b, c) + f(c, a);
}

ld getdist(point a, point b) {
  ld dx = a.x - b.x;
  ld dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}

const int N = (int) 2e5 + 7;
int n, k;
point a[N]; /// atentieee!!!!!!!!!!!

void print(ld sol) {
  cout << fixed << setprecision(6) << sol << "\n";
  exit(0);
}

bool operator < (point a, point b) {
  if (a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}

mt19937 rng((long long) (new char));

void upd(ld &sol, vector<int> ord) {
  if (ord[0] != k) return;

  ld cur = 0;

  for (int i = 1; i < (int) ord.size(); i++) {
    cur += getdist(a[ord[i - 1]], a[ord[i]]);
  }
  sol = min(sol, cur);
}


ld getbrute() {
  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 1);
  ld sol = (ld) 1e18;
  upd(sol, ord);

  while (next_permutation(ord.begin(), ord.end())) {
    upd(sol, ord);
  }

  return sol;
}

ld pref[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);


  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y;
    a[i].i = i;
  }

  ///cout << fixed << setprecision(6) << getbrute() << "\n";

  if (n == 3) {
    vector<int> rem;
    for (int i = 1; i <= n; i++) {
      if (k != i) {
        rem.push_back(i);
      }
    }
    assert((int) rem.size() == 2);
    print(min(getdist(a[k], a[rem[0]]), getdist(a[k], a[rem[1]])) + getdist(a[rem[0]], a[rem[1]]));
  }

  point special;
  int speciali;

  while (1) {
    int i = rng() % n + 1;
    int j = rng() % n + 1;
   // cout << i << " " << j << "\n";
    while (i == j) {
      j = rng() % n + 1;
    }
    assert(1 <= min(i, j) && min(i, j) < max(i, j) && max(i, j) <= n);
    int cnt = 0, bad = -1;
    for (int k = 1; k <= n; k++) {
      bool ok = (f(a[i], a[j], a[k]) == 0);
      if (!ok) {
        bad = k;
      } else {
        cnt++;
      }
    }
    assert(cnt < n);
    if (cnt == n - 1) {
      special = a[bad];
      speciali = bad;
      break;
    }
  }

  bool caz = (k == speciali);

  ///cout << "special = " << special << "\n";
  vector<point> others;

  for (int i = 1; i <= n; i++) {
    if (i != speciali) {
      others.push_back(a[i]);
    }
  }
  n = (int) others.size();

  sort(others.begin(), others.end());
  ld sol = (ld) 1e18;
  for (int swp = 0; swp <= 1; swp++) {
    int kinit = k;
    if (caz) {
     // for (int j)

      for (int j = 1; j < (int) others.size(); j++) {
        pref[j] = pref[j - 1] + getdist(others[j - 1], others[j]);
      }

      for (int i = 0; i < (int) others.size(); i++) {
        ld cur = getdist(special, others[i]);
        if (1 <= i) {
          cur += pref[i] - pref[0];
        }
        if (i != (int) others.size() - 1) {
          cur += getdist(others[0], others[i + 1]);

          if (i + 2 <= (int) others.size() - 1) {
            cur += pref[(int) others.size() - 1] - pref[i + 1];
          }
        }

        sol = min(sol, cur);
      }

    } else {
      k = -1;
      for (int i = 0; i < (int) others.size(); i++) {
        if (others[i].i == kinit) {
          k = i;
          break;
        }
      }
      assert(k != -1);
      /// intre oricare 2 sau la final
      vector<point> path;

      for (int j = k; j >= 0; j--) {
        path.push_back(others[j]);
      }
      for (int j = k + 1; j < (int) others.size(); j++) {
        path.push_back(others[j]);
      }

      ld total;
      {
        /// la final??
        ld cur = 0;
        for (int j = 1; j < (int) path.size(); j++) {
          cur += getdist(path[j - 1], path[j]);
        }
        total = cur;
        cur += getdist(path.back(), special);
        sol = min(sol, cur);
      }

      {
        /// intre 2??
        for (int i = 0; i < (int) path.size() - 1; i++) {
          ld cur = total - getdist(path[i], path[i + 1]);
          cur += getdist(path[i], special);
          cur += getdist(path[i + 1], special);
          sol = min(sol, cur);
        }
      }


    }
    k = kinit;
    reverse(others.begin(), others.end());
  }
  print(sol);


  return 0;
}