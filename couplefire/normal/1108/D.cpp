#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string str;
  cin >> n;
  cin >> str;
  char prev = 'X';
  bool consec = true;
  int cons[n];
  int cur = 0;
  for(int i = 0; i<n; i++){
    cons[i] = 0;
    if(str[i] != prev){
      consec = true;
    }
    else{
      consec = false;
    }
    if(consec){
      cur = i;
      cons[cur]++;
    }
    else{
      cons[cur]++;
    }
    prev = str[i];
  }
  int num = 0;
  for(int i = 0; i<n; i++){
    if(cons[i] > 1){
      if(cons[i] % 2 == 1){
        for(int k = i+1; k<i+cons[i]; k+=2){
          num++;
          str[k] = (str[k-1] == 'R') ? 'G' : 'R';
        }
      }
      else{
        num++;
        if(i == 0) str[i] = (str[i+1] == 'R') ? 'G' : 'R';
        else{
          vector<char> vec = {'R', 'G', 'B'};
          vec.erase(remove(vec.begin(), vec.end(), str[i+1]), vec.end());
          vec.erase(remove(vec.begin(), vec.end(), str[i-1]), vec.end());
          str[i] = vec[0];
        }
        for(int k = i+2; k<i+cons[i]; k+= 2){
          num++;
          str[k] = (str[k-1] == 'R') ? 'G' : 'R';
        }
      }
    }
  }
  cout << num << endl;
  cout << str << endl;
}