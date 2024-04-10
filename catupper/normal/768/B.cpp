#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long Int;
Int lastsize(Int n){
  if(n <= 1)return 1;
  return 1 + 2 * lastsize(n/2);
}

Int solve(Int n, Int l, Int r){
  if(n <= 1)return n;
  Int ls = lastsize(n);
  Int res = 0;
  if(l <= (ls/2 + 1) && (ls/2 + 1) <= r){
    res += n % 2;
  }

  if(l < (ls/2 + 1)){
    res += solve(n / 2, l, min(r, ls/2));
  }
  if((ls / 2 + 1) < r){
    res += solve(n / 2, max(1LL, l - (ls / 2 + 1)), r - (ls / 2 + 1));
  }
  return res;
}
int main(){
  Int n, l, r;
  cin >> n >> l >> r;
  cout << solve(n, l, r) << endl;
  return 0;
}