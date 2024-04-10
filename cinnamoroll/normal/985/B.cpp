#include<iostream>
#include <stdio.h>
#include<string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdint>
#include <map>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(){

  int n,m;
  cin >> n >> m;

  char lamp[2010][2010];
  int num[2010] = {};
  
  for(int i = 0; i<n; i++){
    for(int j = 0; j<m; j++){
      cin >> lamp[i][j];
      if(lamp[i][j] == '1') num[j]++;
    }
  }
  
  for(int i = 0; i<n; i++){
    int c = 1;
    for(int j = 0; j<m; j++){
      if(lamp[i][j] == '1' && num[j] == 1) c = 0;
    }
     if(c == 1){
       cout << "YES" << endl; return 0;
     }
   }
cout << "NO"  << endl;
  
return 0;
}