#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> v(n+1);
  for(int i = 1; i<=n; i++){
    cin >> v[i].first >> v[i].second;
  }
  cout << 1 << " ";
  int cur1, cur2;
  if(v[v[1].first].first == v[1].second || v[v[1].first].second == v[1].second){
    cout << v[1].first << " ";
    cur1 = v[1].first;
    cur2 = v[1].second;
  }
  else{
    cout << v[1].second << " ";
    cur1 = v[1].second;
    cur2 = v[1].first;
  }
  while(cur2 != 1){
    if(v[cur1].first == cur2){
      cur2 = v[cur1].second;
      cur1 = v[cur1].first;
    }
    else{
      cur2 = v[cur1].first;
      cur1 = v[cur1].second;
    }
    cout << cur1 << " ";
  }
  cout << endl;
}