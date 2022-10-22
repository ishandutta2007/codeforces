#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cstdio>
using namespace std;

typedef long long Int;
typedef pair<Int, Int> P;
#define INF (1LL << 60)
set<P> s;
vector<P> query[540000];

Int area, p, q, r, n, x, y, z, res;

void add(P x){
  set<P>::iterator it, jt;
  it = s.lower_bound(x);
  if(x.second <= it->second)return;

  int h = it->second;
  s.insert(x);
  it = s.find(x);it--;
  area -= h * (x.first - it->first);
  while(it->second <= x.second){
    jt = it;jt--;
    area -= it->second * (it->first - jt->first);
    s.erase(it--);
  }
  area += x.second * (x.first - it->first);
}
int main(){
  s.insert(P(0,INF));
  s.insert(P(INF,0));
  scanf("%I64d%I64d%I64d%I64d", &n, &p, &q, &r);
  for(int i = 0;i < n;i++){
    scanf("%I64d%I64d%I64d", &x, &y, &z);
    query[p].push_back(P(y, z));
    query[x].push_back(P(q, z));
    query[x].push_back(P(y, r));
  }
  for(int i = p;i > 0;i--){
    for(int j = 0;j < query[i].size();j++){
      add(query[i][j]);
    }
    res += area;
  }
  cout << p * q * r - res << endl;
  return 0;
}