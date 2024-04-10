#include <bits/stdc++.h>
using namespace std;

int findu(int i, int parent[]){
  if(parent[parent[i]] != parent[i]){
    parent[i] = findu(parent[i], parent);
  }
  return parent[i];
}

void Union(int a, int b, int parent[], int size[]){
  int parent_a = findu(a, parent);
  int parent_b = findu(b, parent);
  if(parent_a == parent_b) return;
  if(size[parent_a] >= size[parent_b]){
    size[parent_a] += size[parent_b];
    parent[parent_b] = parent[parent_a];
  }
  else{
    size[parent_b] += size[parent_a];
    parent[parent_a] = parent[parent_b];
  }
}

int main() {
  int n;
  int m;
  cin >> n >> m;
  int size[n];
  int parent[n];
  for(int i = 0; i<n; i++){
    parent[i] = i;
    size[i] = 1;
  }
  for(int i = 0; i<m; i++){
    int prev = -1;
    int k;
    cin >> k;
    for(int j = 0; j<k; j++){
      int temp;
      cin >> temp;
      temp--;
      if(prev != -1){
        Union(prev, temp, parent, size);
      }
      prev = temp;
    }
  }
  for(int i = 0; i<n; i++){
    int temp = findu(i, parent);
    cout << size[temp] << " ";
  }
  cout << endl;
}