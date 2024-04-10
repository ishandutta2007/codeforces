#include <bits/stdc++.h>
using namespace std;

struct tripple{
  int first, second, id;
  bool operator<(const tripple &a) const{
    return first < a.first;
  }
};

int main() {
  int t;
  cin >> t;
  for(int j = 0; j<t; j++){
    int n;
    cin >> n;
    vector<tripple> v(n);
    for(int i = 0; i<n; i++){
      cin >> v[i].first >> v[i].second;
      v[i].id = i;
    }
    int a[n];
    sort(v.begin(), v.end());
    for(int i = 0; i<n; i++){
      a[v[i].id] = i;
    }
    int arr[n];
    int prevx = v[0].second;
    int cur = 1;
    arr[0] = cur;
    bool work = false;
    for(int i = 1; i<n; i++){
      if(v[i].first > prevx){
        cur = 3-cur;
        work = true;
      }
      arr[i] = cur;
      prevx = max(prevx, v[i].second);
    }
    if(work){
      for(int i = 0; i<n; i++) cout << arr[a[i]] << " ";
    }
    else cout << -1;
    cout << endl;
  }
}