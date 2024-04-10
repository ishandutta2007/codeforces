#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector < int > lab(n, -1);
	
  function < int(int) > find = [&] (int x){
    if(lab[x] < 0) return x;
    return lab[x] = find(lab[x]);
  };

  function < bool(int x, int y) > join = [&](int x, int y) {
    if((x = find(x)) == (y = find(y))) return false;
    if(lab[x] > lab[y]) swap(x, y);
    lab[x] += lab[y];
    lab[y] = x;
    return true;
  };

  map < int, vector < pair < int, int > > > myedges;

  while(m--){
    int s, v, w;
    cin >> s >> v >> w;
    --s; --v;
    myedges[w].emplace_back(s, v);
  }

  int ans = 0;

  for(auto &p : myedges) {
    vector < bool > previous(p.second.size(), false);
    for(int i = 0; i < previous.size(); ++i) {
      auto v = p.second[i];
      if(find(v.first) != find(v.second)) previous[i] = true;
    }

    for(int i = 0; i < previous.size(); ++i) {
      auto v = p.second[i];
      if(!join(v.first, v.second) && previous[i]) ++ans;
    }
  }

  cout << ans;

  return 0;
}