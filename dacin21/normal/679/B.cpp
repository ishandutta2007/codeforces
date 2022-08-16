#include <bits/stdc++.h>

using namespace std;

vector<long long> p3;

unordered_map<long long, pair<int, long long> > cache;
pair<int, long long>  best(long long lim){
  if(lim==0) return make_pair(0, 0ll);
  if(cache.count(lim)) return cache[lim];
  long long p = *(upper_bound(p3.begin(), p3.end(), lim)-1);
  pair<int, long long> c1 = best(p-1);
  pair<int, long long> c2 = best(lim-p);
  c2.first+=1;
  c2.second+=p;
  return cache[lim] = max(c1, c2);
}

int main()
{
  long long X;
  cin >> X;
  for(long long a=1;a*a*a<=X;++a){
    p3.emplace_back(a*a*a);
  }
  pair<int, long long> ret(0, 0);
  ret=best(X);
  cout << ret.first << " " << ret.second  << endl;


  return 0;
}