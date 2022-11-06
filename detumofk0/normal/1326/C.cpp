#include<bits/stdc++.h>

using namespace std;

const long long mod = 998244353;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, k; cin >> n >> k;
  vector<int> pos(n);

  for(int i = 0; i < n; ++i) {
    int x; cin >> x;
    pos[--x] = i;
  }

  long long sum = 0;

  vector<int> vec;
  for(int i = n - 1; i >= n - k; --i) {
    vec.push_back(pos[i]);
    sum += i + 1;
  }

  sort(vec.begin(), vec.end());

  long long ans = 1;

  for(int i = 1; i < vec.size(); ++i) {
    ans = (ans * (vec[i] - vec[i - 1]) % mod);
  }

  cout << sum << " " << ans << endl;

  return 0;
}