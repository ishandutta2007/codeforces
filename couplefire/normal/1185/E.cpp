#include <bits/stdc++.h>
using namespace std;

struct snake{
  int dir = -2;
  pair<int, int> start;
  int len;
};

int main() {
  int t;
  cin >> t;
  for(int j = 0; j<t; j++){
    int n, m;
    cin >> n >> m;
    int grid[n][m];
    int empt[n][m];
    snake arr[27]; 
    bool work = true;
    for(int i = 0; i < n; i++){
      string s;
      cin >> s;
      for(int k = 0; k < m; k++){
        empt[i][k] = 0;
        if(s[k] == '.'){
          grid[i][k] = 0;
          continue;
        }
        else grid[i][k] = s[k]+1-'a';
        int te = grid[i][k];
        if(arr[te].dir == -2){
          arr[te].dir = -1;
          arr[te].start = make_pair(i, k);
          arr[te].len = 1;
        }
        else if(arr[te].dir == -1){
          if(i == arr[te].start.first){
            arr[te].dir = 0;
            arr[te].len = k - arr[te].start.second+1;
          }
          else if(k == arr[te].start.second){
            arr[te].dir = 1;
            arr[te].len = i - arr[te].start.first+1;
          }
          else work = false;
        }
        else{
          if(arr[te].dir == 1){
            if(arr[te].start.second == k){
              arr[te].len = i - arr[te].start.first+1;
            }
            else work = false;
          }
          else{
            if(arr[te].start.first == i){
              arr[te].len = k - arr[te].start.second+1;
            }
            else work = false;
          }
        }
      }
    }
    if(work == false){
      printf("NO\n");
      continue;
    }
    int high = 0;
    int a1, a2, a3, a4;
    for(int i = 1; i<=26; i++){
      if(arr[i].dir == -2) continue;
      else{
        //printf("%d %d %d %d %d\n", i, arr[i].dir, arr[i].start.first, arr[i].start.second, arr[i].len);
        high = max(high, i);
        a1 = arr[i].start.first+1;
        a2 = arr[i].start.second +1;
        if(arr[i].dir == -1) empt[arr[i].start.first][arr[i].start.second] = i;
        else if(arr[i].dir == 1){
          for(int k = arr[i].start.first; k< arr[i].len+arr[i].start.first; k++){
            empt[k][arr[i].start.second] = i;
          }
        }
        else if(arr[i].dir == 0){
          for(int k = arr[i].start.second; k< arr[i].len+arr[i].start.second; k++){
            empt[arr[i].start.first][k] = i;
          }
        }
      }
    }
    for(int i = 0; i<n; i++){
      for(int k = 0; k<m; k++){
        //cout << empt[i][k];
        if(grid[i][k] != empt[i][k]) work = false;
      }
      //cout << endl;
    }
    if(!work){
      printf("NO\n");
      continue;
    }
    printf("YES\n");
    printf("%d\n", high);
    for(int i = 1; i<=high; i++){
      if(arr[i].dir == -1) printf("%d %d %d %d\n", arr[i].start.first+1, arr[i].start.second+1, arr[i].start.first+1, arr[i].start.second+1);
      else if(arr[i].dir == 1) printf("%d %d %d %d\n", arr[i].start.first+1, arr[i].start.second+1, arr[i].start.first+arr[i].len, arr[i].start.second+1);
      else if(arr[i].dir == 0) printf("%d %d %d %d\n", arr[i].start.first+1, arr[i].start.second+1, arr[i].start.first+1, arr[i].start.second+arr[i].len);
      else printf("%d %d %d %d\n", a1, a2, a1, a2);
      
    }
  }
}