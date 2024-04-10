#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m; cin >> n >> m;
  priority_queue<pair<int, int>> pq[n-1];
  vector<int> sum(n-1, 0);
  for(int k = 0; k<m; k++){
    vector<int> v(n);
    for(int i = 0; i<n; i++) cin >> v[i];
    for(int i = 0; i<n-1; i++){
      pq[i].push({v[n-1]-v[i], k});
      sum[i] += v[n-1]-v[i];
    }
  }
  int mi = INT_MAX;
  vector<int> vv;
  for(int i = 0; i<n-1; i++){
    int num = 0;
    vector<int> tv;
    while(!pq[i].empty() && sum[i] > 0){
      sum[i] -= pq[i].top().first;
      tv.push_back(pq[i].top().second);
      pq[i].pop();
      num++;
    }
    if(num < mi){
      mi = num; 
      vv = tv;
    }
  }
  cout << mi << endl;
  for(auto i : vv) cout << i+1 << " ";
  cout << endl;
}