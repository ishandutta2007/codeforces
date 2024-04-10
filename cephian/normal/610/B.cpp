#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n;
int pt[200005];
vector<int> q;

int diff(int i, int j) {
  int a = q[i];
  int b = q[j];
  if(b <= a) b += n;
  return b-a-1;
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  int m = 0x7fffffff;
  for(int i = 0; i < n; ++i) {
      cin >> pt[i];
      m = min(m, pt[i]);
  }
  ll ans = ll(n)*m;
  for(int i = 0; i < n; ++i) {
    if(pt[i] == m)
      q.push_back(i);
  }
  int mx = 0;
  for(int i = 0; i < q.size(); ++i) {
    int j = (i+1) % q.size();
    mx = max(mx, diff(i, j));
  }
  cout << ans + mx << "\n";
  return 0;
}