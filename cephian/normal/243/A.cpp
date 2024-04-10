#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int n, arr[100005];
set<int> ans, a, b;

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i)
    cin >> arr[i];
  b.insert(0);
  for(int i = 0; i < n; ++i) {
    a.clear();
    a.insert(arr[i]);
    for(set<int>::iterator j = b.begin(); j != b.end(); ++j)
      a.insert((*j) | arr[i]);
    for(set<int>::iterator j = a.begin(); j != a.end(); ++j)
        ans.insert(*j);
    swap(b, a);
  }
  cout << ans.size() << "\n";
}