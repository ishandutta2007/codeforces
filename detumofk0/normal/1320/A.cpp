#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n;
  vector<int> a(n);

  long long ans = 0;

  map<int, long long> mymap;
  for(int i = 0; i < n; ++i) {
    int x; cin >> x;
    ans = max(ans, mymap[x - i] += x);
  }

  cout << ans << endl;

  return 0;
}