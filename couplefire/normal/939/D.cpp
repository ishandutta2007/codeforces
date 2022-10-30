#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> siz;

int find_set(int v) {
  if (v == parent[v])
      return v;
  return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (siz[a] < siz[b]) swap(a, b);
    parent[b] = a;
    siz[a] += siz[b];
  }
}

int main() {
  int n;
  cin >> n;
  parent.resize(2*n);
  siz.resize(2*n);
  string a, b;
  cin >> a >> b;
  a += b;
  vector<char> s(a.begin(), a.end());
  unordered_map<char, int> m;
  for(int i = 0; i<2*n; i++){
    if(m.count(s[i]) == 0) m.insert(pair<char, int>(s[i], i));
    parent[i] = m[s[i]];
    siz[i] = 1;
  }
  vector<pair<char, char>> re;
  int ans = 0;
  for(int i = 0; i<n; i++){
    s[i] = s[find_set(i)];
    s[i+n] = s[find_set(i+n)];
    if(s[i] != s[i+n]){
      re.push_back(pair<char, char>(s[i], s[i+n]));
      union_sets(i, i+n);
      s[i] = s[find_set(i)];
      s[i+n] = s[find_set(i+n)];
      ans++;
    }
  }
  cout << ans << endl;
  for(auto i : re){
    cout << i.first << " " << i.second << endl;
  }
}