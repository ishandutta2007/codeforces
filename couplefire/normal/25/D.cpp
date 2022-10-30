#include <bits/stdc++.h>
using namespace std;

int re = 0;
stack<pair<int, int>> dump;
vector<int> parent;
vector<int> siz;

void ms(int n){
  parent.resize(n);
  siz.resize(n);
  for(int i = 0; i<n; i++){
    parent[i] = i;
    siz[i] = 1;
  }
}

int fs(int v){
  if(parent[v] == v) return v;
  return parent[v] = fs(parent[v]);
}

void us(int a, int b){
  int a_ = fs(a);
  int b_ = fs(b);
  if(a_ == b_){
    re++;
    dump.push(pair<int, int>(a, b));
    return;
  }
  if(siz[a_] < siz[b_]) swap(a_, b_);
  parent[b_] = parent[a_];
  siz[a_] += siz[b_];
}

int main() {
  int n;
  cin >> n;
  ms(n);
  for(int i = 0; i<n-1; i++){
    int a, b;
    cin >> a >> b;
    --a; --b;
    us(a, b);
  }
  cout << re << endl;
  for(int i = 1; i < n; i++){
    if(fs(i) != fs(i-1)){
      us(i, i-1);
      cout << dump.top().first+1 << " " << dump.top().second+1 << " ";
      dump.pop();
      cout << i << " " << i+1 << endl;
    }
  }
}