#include <bits/stdc++.h>

using namespace std;

const int N = 3 * 100000 + 5;

int n, m, d, viz[N];

vector <int> g[N];
vector <int> id[N];

queue <int> q;

set <int> ans, transfer;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>m>>d;
  for (int i = 1; i <= m; i ++) {
    int nod;
    cin>>nod;
    q.push(nod);
    viz[nod] = 1;
  }
  for (int i = 1; i < n; i ++) {
    int a, b;
    cin>>a>>b;
    g[a].push_back(b);
    id[a].push_back(i);
    g[b].push_back(a);
    id[b].push_back(i);
  }
  while (!q.empty()) {
    int nod = q.front();
    q.pop();
    for (int i = 0; i < g[nod].size(); i ++) {
      int nou = g[nod][i];
      if (viz[nou] == 0) {
        viz[nou] = 1;
        q.push(nou);
        transfer.insert(id[nod][i]);
      }
      else {
        ans.insert(id[nod][i]);
      }
    }
  }
  for (auto x: transfer) {
    ans.erase(x);
  }
  cout<<ans.size()<<"\n";
  for (auto x: ans) {
    cout<<x<<" ";
  }
  cout<<"\n";
  return 0;
}
/**

**/