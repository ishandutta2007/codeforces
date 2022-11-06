//https://codeforces.com/contest/1080/problem/F
#include <iostream>
#include <fstream>
#include <iomanip>
#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include<ext/rope>

using __gnu_cxx::rope;
using std::cerr;
using std::deque;
using std::endl;
using std::fill;
using std::ios_base;
using std::istream;
using std::iterator;
using std::make_pair;
using std::map;
using std::max;
using std::min;
using std::numeric_limits;
using std::ostream;
using std::pair;
using std::priority_queue;
using std::set;
using std::sort;
using std::string;
using std::swap;
using std::unordered_map;
using std::vector;
using std::bitset;
using std::uniform_int_distribution;
using std::uniform_real_distribution;

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

namespace dalt
{
};
namespace other
{
};

using namespace dalt;

namespace dalt
{
class no_tag_persistent_segment
{
public:
    no_tag_persistent_segment()
    {
        _l = _r = this;
        _val = -1;
    }

#define NO_INTERSECTION ql > r || qr < l
#define COVER ql <= l &&qr >= r
#define RANGE (min(qr, r) - max(l, ql) + 1)

    void update(int ql, int qr, int l, int r, int val)
    {
        if (COVER)
        {
            modify(val);
            return;
        }
        pushDown();
        int m = (l + r) >> 1;
        if (!(m < ql || l > qr))
        {
            _l = new no_tag_persistent_segment(*_l);
            _l->update(ql, qr, l, m, val);
        }
        if (!(m + 1 > qr || r < ql))
        {
            _r = new no_tag_persistent_segment(*_r);
            _r->update(ql, qr, m + 1, r, val);
        }
        pushUp();
    }

    int query(int ql, int qr, int l, int r)
    {
        if (NO_INTERSECTION)
        {
            return 2e9;
        }
        if (COVER)
        {
            return _val;
        }
        int m = (l + r) >> 1;
        return min(_l->query(ql, qr, l, m),
        _r->query(ql, qr, m + 1, r));
    }

#undef NO_INTERSECTION
#undef COVER

private:
    no_tag_persistent_segment *_l, *_r;
    int _val;

    void pushDown()
    {
    }

    void pushUp()
    {
      _val = min(_l->_val, _r->_val); 
    }

    void modify(int val)
    {
      _val = val;
    }
};
}

struct Interval{
  int l;
  int r;
  int belongTo;
};

void no(ostream &out){
  out << "no" << endl;
  out.flush();
}

void yes(ostream &out){
  out << "yes" << endl;
  out.flush();
}

void solve(istream &in, ostream &out)
{
  int n, m , k;
  in >> n >> m >> k;
  vector<Interval> intervals(k);
  for(int i = 0; i < k; i++){
    in >> intervals[i].l >> intervals[i].r >> intervals[i].belongTo;
  }
  sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) { return a.r < b.r;});
  vector<int> leftBound(n + 1, -1);
  map<int, no_tag_persistent_segment *> segtrees;
  no_tag_persistent_segment *last = new no_tag_persistent_segment();
  for(Interval &interval : intervals){
    if(leftBound[interval.belongTo] >= interval.l){
      continue;
    }
    last = new no_tag_persistent_segment(*last);
    last->update(interval.belongTo, interval.belongTo, 1, n, interval.l);
    leftBound[interval.belongTo] = interval.l;
    segtrees[interval.r] = last;
  }
  for(int i = 0; i < m; i++){
    int a, b, x, y;
    in >> a >> b >> x >> y;
    auto iter = segtrees.upper_bound(y);
    if(iter == segtrees.begin()){
      no(out);
      //cerr << "not exist" << endl;
      continue;
    }
    iter--;
    no_tag_persistent_segment *seg = iter->second;
    int l = seg->query(a, b, 1, n);
    //cerr << l << endl;
    if(l >= x){
      yes(out);
    }else{
      no(out);
    }
  }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout << std::setiosflags(std::ios::fixed);
    std::cout << std::setprecision(15);
    
    solve(std::cin, std::cout);

    return 0;
}