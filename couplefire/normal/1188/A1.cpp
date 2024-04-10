#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int adj[n];
  memset(adj, 0, n*sizeof(int));

  for(int i = 0; i<n-1; i++){
    int a, b;
    cin >> a >> b;
    adj[a-1]++;
    adj[b-1]++;
  }
  for(int i  =0; i<n; i++){
    if(adj[i] == 2){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}