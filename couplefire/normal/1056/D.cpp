#include <bits/stdc++.h>
using namespace std;

void dfs(int c, map<int, int> &m, vector<int> &v, vector<int> children[]){
  if(children[c].size() == 0) v[c] = 1;
  for(int i = 0; i<children[c].size(); i++){
    dfs(children[c][i], m, v, children);
    v[c] += v[children[c][i]];
  }
  if(m.count(v[c]) == 0) m.insert(pair<int, int>(v[c], 1));
  else m[v[c]]++;
}

int main() {
  int n;
  cin >> n;
  vector<int> children[n];
  for(int i = 0; i<n-1; i++){
    int a;
    cin >> a;
    children[a-1].push_back(i+1);
  }
  map<int, int> m;
  vector<int> v(n, 0);
  dfs(0, m, v, children);
  int s = 0;
  for(auto i : m){
    s = i.first;
    for(int k = 0; k<i.second; k++) cout << s << " ";
  }
  cout << endl;
}