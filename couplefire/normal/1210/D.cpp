#include <bits/stdc++.h>
using namespace std;
#define MAXN 100007

vector<long long> adj[MAXN][2]; // 0: in, 1: out
long long ecnt[MAXN][2] = {0};
long long ss[MAXN] = {0};
long long sum = 0;
long long n, m, q;

int main() {
  cin >> n >> m;
  for(long long i = 0; i<m; i++){
    long long a, b; cin >> a >> b;
    --a; --b;
    if(a > b) swap(a, b);
    adj[a][0].push_back(b);
    adj[b][1].push_back(a);
    ecnt[a][0]++;
    ecnt[b][1]++;
  }
  for(long long i = 0; i<n; i++){
    ss[i] = ecnt[i][0]*ecnt[i][1];
    sum += ss[i];
  }
  cin >> q;
  cout << sum << endl;
  while(q--){
    long long v; cin >> v; --v;
    sum -= ss[v];
    ss[v] = 0;
    ecnt[v][1] += ecnt[v][0];
    ecnt[v][0] = 0;
    for(auto i : adj[v][0]){
      sum -= ecnt[i][0]*ecnt[i][1];
      ecnt[i][1]--;
      ecnt[i][0]++;
      sum += ecnt[i][0]*ecnt[i][1];
      ss[i] = ecnt[i][0]*ecnt[i][1];
      adj[i][0].push_back(v);
    }
    adj[v][0].clear();
    cout << sum << endl;
  }
}