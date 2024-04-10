#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;


int n;
pii a[100005];
int mp[100005];
int mn[100005];
int mx[100005];
bool cmp(const pii& a, const pii& b) {
  return a.second < b.second;
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a, a + n);
  for(int i = 0; i < n; ++i) {
    mp[a[i].second] = i;
    mn[i] = 0x7fffffff;
    mx[i] = max(abs(a[i].first - a[0].first), abs(a[i].first - a[n-1].first));
    if(i != 0)
      mn[i] = min(mn[i], abs(a[i].first - a[i-1].first));
    if(i != n-1)
      mn[i] = min(mn[i], abs(a[i].first - a[i+1].first));
  }
  for(int i = 0; i < n; ++i)
    cout << mn[mp[i]] << " " << mx[mp[i]] << "\n";
}