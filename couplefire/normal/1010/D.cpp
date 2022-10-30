#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> type; // in:0, not:1, and:2, or:3, xor:4
vector<int> val;
vector<vector<int>> child;
vector<int> inputs;
map<int, int> mp;
int stable = 0;
int ans;

int dfs(int i){
  if(type[i] == 0) return val[i];
  else if(type[i] == 1){
    val[i] = 1-dfs(child[i][0]);
    return val[i];
  }
  else if(type[i] == 2){
    val[i] = dfs(child[i][0]) & dfs(child[i][1]);
    return val[i];
  }
  else if(type[i] == 3){
    val[i] = dfs(child[i][0]) | dfs(child[i][1]);
    return val[i];
  }
  val[i] = dfs(child[i][0]) ^ dfs(child[i][1]);
  return val[i];
}

void ddfs(int i){
  if(type[i] == 0){
    if(stable == 0) mp[i] = !ans;
    else mp[i] = ans;
  }
  else if(type[i] == 1) ddfs(child[i][0]);
  else if(type[i] == 2){
    if(val[child[i][1]] == 0) stable++;
    ddfs(child[i][0]);
    if(val[child[i][1]] == 0) stable--;
    if(val[child[i][0]] == 0) stable++;
    ddfs(child[i][1]);
    if(val[child[i][0]] == 0) stable--;
  }
  else if(type[i] == 3){
    if(val[child[i][1]] == 1) stable++;
    ddfs(child[i][0]);
    if(val[child[i][1]] == 1) stable--;
    if(val[child[i][0]] == 1) stable++;
    ddfs(child[i][1]);
    if(val[child[i][0]] == 1) stable--;
  }
  else{
    ddfs(child[i][0]);
    ddfs(child[i][1]);
  }
}

int main() {
  cin >> n;
  type.resize(n);
  val.resize(n);
  child.resize(n);
  for(int i = 0; i<n; i++){
    string s; cin >> s;
    child[i].resize(2);
    if(s == "IN"){
      int a; cin >> a;
      type[i] = 0;
      val[i] = a;
      inputs.push_back(i);
    }
    else if(s == "NOT"){
      int a; cin >> a;
      --a;
      type[i] = 1;
      child[i][0] = a;
    }
    else{
      int a, b; cin >> a >> b;
      --a; --b;
      child[i][0] = a;
      child[i][1] = b;
    }
    if(s == "AND") type[i] = 2;
    else if(s == "OR") type[i] = 3;
    else if(s == "XOR") type[i] = 4;
  }
  ans = dfs(0);
  ddfs(0);
  for(auto i : inputs) cout << mp[i];
  cout << endl;
}