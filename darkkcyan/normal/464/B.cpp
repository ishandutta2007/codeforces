#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )
#define repf(i,a,b) for (int i = a; i <= b; ++i) 

struct p3 {
  llong x[3];
  p3() { memset(x, 0, sizeof(x)); }
  bool nextper() { return next_permutation(x, x + 3); }
  p3& sort() { std::sort(x, x + 3); return *this; }
  llong length2() const {
    llong ans = x[0] * x[0] + x[1] * x[1] + x[2] * x[2];
    return ans;
  }
  double length() const { return sqrt(length2()); }
};

ostream& operator<< (ostream& cout, const p3& u) {
  cout << "(";
  rep(i, 3) cout << u.x[i] << ' ';
  cout << ")";
  return cout;
}

bool operator < (p3 u, p3 v) {
  u.sort(); v.sort();
  rep(i, 3) {
    if (u.x[i] < v.x[i]) return true;
    if (u.x[i] > v.x[i]) return false;
  }
  return false;
}

bool operator == (const p3& u, const p3& v) {
  return !(u < v) and !(v < u);
}

p3 fixlength(const p3& x, double sl) {
  // clog << "sqrt length " << sl << ' ' << ' ' << x.length2() << ' ';
  // rep(i, 3) clog << x.x[i] << ' ';
  // clog << endl;
  p3 ans;
  rep(i, 3) ans.x[i] = round(x.x[i] / sl);
  return ans;
}

p3 operator* (const p3& u, const p3& v) {
  p3 ans;
  rep(a, 3) {
    int b = (a + 1) % 3, c = (a + 2) % 3;
    ans.x[a] = u.x[b] * v.x[c] - u.x[c] * v.x[b];
  }
  return ans;
}

p3 operator - (const p3& u, const p3& v) {
  p3 ans; rep(i, 3) ans.x[i] = u.x[i] - v.x[i];
  return ans;
}

p3 operator +(const p3& u, const p3& v) {
  p3 ans; rep(i, 3) ans.x[i] = u.x[i] + v.x[i];
  return ans;
}

int cross(const p3& u, const p3& v) {
  llong ans = 0;
  rep(i, 3) ans += u.x[i] * v.x[i];
  return ans;
}

p3 a[8];


int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  rep(i, 8) rep(f, 3) cin >> a[i].x[f];
  rep(i, 8) a[i].sort();
  
  int neq = 0, np = 0, ni = 0, nss = 0;
  rep(i, 8) rep(f, 8) rep(g, 8) {
    if (i == f or f == g or  g == i) continue;
    do { do { do {
      p3 u = a[f] - a[i], v = a[g] - a[i];

      if (u.length2() != v.length2()) {
        // clog << " not eq length" << endl;
        ++neq;
        continue;
      }

      if (cross(u, v) != 0) {
        // clog << "not perpendicular" << endl;
        ++np;
        continue;
      }
      
      // clog << a[i] << ' ' << a[f] << ' ' << a[g] << endl;

      p3 uv = u * v;
      p3 suv = fixlength(uv, u.length());
      if (suv.length2() != u.length2()) {
        ++ni;
        // clog << "suv is not integer point" << ' ' << suv.length2() << ' ' << u.length2() << endl;
        continue;
      }
      multiset<p3> s1, s2;
      rep(h, 8) {
        if (h != i and h != f and h != g) s1.insert(a[h]);
      }
      
      s2.insert(a[g] + u);
      s2.insert(a[g] + u + suv);
      s2.insert(a[i] + suv);
      s2.insert(a[f] + suv);
      s2.insert(a[g] + suv);
      
      if (s1 != s2) {
        // clog << "Not same set" << endl;
        // for (auto u: s1) {
        //   clog << u << ' ';
        // }
        // clog << endl;
        // for (auto v: s2) clog << v << ' '; clog << endl;
        nss++;
        continue;
      }
      rep(h, 8) {
        if (h == i or h == f or h == g) continue;
        for (auto it = s2.begin(); it != s2.end(); ++it) {
          if (!(a[h] == *it)) continue;
          a[h] = *it;
          s2.erase(it);
          break;
        }
      }
      cout << "YES\n";
      rep(i, 8) {
        rep(f, 3) cout << a[i].x[f] << ' ';
        cout << '\n';
      }
      
      exit(0);
    } while (a[g].nextper()); } while (a[f].nextper()); } while (a[i].nextper());
  }
  
  // clog << neq << ' ' << np << ' ' << ni << ' ' << nss << endl;
  cout << "NO";
  
  return 0;
}