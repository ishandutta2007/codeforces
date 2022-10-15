#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE


  function<bool(vector<int>)> isGood = [&] (vector<int> v) {


    if (*min_element(v.begin(), v.end()) <= 0) {
      return false;
    }

    const int B = 31;
    vector<int> t(B);
    vector<bool> isActive(B, false);
    iota(t.begin(), t.end(), 0);

    function<int(int)> getRoot = [&] (int a) {
      if (t[a] == a) {
        return a;
      } else {
        return t[a] = getRoot(t[a]);
      }
    };

    function<void(int, int)> join = [&] (int a, int b) {
      t[getRoot(a)] = getRoot(b);
    };

    for (auto &x : v) {
      int last = -1;
      for (int bit = 0; bit < B; bit++) {
        if (x & (1 << bit)) {
          isActive[bit] = true;
          if (last != -1) {
            join(last, bit);
          }
          last = bit;
        }
      }
    }

    int guy = -1;
    for (int bit = 0; bit < B; bit++) {
      if (isActive[bit]) {
        if (guy == -1) {
          guy = bit;
        } else {
          if (getRoot(guy) != getRoot(bit)) {
            return false;
          }
        }
      }
    }
    return true;
  };


  int Tests;
  cin >> Tests;

  for (int testCase = 1; testCase <= Tests; testCase++) {
    int n, cnt0 = 0;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
      cnt0 += (x == 0);
      if (x == 0) {
        x++;
      }
    }
    if (isGood(a)) {
      cout << cnt0 << "\n";
      for (auto &x : a) {
        cout << x << " ";
      }
      cout << "\n";
      continue;
    }
    bool Found = false;
    for (auto &x : a) {
      x++;
      if (isGood(a)) {
        Found = true;
        cout << cnt0 + 1 << "\n";
        for (auto &x : a) {
          cout << x << " ";
        }
        cout << "\n";
        break;
      }
      x--;
      x--;
      if (isGood(a)) {
        Found = true;
        cout << cnt0 + 1 << "\n";
        for (auto &x : a) {
          cout << x << " ";
        }
        cout << "\n";
        break;
      }
      x++;
    }
    if (Found) {
      continue;
    }
    vector<int> Inds;
    int Maximum = -((int) 1e9 + 7);
    for (int i = 0; i < n; i++) {
      int lowBit = 0;
      while (!(a[i] & (1 << lowBit))) {
        lowBit++;
      }
      if (lowBit > Maximum) {
        Maximum = lowBit;
        Inds.clear();
      }
      if (lowBit == Maximum) {
        Inds.push_back(i);
      }
    }
    if ((int) Inds.size() < 2) {
      cout << "bad : " << (int) Inds.size() << "\n";
      cout << n << "\n";
      for (auto &x : a) {
        cout << x << " ";
      }
      cout << "\n";
      exit(0);
    }

    a[Inds[0]]++;
    a[Inds[1]]--;
    cout << cnt0 + 2 << "\n";
    for (auto &x : a) {
      cout << x << " ";
    }
    cout << "\n";
  }
}