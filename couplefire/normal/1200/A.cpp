#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  set<int> room;
  for(int i = 0; i<10; i++) room.insert(i);
  string s;
  cin >> s;
  int visited[10];
  fill(visited, visited+10, 0);
  for(int i = 0; i<n; i++){
    char t = s[i];
    if(t == 'L'){
      int k = *room.begin();
      visited[k] = 1;
      room.erase(room.begin());
    }
    else if(t == 'R'){
      int k = *(--room.end());
      visited[k] = 1;
      room.erase(--room.end());
    }
    else{
      int k = t-'0';
      visited[k] = 0;
      room.insert(k);
    }
  }
  for(int i = 0; i<10; i++){
    if(visited[i] == 1) cout << 1;
    else cout <<  0;
  }
  cout << endl;
}