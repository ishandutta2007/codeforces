#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

bool swapped = false;
int ask(int r1, int c1, int r2, int c2) {
  if (swapped) swap(r1, c1), swap(r2, c2);
  cout << "? " << ++r1 << ' ' << ++c1 << ' ' << ++r2 << ' ' << ++c2 << endl;
  int ans; cin >> ans;
  return ans;
}

void answer(int r1, int c1, int r2, int c2) {
  if (swapped) swap(r1, c1), swap(r2, c2);
  cout << "! " << ++r1 << ' ' << ++c1 << ' ' << ++r2 << ' ' << ++c2 << endl;
  exit(0);
}

int n;
vector<bool> r, c;

int find(int row) {
    int left = 0, right = n - 1;
    while (right > left) {
      int mid = (left + right) / 2;
      if (ask(row, left, row, mid) & 1) right = mid;
      else left = mid + 1;
    }
    return left;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    r.resize(n);
    c.resize(n);
    bool sr = 0, sc;
    rep(i, n - 1) {
      r[i] = ask(i, 0, i, n - 1) & 1;
      c[i] = ask(0, i, n - 1, i) & 1;
      sr ^= r[i];
      sc ^= c[i];
    }
    r.back() = sr;
    c.back() = sc;
    vector<int> ansr;
    rep(i, n) {
      if (r[i]) ansr.push_back(i);
    }
    if (!ansr.size()) {
      swap(r, c);
      swapped = true;
      rep(i, n) {
        if (r[i]) ansr.push_back(i);
      }
    }

    assert(len(ansr) == 2);
    // clog << swapped << endl;
    answer(ansr[0], find(ansr[0]), ansr[1], find(ansr[1]));

    return 0;
}