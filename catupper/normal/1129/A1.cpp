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

Int n, m;
Int a, b;
Int cnt[216000];
Int mindist[216000];
Int dist(Int x, Int y){
  Int res = y - x;
  if(res < 0)res += n;
  return res;
}

int main(){
  fill(mindist, mindist + 216000, LINF);
  cin >> n >> m;
  for(int i = 0;i < m;i++){
    cin >> a >> b;
    cnt[a]++;
    mindist[a] = min(mindist[a], dist(a, b));
  }

  for(int i = 1;i <= n;i++){
    Int res = 0;
    for(int j = 1;j <= n;j++){
      if(cnt[j] == 0)continue;
      res = max(res, dist(i, j) + n * (cnt[j]-1) + mindist[j]); 
    }
    if(i != 1)cout << " ";
    cout << res;
  }cout << endl;
  return 0;
}