#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      freq[x]++;
    }
    vector<int> a;
    for (const pair<int, int>& p: freq) {
      if (p.second >= k) a.push_back(p.first);
    }
    if (!a.size()) {
      cout << "-1\n";
      continue;
    }
    sort(a.begin(), a.end());
    int curl = -1;
    int cur = -3;
    int l = 0, r = -1;
    for (int x: a) {
      if (x == cur+1) {
        cur++;
      }
      else {
        if (cur - curl > r-l) {
          r = cur;
          l = curl;
        }
        cur = x;
        curl = x;
      }
    }
    if (cur - curl > r-l) {
      r = cur;
      l = curl;
    }
    cout << l << " " << r << '\n';
  }
}