#include <bits/stdc++.h>
using namespace std;
int n;
int num = 0;

int main() {
  cin >> n;
  int pre[n+1];
  pre[0] = 0;
  vector<int> all;
  for(int i = 0; i<n; i++){
    int a;
    cin >> a;
    pre[i+1] = pre[i]+a;
  }
  for(int i = 1; i<=n; i++){
    for(int k = 0; k<i; k++){
      all.push_back(pre[i]-pre[k]);
    }
  }
  vector<pair<int, int>> op;
  for(auto i : all){
    int cnt = 0;
    vector<pair<int, int>> top;
    for(int k = 0; k<n;){
      map<int, int> m;
      m.insert(make_pair(pre[k], k));
      bool findone = false;
      while(!findone && k < n){
        int t = pre[k+1]-i;
        if(m.count(t)){
          findone = true;
          cnt++;
          top.push_back(make_pair(k+1, m[t]+1));
        }
        m.insert(make_pair(pre[k+1], k+1));
        k++;
      }
    }
    if(cnt > num){
      num = cnt;
      op = top;
    }
  }
  cout << num << endl;
  for(auto v : op) cout << v.second << " " << v.first << endl;
}