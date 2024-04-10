#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> children[], int respect[], int bad[]){
  bool good = !children[node].empty();
  if(children[node].empty() && respect[node] == 1){
    bad[node] = 1;
  }
  for(int i = 0; i<children[node].size(); i++){
    if(!(respect[children[node][i]] && respect[node])) good = false;
    dfs(children[node][i], children, respect, bad);
  }
  if(good) bad[node] = 1;
}

int main() {
  int n;
  cin >> n;
  vector<int> children[n];
  vector<int> parents[n];
  int respect[n];
  int bad[n];
  int root;
  for(int i = 0; i<n; i++){
    bad[i] = 0;
    int temp, good;
    cin >> temp >> good;
    if(temp != -1){
      parents[i].push_back(temp-1);
      children[temp-1].push_back(i);
    }
    else root = i;
    if(good) respect[i] = 1;
    else respect[i] = 0;
  }
  dfs(root, children, respect, bad);
  vector<int> vec;
  for(int i = 0; i<n; i++){
    if(bad[i]) vec.push_back(i);
  }
  if(vec.empty()){
    cout << -1 << endl;
    return 0;
  }
  sort(vec.begin(), vec.end());
  for(auto i : vec){
    cout << i+1 << " ";
  }
  cout << endl;
}