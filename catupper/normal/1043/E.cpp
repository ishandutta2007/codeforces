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

Int ans[324000];
Int x[324000], y[324000];
Int sumx, n, m;
vector<Int> difs;

int main(){
  scanf("%lld %lld", &n, &m);
  for(int i = 0;i < n;i++){
    scanf("%lld %lld", &x[i] , &y[i]);
    difs.push_back(y[i] - x[i]);
    sumx += x[i];
  }
  sort(difs.begin(), difs.end());
  Int _difsum[n+1];
  Int *difsum = _difsum + 1;
  difsum[-1] = 0;
  for(int i = 0;i < n;i++){
    difsum[i] = difsum[i-1] + difs[i];
  }
  for(int i = 0;i < n;i++){
    ans[i] += x[i] * (n-1) + sumx - x[i];
    Int pos = lower_bound(difs.begin(), difs.end(), y[i] - x[i]) - difs.begin();
    ans[i] += (n-pos-1) * (y[i] - x[i]);
    ans[i] += difsum[pos-1];
    //    cout << pos << " "<<ans[i] << endl;
  }
  for(int i = 0;i < m;i++){
    Int u, v;
    scanf("%lld %lld", &u , &v);u--,v--;
    Int val = min(x[u] + y[v], x[v] + y[u]);
    ans[u] -= val;
    ans[v] -= val;
  }

  for(int i = 0;i < n;i++)printf("%lld ",ans[i]);printf("\n");  
  return 0;
}