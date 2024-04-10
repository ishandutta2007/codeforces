#include <bits/stdc++.h>
using namespace std;

long long totalsum = 0;
long long *parent;
vector<long long> *children;
long long *sum;
bool work = true;

void dfs(long long i, long long s, bool single);

int main() {
  cout << fixed;
  long long n;
  cin >> n;
  parent = new long long[n];
  parent[0] = -1;
  children = new vector<long long>[n];
  sum = new long long[n];
  for(long long i = 0; i<n-1; i++){
    cin >> parent[i+1];
    parent[i+1]--;
    children[parent[i+1]].push_back(i+1);
  }
  for(long long i = 0; i<n; i++){
    cin >> sum[i];
  }
  dfs(0, 0, false);
  if(work) cout << totalsum << endl;
  else cout << -1 << endl;
}

void dfs(long long i, long long s, bool single){
  if(work == false) return;
  if(sum[i] != -1){
    if(s > sum[i]){
      work = false;
      return;
    }
    totalsum += sum[i] - s;
    s = sum[i];
  }
  if(single && children[i].size() != 0){
    long long mi = LONG_LONG_MAX;
    for(long long k = 0; k<children[i].size(); k++) mi = min(mi, sum[children[i][k]]);
    totalsum -= (mi-s)*(children[i].size()-1);
  }
  for(long long k = 0; k<children[i].size(); k++){
    dfs(children[i][k], s, sum[i] != -1);
  }
}