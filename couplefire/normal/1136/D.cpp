#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> arr(n);
  vector<int> appear(n+1, true);
  set<int> it;
  set<int> ps[n+1];
  for(int i = 0; i<n; i++){
    int t;
    scanf("%d", &t);
    arr[n-i-1] = t;
  }
  for(int i = 0; i<m; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    ps[b].insert(a);
  }
  it = ps[arr[0]];
  int t = 0;
  int cnt = 0;
  while(!it.empty() && cnt < n-1){
    if(appear[arr[cnt]]){
      set<int> temp;
      set_intersection(it.begin(), it.end(), ps[arr[cnt]].begin(), ps[arr[cnt]].end(), inserter(temp, temp.begin()));
      it = temp;
    }
    if(it.count(arr[cnt+1])){
      t++;
      appear[arr[cnt+1]] = false;
    }
    if(!appear[arr[cnt]]){
      cnt++;
      continue;
    }
    cnt++;
  }
  cout << t << endl;
}