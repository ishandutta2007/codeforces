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
string str;
bool big(int x, int y){
  char c;
  cout << "? " << x << " " << y << endl;
  cin >> c;
  if(c == 'e')exit(0);
  return c == 'x';
}

void game(){
  Int top = 1;
  while(top <= 1000000000 && big(top*2, top))top *= 2;
  if(top > 1000000000){
    cout << "! 1" << endl;
    return;
  }
  Int bottom = 0;
  while(top - bottom > 1){
    Int mid = (top + bottom) / 2;
    if(big(mid*2, mid))bottom = mid;
    else top = mid;
  }
  Int ans = 2*top-1;
  if(big(ans, ans+1))ans++;
  cout << "! " << ans << endl;
  return;
}

int main(){
  while(true){
    cin >> str;
    if(str == "end")break;
    game();
  }
  return 0;
}