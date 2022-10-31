#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;
  int n = str.size();
  int prefix[n+2];
  prefix[1] = 1;
  for(int i = 2; i<n+2; i++){
    if(i == n+1){
      prefix[i] = prefix[i-1];
      continue;
    }
    if(str[i-2] == str[i-1]) prefix[i] = prefix[i-1]+1;
    else prefix[i] = prefix[i-1];
  }
  int m;
  cin >> m;
  for(int i = 0; i<m; i++){
    int a, b;
    cin >> a >> b;
    cout << prefix[b] - prefix[a] << endl;
  }
}