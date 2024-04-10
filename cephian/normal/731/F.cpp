#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <vector>
#include <iomanip>
#include <set>
#include <algorithm>

using namespace std;
typedef long long ll;

const int N = 200005;
int pfx[N],n,a;
set<int> s;

ll calc(int x) {
  ll ans = 0;
  for(int i = 1; ;++i) {
    int lo = i*x;
    if(lo >= N) break;
    int hi = min((i+1)*x-1,N-1);
    ans += ll(pfx[hi]-pfx[lo-1])*lo;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> a;
    ++pfx[a];
    s.insert(a);
  }
  for(int i = 1; i < N; ++i)
    pfx[i] += pfx[i-1];
  ll c = 0;
  for(set<int>::iterator a = s.begin(); a != s.end(); ++a) {
    c = max(c,calc(*a));
  }
  cout << c << "\n";
  return 0;
}