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
  
  int s[n],c[n];
  
  REP(i,n) cin >> s[i];
  REP(i,n) cin >> c[i];
  
  int two[n];
  REP(i,n) two[i] = MOD;

  //index i
  REP(i,n-2){
    FOR(j,i+1,n-1){
      if(s[i] < s[j])
        two[j] = min(two[j],c[i]+c[j]);
    }
  }
  
  REP(i,n-1){
    int Min = MOD,flag = 0;
    FOR(j,i+1,n){
      if(s[i] < s[j]) Min = min(Min,c[j]);
      flag = 1;
    }
    two[i] += Min;
    if(flag == 0) two[i] = MOD;
  }
  
  sort(two,two + n);
  
  if(two[0] == MOD) cout << -1 << endl;
  else cout << two[0] << endl;
  
  return 0;
}