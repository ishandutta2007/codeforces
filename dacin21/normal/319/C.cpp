#include <bits/stdc++.h>

using namespace std;

const long long xLeftLeftest = -(1LL<<61);
const long long qQuery = -(1LL<<60);

struct Line{
  long long m, q;
  mutable long double xLeft;
  Line(long long _m, long long _q):m(_m), q(_q), xLeft(xLeftLeftest){}
  bool operator<(const Line& other)const{
    if(q==qQuery){
      return m < other.xLeft;
    }
    if(other.q==qQuery){
      return xLeft < m;
    }
    return m < other.m;//Max hull
  }
   void recalcXLeft(const Line & pre)const{
    xLeft = -((long double)pre.q-q ) / (pre.m-m);
  }
};

struct Hull{
  multiset<Line> slopes;

  bool bad(multiset<Line>::iterator it){
    auto suc = next(it);
    if(it==slopes.begin()){
      if(suc==slopes.end()) return false;
      return it->m==suc->m && it->q <=suc->q;
    }
    auto pre = prev(it);
    if(suc==slopes.end()){
      return it->m==pre->m && it->q <= pre->q;
    }
    return ((long double)it->q - suc->q) / (suc->m - it->m) <= ((long double)pre->q - it->q) / (it->m - pre->m);//check x intersection
  }
  void insert(Line const & l){
    multiset<Line>::iterator e = slopes.insert(l);
    if(bad(e)){
      slopes.erase(e);
      return;
    }
    while(next(e)!=slopes.end() && bad(next(e)))slopes.erase(next(e));
    if(next(e)!=slopes.end()){next(e)->recalcXLeft(*e);}
    while(e!=slopes.begin() && bad(prev(e))) slopes.erase(prev(e));
    if(e!=slopes.begin()){
      e->recalcXLeft(*prev(e));
    } else e->xLeft = xLeftLeftest;
  }

  long long query(long long x){
    auto e = slopes.upper_bound(Line(x, qQuery));
    assert(e!=slopes.begin());
    --e;
    return e->m * x + e->q;
  }
  void printLines(){
    cerr << "Lines: \n";
    for(auto &e: slopes){
      cerr << e.xLeft << ":   " << e.m << " * x + " << e.q << "\n";
    }
    cerr << "\n";
  }

};

int main()
{
  cin.tie(0);
  vector<long long> a, b;
  int N;
  cin >> N;
  copy_n(istream_iterator<long long>(cin), N, back_inserter(a));
  copy_n(istream_iterator<long long>(cin), N, back_inserter(b));
  Hull h;
  h.insert(Line(-b[0], 0));
  for(int i=1;i<N-1;++i){
      //cerr << i <<" : " << h.query(a[i]) << "\n";
      h.insert(Line(-b[i], h.query(a[i])));
  }
  cout << -h.query(a.back());

  return 0;
}