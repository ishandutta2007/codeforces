#include<iostream>
#include <stdio.h>
#include<string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdint>
#include <queue> 
#include <map>
#include <set>
#define MOD 1000000007
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n)  FOR(i,0,n)
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
typedef long long ll;
using namespace std;



int main(){
  
  int n;
  cin >> n;
  
  int num[n];
  REP(i,n) cin >> num[i];
  
  int count = 0;
  REP(i,n){
    while(num[i] != i+1){
      swap(num[i],num[num[i]-1]);
      count++;
    }
  }
    
    if((n - count) % 2 == 0) cout << "Petr" << endl;
    else   cout << "Um_nik" << endl;
    
  return 0;
}