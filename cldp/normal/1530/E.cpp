#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using LL = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    string s;
    cin >> s;
    map<char, int> cnt;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      ++cnt[s[i]];
    }
    if (cnt.size() == 1) {
      cout << s << "\n";
      continue;
    }
    char hasone = 0;
    for (auto [a, b] : cnt) {
      if (b == 1) {
        hasone = a;
        break;
      }
    }
    if (hasone != 0) {
      cout << hasone;
      cnt.erase(hasone);
      for (auto [a, b] : cnt) {
        for (int i = 0; i < b; ++i) cout << a;
      }
      cout << "\n";
      continue;
    }

    vector<char> rest;
    bool isfirst = true;
    for (auto [a, b] : cnt) {
      if (isfirst) {
        isfirst = false;
        continue;
      }
      for (int i = 0; i < b; ++i) rest.push_back(a);
    }
    reverse(rest.begin(), rest.end());
    if (cnt.size() >= 3) {
      int sumfirst = cnt.begin()->second;
      int sumrest = rest.size();
      if (sumrest >= sumfirst - 2) {
        char firstc = cnt.begin()->first;
        cout << firstc << firstc;
        for (int i = 0; i < sumfirst - 2; ++i) {
          cout << rest.back() << firstc;
          rest.pop_back();
        }
        while (!rest.empty()) {
          cout << rest.back();
          rest.pop_back();
        }
        cout << "\n";
        continue;
      } else {
        char bb, cc;
        int now = 0;
        for (auto [a, b] : cnt) {
          if (now == 0) {
            ++now;
            continue;
          }
          if (now == 1) {
            bb = a;
            ++now;
            continue;
          }
          if (now == 2) {
            cc = a;
            break;
          }
        }
        char firstc = cnt.begin()->first;
        cout << firstc << bb;
        for (int i = 0; i < sumfirst - 1; ++i) cout << firstc;
        cout << cc;
        --cnt[bb];
        --cnt[cc];
        cnt.erase(firstc);
        for (auto [a, b] : cnt) {
          for (int i = 0; i < b; ++i) cout << a;
        }
        cout << "\n";
        continue;
      }
    }
    int now = 0;
    char aa, bb;
    int na, nb;
    for (auto [a, b] : cnt) {
      if (now == 0) {
        aa = a;
        na = b;
        ++now;
        continue;
      } 
      if (now == 1) {
        bb = a;
        nb = b;
        break;
      }
    }
    if (nb >= na - 2) {
      cout << aa << aa;
      for (int i = 0; i < na - 2; ++i) cout << bb << aa;
      nb -= na - 2;
      for (int i = 0; i < nb; ++i) cout << bb;
      cout << '\n';
    } else {
      cout << aa;
      for (int i = 0; i < nb; ++i) cout << bb;
      for (int i = 0; i < na - 1; ++i) cout << aa;
      cout << '\n';
    }
  }
  return 0;
}