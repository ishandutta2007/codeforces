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
Int cnt;
bool ng[216000];
Int conv[216000];
Int a[10][216000];
Int n, m;
Int calc(Int x){
  return x * (x + 1) / 2;
}

int main(){
  cin >> n >> m;
  for(int i = 0;i < m;i++){
    for(int j = 0;j < n;j++){
      scanf("%lld", &a[i][j]);
    }
  }

  for(int i = 0;i < n;i++){
    conv[a[0][i]] = i;
  }
  for(int i = 0;i < m;i++){
    for(int j = 0;j < n;j++){
      a[i][j] = conv[a[i][j]];
      if(j && a[i][j-1] + 1 != a[i][j]){
	ng[a[i][j-1]] = true;
      }
    }
    ng[a[i][n-1]] = true;
  }
  int last = -1;
  ng[n-1] = true;
  for(int i = 0;i < n;i++){
    if(!ng[i])continue;
    cnt += calc(i - last);
    last = i;
    //    cout << last << endl;
  }
  printf("%lld\n", cnt);

  
  return 0;
}