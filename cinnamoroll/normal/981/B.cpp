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

  map <int,ll>mp;
  
  int n;
  cin >> n;
  
  REP(i,n){
    int a; ll v;
    cin >> a >> v;
   mp.insert({a,v});
  }
  
  int m;
  cin >> m;
  
  REP(i,m){
    int b; ll v;
    cin >> b >> v;
    mp[b] = max(v,mp[b]);
  }
  
  ll ans = 0;
    for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
        ans += itr->second;
    }
  
  cout << ans << endl;
  
  return 0;
}