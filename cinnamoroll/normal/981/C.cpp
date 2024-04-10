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

  int n;
  cin >> n;
  
  vector<int> Node[n+1],l;
  
  REP(i,n-1){
    int a,b;
    cin >> a >> b;
    Node[a].push_back(b);
    Node[b].push_back(a);
  }
  
  int check = 0,top = 0;
  REP(i,n){
    int deg = Node[i+1].size();  // 
    if(deg == 1) l.push_back(i+1); // 	
    if(deg >= 3){
      if(check == 1) {
        cout << "No" << endl;
        return 0;
      }
      else {
        check = 1;
        top = i+1;   //
      }
    }
  }
  
  cout << "Yes" << endl;
  
  if(top == 0){ //
    top = l.back();
    l.pop_back();
  }
  
  cout << l.size() << endl;
  
  REP(i,l.size())
    cout << top << " " << l[i] << endl;
  
  return 0;
}