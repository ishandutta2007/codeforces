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
  
  map <string,string> stone;
  

  stone["purple"] = "Power";
    stone["green"] = "Time";
  stone["blue"]  = "Space";
  stone["orange"] =  "Soul";
  stone["red"] = "Reality";
  stone["yellow"] = "Mind";

  
  REP(i,n){
   string s;
    cin >> s;
    stone.erase(s);
  }
  
  cout << 6 - n << endl;
  ITR(itr,stone)
    cout << itr->second << endl; 

  
  return 0;
}