#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
using namespace std;

bool check(int x, pair<int, int> a){
  return x >= a.first && x <= a.second;
}

int main() {
  int n; scanf("%d", &n);
  vector<pair<int, pair<int, int>>> vert;
  vector<pair<int, pair<int, int>>> hor;
  for(int i = 0; i<n; i++){
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if(a > c) swap(a, c);
    if(b > d) swap(b, d);
    if(a == c){
      vert.push_back({a, {b, d}});
    }
    else{
      hor.push_back({b, {a, c}});
    }
  }
  if(vert.size() > hor.size()) swap(vert, hor);
  vector<bitset<5000>> v(vert.size());
  for(int i = 0; i<vert.size(); i++){
    for(int j = 0; j<hor.size(); j++){
      v[i][j] = check(vert[i].first, hor[j].second) && check(hor[j].first, vert[i].second);
    }
  }
  long long ans = 0;
  for(int i = 0; i<vert.size(); i++){
    for(int j = i+1; j<vert.size(); j++){
      int cnt = (v[i]&v[j]).count();
      ans += cnt*(cnt-1)/2;
    }
  }
  cout << ans << endl;
}