#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n;
string words[105];

int out[26][26];
int in[26];

typedef pair<int, int> pii;
set<pii> Q;
string topo() {
  string ans = "";
  for(int i = 0; i < 26; ++i) {
    Q.insert(pii(in[i], i));
  }
  while(!Q.empty()) {
    if(Q.begin()->first != 0)
      return "Impossible";
    pii p = *Q.begin();
    Q.erase(Q.begin());
    int v = p.second;
    ans += char(v + 'a');
    for(int i = 0; i < 26; ++i) {
      if(out[v][i] > 0) {
        Q.erase(pii(in[i], i));
        in[i] -= out[v][i];
        Q.insert(pii(in[i], i));
      }
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i < 26; ++i) {
    fill(out[i], out[i]+26, 0);
    in[i] = 0;
  }
  for(int i = 0; i < n; ++i)
    cin >> words[i];
  for(int i = 1; i < n; ++i) {
    int j = 0;
    while(j < words[i].size() && j < words[i-1].size() && words[i][j] == words[i-1][j])
      ++j;
    if(j == words[i-1].size())
      continue;
    if(j == words[i].size()) {
      cout << "Impossible\n";
      return 0;
    }
    int a = words[i-1][j]-'a';
    int b = words[i][j]-'a';
    ++out[a][b];
    ++in[b];
  }
  cout << topo() << "\n";

  return 0;
}