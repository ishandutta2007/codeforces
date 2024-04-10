#include <bits/stdc++.h>
using namespace std;

int d = 0;

int fs(int v, vector<int> &parent){
  if(parent[v] == v) return v;
  return parent[v] = fs(parent[v], parent);
}

void us(int a, int b, vector<queue<int>> &q, vector<int> &parent){
  int aa = fs(a, parent);
  int bb = fs(b, parent);
  if(aa == bb) return;
  if(q[aa].size() < q[bb].size()){
    d = bb;
    parent[aa] = parent[bb];
    while(!q[aa].empty()){
      int d  = q[aa].front();
      q[aa].pop();
      q[bb].push(d);
    }
  }
  else{
    d = aa;
    parent[bb] = parent[aa];
    while(!q[bb].empty()){
      int d  = q[bb].front();
      q[bb].pop();
      q[aa].push(d);
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<queue<int>> q(n);
  vector<int> parent(n);
  for(int i = 0; i<n; i++){
    q[i].push(i);
    parent[i] = i;
  }
  for(int i = 0; i<n-1; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    us(a, b, q, parent);
  }
  while(!q[d].empty()){
    cout << q[d].front()+1 << " ";
    q[d].pop();
  }
  cout << endl;
}