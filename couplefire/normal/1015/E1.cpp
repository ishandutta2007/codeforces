#include <bits/stdc++.h>
using namespace std;
int n, m;
char grid[1001][1001];
int visited1[1001][1001] = {0};
int visited2[1001][1001] = {0};
int ac[1001][1001] = {0};
int dph[1001][1001] = {0};
int dpv[1001][1001] = {0};

void calcdph(){
  for(int i = 0; i<1001; i++){
    vector<pair<int, int>> arr;
    int p = -1;
    for(int k = 0; k<1001; k++){
      if(grid[i][k] == '.'){
        if(k>0 && grid[i][k-1] != '.') arr.push_back(make_pair(p+1, k-1));
        p = k;
      }
    }
    for(auto v : arr){
      int b = v.first, e = v.second;
      for(int k = b; k<= e; k++){
        dph[i][k] = min(abs(k-b), abs(e-k));
      }
    }
  }
}

void calcdpv(){
  for(int i = 0; i<1001; i++){
    vector<pair<int, int>> arr;
    int p = -1;
    for(int k = 0; k<1001; k++){
      if(grid[k][i] == '.'){
        if(k > 0 && grid[k-1][i] != '.') arr.push_back(make_pair(p+1, k-1));
        p = k;
      }
    }
    for(auto v : arr){
      int b = v.first, e = v.second;
      for(int k = b; k<= e; k++){
        dpv[k][i] = min(abs(k-b), abs(e-k));
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for(int i = 0; i<1001; i++){
    for(int k = 0; k<1001; k++) grid[i][k] = '.';
  }
  for(int i = 0; i<n; i++){
    string s;
    cin >> s;
    for(int k = 0; k<m; k++){
      grid[i][k] = s[k];
    }
  }
  calcdph();
  calcdpv();
  vector<vector<int>> stars;
  int st = 0;
  for(int i = 0; i<1001; i++){
    for(int k = 0; k<1001; k++){
      int mi = min(dph[i][k], dpv[i][k]);
      if(mi <= 0) continue;
      visited1[i][k+mi+1]--;
      visited1[i][k-mi]++;
      visited2[i+mi+1][k]--;
      visited2[i-mi][k]++;
      stars.push_back({i+1, k+1, mi});
      st++;
    }
  }
  for(int i = 0; i<1001; i++){
    int num = 0;
    for(int k = 0; k<1001; k++){
      num += visited1[i][k];
      if(num > 0){
        ac[i][k] = 1;
      }
    }
  }
  for(int i = 0; i<1001; i++){
    int num = 0;
    for(int k = 0; k<1001; k++){
      num += visited2[k][i];
      if(num > 0) ac[k][i] = 1;
    }
  }
  for(int i = 0; i<1001; i++){
    for(int k = 0; k<1001; k++){
      if(ac[i][k] == 0 && grid[i][k] == '*'){
        cout << -1 << endl;
        return 0;
      }
    }
  }
  cout << st << endl;
  for(auto k : stars){
    cout << k[0] << " " << k[1] << " " << k[2] << endl;
  }
}