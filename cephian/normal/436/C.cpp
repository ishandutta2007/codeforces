#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> state;

int G[1005][1005];
bool visit[1005];
int n, m, k, w, bound;
vector<string> board;
vector<pii> store;

int dist(int i, int j) {
  int ans = 0;
  for(int a = 0; a < board[i].size(); ++a)
    ans += board[i][a] != board[j][a];
  return ans;
}

priority_queue<state, vector<state>, greater<state> > Q;

int mst(int i) {
  Q.push(state(0, pii(-1, i)));
  int ans = 0;
  while(!Q.empty()) {
    state p = Q.top();
    Q.pop();
    int v = p.second.second;
    if(visit[v]) continue;
    visit[v] = 1;
    ans += p.first;
    store.push_back(pii(v+1, p.second.first+1));
    for(int i = 0; i < k; ++i) {
      if(visit[i] || G[v][i] > bound) continue;
      Q.push(state(G[v][i], pii(v, i)));
    }
  }
  return ans;
}

int main() {
  cin >>n>>m>>k>>w;
  bound = n*m;
  for(int i = 0; i < k; ++i) {
    string g = "";
    for(int j = 0; j < n; ++j) {
      string g2;
      cin >> g2;
      g+=g2;
    }
    board.push_back(g);
  }
  for(int i = 0; i < k; ++i)
    for(int j = 0; j < k; ++j)
      G[i][j] = dist(i, j)*w;
  fill(visit, visit+k, 0);
  int ans = 0;
  for(int i = 0; i < k; ++i) {
    // cout << i << " : " << visit[i] << endl;
    if(visit[i]) continue;
    ans += mst(i) + bound;
  }
  cout << ans << endl;
  for(int i = 0; i < store.size(); ++i) {
    cout << store[i].first << " " << store[i].second << endl;
  }
  return 0;
}