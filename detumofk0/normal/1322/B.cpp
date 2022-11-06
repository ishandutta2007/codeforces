#include<bits/stdc++.h>

using namespace std;

long long with_hold(vector<int> &v, int bound) {
  int pter = 0;
  long long ans = 0;
  for(int i = v.size() - 1; i >= 0; --i) {
    while(pter + 1 < i && v[i] + v[pter] < bound) ++pter;
    if(v[i] + v[pter] >= bound) ans += i - pter;
  }
  return ans;
}

long long without_hold(vector<int> &a, vector<int> &b, int bound) {
  if(b.empty() || a.empty()) return 0;
  int pter = (int)b.size() - 1;
  long long ans = 0;
  for(int i = 0; i < a.size(); ++i) {
    while(pter > 0 && a[i] + b[pter] >= bound) --pter;
    if(pter >= 0 && a[i] + b[pter] < bound) ans += pter + 1;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);


  int n; cin >> n;

  vector<int> a(n);
  vector<vector<int>> yes(26), no(26);

  for(int &x : a) {
    int cur = 0;
    cin >> x;
    for(int i = 0; i < 26; ++i) {
      if(x & (1 << i)) {
        yes[i].emplace_back(cur);
        cur |= (1 << i);
      }
      else no[i].emplace_back(cur);
    }
  }
  long long ret = 0;
  for(int i = 0; i < 26; ++i) {
    sort(no[i].begin(), no[i].end());
    sort(yes[i].begin(), yes[i].end());
    long long ans = with_hold(yes[i], 1 << i) + with_hold(no[i], 1 << i);
    ans += without_hold(yes[i], no[i], 1 << i);

    if(ans % 2 == 1) ret ^= 1 << i;
  }

  cout << ret << endl;

  return 0;
}