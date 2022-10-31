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
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n)  FOR(i,0,n)
typedef long long ll;

int main(){

  int n;
  cin >> n;

  int p[100];
  REP(i,n/2) cin >> p[i];

  sort(p,p+n/2);
  
  int B = 0;
  REP(i,n/2){
    B += abs(p[i] - 2*(i+1));
  }
  
  int W = 0;
    REP(i,n/2){
    W += abs(p[i] - (2*i + 1));
  }
  
  cout << min(B,W) << endl;
  
return 0;
}