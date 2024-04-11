#include <bits/stdc++.h>

using namespace std;

<<<<<<< HEAD
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
=======
struct Line{
  static constexpr long double ninf = numeric_limits<long double>::lowest();
  static Line qline;
  long long m, q;
  mutable long double xleft;
  Line(long long _m, long long _q):m(_m), q(_q), xleft(ninf){}
  bool operator<(const Line& other)const{
    if(this == &qline || &other == &qline){ // query
        return xleft < other.xleft;
    }
    return m < other.m;//Max hull
  }
  void recalcxleft(const Line & pre)const{
    xleft = -((long double)pre.q-q ) / (pre.m-m);
  }
};
Line Line::qline(0, 0);
template<typename intersect_t>
struct Hull {
>>>>>>> ba48ae4a69f706fe86df6abfbbc02a36ff86f577
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
<<<<<<< HEAD
    return ((long double)it->q - suc->q) / (suc->m - it->m) <= ((long double)pre->q - it->q) / (it->m - pre->m);//check x intersection
=======
    return ((intersect_t)it->q - suc->q)*(it->m - pre->m) <= ((intersect_t)pre->q - it->q)*(suc->m - it->m);//check x intersection
>>>>>>> ba48ae4a69f706fe86df6abfbbc02a36ff86f577
  }
  void insert(Line const & l){
    multiset<Line>::iterator e = slopes.insert(l);
    if(bad(e)){
      slopes.erase(e);
      return;
    }
    while(next(e)!=slopes.end() && bad(next(e)))slopes.erase(next(e));
<<<<<<< HEAD
    if(next(e)!=slopes.end()){next(e)->recalcXLeft(*e);}
    while(e!=slopes.begin() && bad(prev(e))) slopes.erase(prev(e));
    if(e!=slopes.begin()){
      e->recalcXLeft(*prev(e));
    } else e->xLeft = xLeftLeftest;
  }

  long long query(long long x){
    auto e = slopes.upper_bound(Line(x, qQuery));
=======
    if(next(e)!=slopes.end()){next(e)->recalcxleft(*e);}
    while(e!=slopes.begin() && bad(prev(e))) slopes.erase(prev(e));
    if(e!=slopes.begin()){
      e->recalcxleft(*prev(e));
    } else e->xleft = Line::ninf;
  }

  long long query(long long x){
    Line::qline.xleft = x;
    auto e = slopes.upper_bound(Line::qline);
>>>>>>> ba48ae4a69f706fe86df6abfbbc02a36ff86f577
    assert(e!=slopes.begin());
    --e;
    return e->m * x + e->q;
  }
<<<<<<< HEAD
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
=======
};
template<typename intersect_t>
struct MonoHull{
  deque<Line> data;
  bool badBack(Line const &newLine){
    if(data.size()<2) return false;
    Line secondLast = data[(int)data.size()-2];
    Line last = data.back();
    return ((intersect_t)last.q - newLine.q)*(last.m - secondLast.m) <= ((intersect_t)secondLast.q - last.q)*(newLine.m - last.m);
  }

  void insert(Line const & l){
    assert(data.empty() || l.m >= data.back().m);
    if(!data.empty() && l.m == data.back().m){
        data.back().q = max(data.back().q, l.q);
        return;
    }
    while(badBack(l)) data.pop_back();
    if(!data.empty()) l.recalcxleft(data.back());
    data.push_back(l);
  }
  long long query(long long x){
    while(data.size()>1 && x>data[1].xleft)
      data.pop_front();
    return data.front().m*x+data.front().q;
  }
};

int monoMain(){
  //cin.tie(0);
  //ios_base::sync_with_stdio(false);
  int N;
  scanf("%d", &N);
  vector<long long> a(N), b(N);
  for(int i=0;i<N;++i)
    scanf("%lld", &a[i]);
  for(int i=0;i<N;++i)
    scanf("%lld", &b[i]);
  Hull<long double> h;
  //MonoHull<long double> h;
  h.insert(Line(-b[0], 0));
  for(int i=1;i<N-1;++i){
      //cerr << i <<" : " << h.query(a[i]) << "\n";
      h.insert(Line(-b[i], h.query(a[i])));
  }
  printf("%lld", -h.query(a.back()));
  return 0;
}

int main()
{
  return monoMain();
>>>>>>> ba48ae4a69f706fe86df6abfbbc02a36ff86f577
  cin.tie(0);
  vector<long long> a, b;
  int N;
  cin >> N;
  copy_n(istream_iterator<long long>(cin), N, back_inserter(a));
  copy_n(istream_iterator<long long>(cin), N, back_inserter(b));
<<<<<<< HEAD
  Hull h;
=======
  Hull<long double> h;
>>>>>>> ba48ae4a69f706fe86df6abfbbc02a36ff86f577
  h.insert(Line(-b[0], 0));
  for(int i=1;i<N-1;++i){
      //cerr << i <<" : " << h.query(a[i]) << "\n";
      h.insert(Line(-b[i], h.query(a[i])));
  }
  cout << -h.query(a.back());

  return 0;
}