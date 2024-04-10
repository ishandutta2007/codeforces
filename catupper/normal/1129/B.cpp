#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

Int hoge = 500251;
Int k;
int main(){
  for(int k = 0;k <= 10000;k++){
    cin >> k;
       Int kk = k;
    Int b = 1999;
  Int c = k % b;
  c = (b - c) % b;
  Int a = (k + c) / b + 1 + b + c;
  cout << b + 1 << endl;
   for(int i = 0;i <= b;i++){
    if(i)cout << " ";
    if(i < b-2)cout << 0;
    if(i == b-2)cout << -b+1;
    else if(i == b-1)cout << -1-c;
    else if(i == b)cout << a ;
  }
  cout << endl;

  Int ans =a;
  ans = max(ans, (a-c-1)*2);
  ans = max(ans, (a-b-c)*(b+1));
  //  cout << ans << " " << a-b-c << " " << b +1  << endl;
  //  if(ans-a != kk || kk < 10)cout << ans - a << " " << kk << endl;
    break;
  k = kk;
  }
  return 0;
}