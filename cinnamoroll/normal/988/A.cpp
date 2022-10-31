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
  
  int k,n;
  cin >> n >> k;
  
  int N[110] = {};
  int num[n];
  REP(i,n){
    cin >> num[i];
    N[num[i]]++;
  }
  
  int c = 0;
  REP(i,101){
  if(N[i] != 0) c++;
  }
  
  if(c < k) cout << "NO" << endl;
           
  else{
    cout << "YES" << endl;
    c = 0;int A[101] = {};
    REP(i,n){
      if(A[num[i]] == 0) {
        cout << i+1 << " ";
        c++;
        A[num[i]]++;
                 }
                  if(c == k) break;
    }
  }
  
  
  return 0;
}