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
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
typedef long long ll;
using namespace std;

int main(){

  string s;
  cin >> s;
  
  REP(i,s.size()/2){
    if(s[i] != s[s.size()-1-i]){
      cout << s.size() << endl;
      return 0;
    }
  }
  
  char c = s[0];
  REP(i,s.size()-1){
    if(c != s[i+1]){
      cout << s.size()-1 << endl;
      return 0;
    }
    c = s[i+1];
  }
  
    cout << 0 << endl;

 return 0;
}