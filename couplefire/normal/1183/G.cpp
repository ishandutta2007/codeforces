#include <bits/stdc++.h>
using namespace std;

int main() {
  int q;
  cin >> q;
  while(q--){
    map<int, pair<int, int>> mp;
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
      int a, b;
      cin >> a >> b;
      mp[a].first++;
      mp[a].second += b;
    }
    int total = 0;
    int keep = 0;
    priority_queue<pair<int, int>> pq;
    for(auto i:mp) pq.push(i.second);
    int cnt = pq.top().first;
    while(cnt > 0 && !pq.empty()){
      if(pq.top().first == cnt){
        total += cnt;
        keep += min(cnt, pq.top().second);
        pq.pop();
        cnt--;
      }
      else if(pq.top().first < cnt){
        cnt = pq.top().first;
        total += cnt;
        keep += min(cnt, pq.top().second);
        pq.pop();
        cnt--;
      }
      else{
        pq.push(make_pair(cnt, min(cnt, pq.top().second)));
        pq.pop();
      }
    }
    cout << total << " " << keep << endl;
  }
}