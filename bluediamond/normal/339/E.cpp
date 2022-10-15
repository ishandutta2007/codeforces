/// lmao, thanks dj3500:))
#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 7;
int n, a[N];
vector<pair<int, int>> ret;

void bkt(int done) {
  bool good = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] != i) {
      good = 0;
      break;
    }
  }
  if (good) {
    reverse(ret.begin(), ret.end());
    cout << (int) ret.size() << "\n";
    for (auto &it : ret) cout << it.first << " " << it.second << "\n";
    exit(0);
  }
  if (done == 3) {
    return;
  }
  vector<int> sus;
  for (int i = 1; i <= n; i++) if (abs(a[i] - a[i - 1]) != 1 || abs(a[i] - a[i + 1]) != 1) sus.push_back(i);
  for (int i = 0; i < (int) sus.size(); i++) for (int j = i + 1; j < (int) sus.size(); j++) {
    int l = sus[i], r = sus[j];
    ret.push_back({l, r});
    reverse(a + l, a + r + 1);
    bkt(done + 1);
    reverse(a + l, a + r + 1);
    ret.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  a[0] = a[n + 1] = -1;
  for (int i = 1; i <= n; i++) cin >> a[i];
  bkt(0);
  assert(0);
}