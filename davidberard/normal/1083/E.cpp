#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
 
const int NMAX = 1001000;
const ll INF = 0x25f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
 
ll x[NMAX], y[NMAX], a[NMAX];
int N;
 
ll MM = 1.1e9;

namespace isdh {
  struct Line {
    ll m, b, start;
    Line() {}
    Line(ll x, ll y) : m(x), b(y), start(-INFLL) {}
    ll isecX(const Line& o) const { // ceil(x intersection point) or -INFLL if parallel
      if (m == o.m) return -INFLL;
      ll num = (b-o.b), den=o.m-m;
      return num/den + ((num^den) >= 0 && num%den);
    }
    ll solve(const ll& x) const {
      return m*x+b;
    }
    bool operator < (const Line& o) const {
      return (m == o.m ? b < o.b : m < o.m);
    }
  };

  struct HullStatic {
    Line *lines; int p;
    HullStatic() :lines(nullptr), p(0) {}
    HullStatic(int sz) :p(0) {
      lines = (Line*) malloc(sizeof(Line)*sz);
    }
    HullStatic(vector<Line> init) {
      lines = (Line*) malloc(sizeof(Line)*init.size());
      sort(init.begin(), init.end());
      p = 0;
      // reverse(lines.begin(), lines.end()); // for min
      for (auto& l : init) insert(l);
    }
    inline void insert(Line l) {
      // insertions must be done in order of m and b
      while (p && l.isecX(lines[p-1]) <= lines[p-1].start) {
        --p;
      }
      if (p) {
        l.start = l.isecX(lines[p-1]);
        lines[p++] = move(l);
      } else {
        l.start = -INFLL;
        lines[p++] = move(l);
      }
    }
    ll solve(ll x) {
      int lo = 0, hi = p-1;
      while (lo < hi) {
        int m = (lo+hi+1)/2;
        if (lines[m].start <= x) {
          lo = m;
        } else {
          hi = m-1;
        }
      }
      return lines[lo].solve(x);
    }
  };
}


inline char get() {
	static char buf[100000], *S=buf, *T=buf;
	if(S==T) {
		T = (S=buf) + fread(buf, 1, 100000, stdin);
		if(S==T) return EOF;
	}
	return *S++;
}
 
inline ll read() {
	static char c; ll x = 0;
	for(c=get();c<'0'||c>'9';c=get());
	for(;c>='0'&&c<='9';c=get()) x = x*10+c-'0';
	return x;
}
 
ll ans;
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
	N = read();
    vector<vector<ll>> v(N, vector<ll>(3));
    for(auto& vv : v) {
        for(auto& vvv : vv) {
            vvv = read();
        }
    }
    sort(v.begin(), v.end());
    for(int i=1;i<=N;++i) {
        x[i] = v[i-1][0];
        y[i] = v[i-1][1];
        a[i] = v[i-1][2];
    }
    isdh::HullStatic env(N);
	env.insert(isdh::Line(0, 0));
	for(int i=N;i>=0;--i) {
        ll f = env.solve(MM-x[i]);
		////cerr << " f = " << f << endl;
		ans = max(f, ans);
		ll b = f + (x[i]-MM)*y[i] - a[i];
		ll m = y[i];
		////cerr << "b " << b << " m " << m << endl;
		if(i != 0) {
			env.insert(isdh::Line(m, b));
		}
	}
	cout << ans << endl;
 
    return 0;
}