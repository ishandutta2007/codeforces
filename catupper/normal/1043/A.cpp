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
Int a[21600];
Int n;
bool ok(int k){
  int get = 0;
  for(int i = 0;i < n;i++){
    if(k < a[i])return false;
    get += k - a[i];
    get -= a[i];
  }
  return get > 0;
}


int main(){
  cin >> n;
  for(int i = 0;i < n;i++)cin >> a[i];
  for(int k = 1;k <= 1000;k++){
    if(ok(k)){
      cout  <<  k << endl;
      return 0;
    }
  }
  return 0;
  
}