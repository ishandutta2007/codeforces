#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n;
  vector < int > a(n);

  set < int > inside;
  set < int > current_people;

  int ans = 0;
  vector < int > parts;

  for(int i = 0; i < n; ++i) {
    int x; cin >> x;
    if(x < 0) {
      x = -x;
      if(!inside.count(x)) {
        cout << -1;
        return 0;
      }
      inside.erase(x);

      if(!inside.size()){
        ans++;
        parts.push_back(current_people.size() * 2);
        current_people.clear();
        inside.clear();
      }
    }
    else {
      if(current_people.count(x)) {
        cout << -1;
        return 0;
      }
      inside.insert(x);
      current_people.insert(x);
    }
  }

  if(inside.size()) {
    cout << -1;
    return 0;
  }
  cout << ans << endl;
  for(int x : parts) cout << x << " ";

  return 0;
}