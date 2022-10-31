#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  map<pair<int, int>, int> um;
  vector<pair<int, int>> v1;
  vector<pair<int, int>> v2;
  for(int i = 0; i<n; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    if(a < b){
      v1.push_back(make_pair(b, a));
      um[make_pair(b, a)] = i+1;
    }
    else{
      v2.push_back(make_pair(b, a));
      um[make_pair(b, a)] = i+1;
    }
  }
  if(v1.size() > v2.size()){
    sort(v1.begin(), v1.end());
    cout << v1.size() << endl;
    for(int i = v1.size()-1; i>=0; i--) printf("%d ", um[v1[i]]);
  }
  else{
    sort(v2.begin(), v2.end());
    cout << v2.size() << endl;
    for(auto i : v2) printf("%d ", um[i]);
  }
  cout << endl;
}