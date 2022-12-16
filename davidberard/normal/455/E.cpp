#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const ll INFLL = 0x3f3f3f3f3f3f3f3f;


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
    HullStatic(const HullStatic& a, const HullStatic& b) {
      lines = (Line*) malloc(sizeof(Line)*(a.p+b.p));
      p = 0;
      int j=0;
      for (int i=0; i<a.p; ++i) {
        while (j<b.p && a.lines[i] < b.lines[j]) {
          insert(b.lines[j]);
          ++j;
        }
        insert(a.lines[i]);
      }
      while (j<b.p) {
        insert(b.lines[j]);
        ++j;
      }
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


struct segtree {
    vector<isdh::HullStatic> t;
    int h, n;
    segtree() {}
    segtree(const vector<isdh::Line>& lines) {
        h = 32 - __builtin_clz((int) lines.size());
        n = 1<<h;
        t = vector<isdh::HullStatic>(n<<1);
        for (int i=0; i<lines.size(); ++i) {
            t[i+n] = isdh::HullStatic(1);
            t[i+n].insert(lines[i]);
        }
        for (int i=n-1; i; --i) {
            t[i] = isdh::HullStatic(t[i<<1], t[i<<1|1]);
        }

        /*
        for (int i=1; i<n*2; ++i) {
            //cerr << " i " << i << endl;
            for (auto& l : t[i].lines) {
                //cerr << "   l " << l.m << "x + " << l.b << " : " << l.start << endl;
            }
        }
        */
    }
    ll query(int l, int r, ll x) {
        ll ans = INFLL;
        for (l+=n, r+=n; l<r; l/=2, r/=2) {
            if (l%2) {
                //cerr << " get " << l << endl;
                ans = min(ans, t[l++].solve(x));
            }
            if (r%2) {
                ans = min(ans, t[--r].solve(x));
                //cerr << " get " << r << endl;
            }
        }
        return ans;
    }
};

const int N = 100100;

ll a[N], sum[N];
int n, m;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;

    vector<isdh::Line> lines(n+1);
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        sum[i] = sum[i-1]+a[i];
        lines[i] = isdh::Line(a[i], a[i]*i - sum[i]);
        //cerr << " :: " << a[i] << "x + " << a[i]*i - sum[i] << endl;
    }

    segtree st(lines);

    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        int hi = y+1;
        int lo = max(1, hi-x);
        //cerr << "QUERY " << lo << " " << hi << " " << x-y << endl;
        //cerr << "  -> " << sum[y] << " " << st.query(lo, hi, x-y) << endl;
        ll ans = sum[y] + st.query(lo, hi, x-y);
        cout << ans << "\n";
    }

    return 0;
}