#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int N = 300005;
int a[N],n,l[N],r[N];

set<int> s;

int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i < n; ++i)
    cin >> a[i];
  for(int i = 0; i < n; ++i) {
    l[i] = i;
    for(int j = i-1; j >=0; --j) {
      if(a[j] % a[i] != 0) break;
      if(a[j] == a[i]) {
        l[i] = l[j];
        break;
      }
      l[i] = j;
    }
  }
  int mx = 0;
  for(int i = n-1; i >= 0; --i) {
    r[i] = i;
    for(int j = i+1; j < n; ++j) {
      if(a[j] % a[i] != 0) break;
      if(a[j] == a[i]) {
        r[i] = r[j];
        break;
      }
      r[i] = j;
    }
    mx = max(mx,r[i] - l[i]);
  }
  for(int i = 0; i < n; ++i) {
    if(r[i]-l[i] == mx)
      s.insert(l[i]);
  }
  cout << s.size() << " " << mx << "\n";
  while(!s.empty()) {
    cout << *s.begin()+1 << "\n";
    s.erase(s.begin());
  }
  return 0;
}