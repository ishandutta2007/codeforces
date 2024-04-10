#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> qs;
int n, t;

bool check(int num){
  int temp = 0;
  int cnt = 0;
  for(auto i : qs){
    if(i.second < num) continue;
    if(cnt == num) break;
    temp += i.first;
    if(temp > t) return false;
    cnt++;
  }
  if(cnt < num) return false;
  return true;
}

int main() {
  scanf("%d %d", &n, &t);
  map<pair<int, int>, stack<int>> m;
  for(int i = 0; i<n; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    qs.push_back(make_pair(b, a));
    m[make_pair(b, a)].push(i+1);
  }
  sort(qs.begin(), qs.end());
  int lo = 0, hi = qs.size();
  while(lo < hi){
    int mid = lo+(hi-lo+1)/2;
    if(!check(mid)) hi = mid-1;
    else lo = mid;
  }
  cout << lo << endl;
  cout << lo << endl;
  int cnt = 0;
  for(auto i : qs){
    if(i.second < lo) continue;
    if(cnt == lo) break;
    printf("%d ", m[i].top());
    m[i].pop();
    cnt++;
  }
  cout << endl;
}