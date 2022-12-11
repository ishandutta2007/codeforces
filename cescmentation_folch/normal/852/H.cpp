#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>,
      rb_tree_tag,tree_order_statistics_node_update>;
// Use like a map: put something instead of null_type

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<ld> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;

typedef ll T; //Tipus del punt: Tocar aixo!
const T INF = 1000000000000000LL;
const ld EPS = 1e-5;

struct Pt {
  T x, y;
  int ind;
  Pt(T a, T b) : x(a), y(b) {}
  Pt() {} };

//Tocar aixo!
inline bool EQ(T a, T b) { return a == b; }
inline T sq(T n) { return n*n; }
inline Pt operator+(Pt a, Pt b) {
  return Pt(a.x + b.x, a.y + b.y); }
inline Pt operator-(Pt a, Pt b) {
  return Pt(a.x - b.x, a.y - b.y); }
inline Pt operator*(T k, Pt a) {
  return Pt(k*a.x, k*a.y); }
inline Pt operator/(Pt a, T k) {
  return Pt(a.x/k, a.y/k); }
inline T operator^(Pt a, Pt b) {
  return a.x*b.y - a.y*b.x; }
inline T operator*(Pt a, Pt b) {
  return a.x*b.x + a.y*b.y; }
inline bool operator==(Pt a, Pt b) {
  return EQ(a.x, b.x) and EQ(a.y, b.y); }
inline bool operator!=(Pt a, Pt b) {
  return !(a == b); }
inline bool operator<(Pt a, Pt b) {
  return EQ(a.x, b.x) ? a.y < b.y : a.x < b.x; }
inline bool operator<=(Pt a, Pt b) {
  return a < b or a == b; }
inline bool operator>(Pt a, Pt b) {
  return !(a <= b); }
inline bool operator>=(Pt a, Pt b) {return !(a < b);}
ostream& operator<<(ostream& out, Pt a) {
  out << "(" << a.x << "," << a.y << ")";return out;}
istream& operator>>(istream& in, Pt& a) {
  in >> a.x >> a.y; return in; }

inline ld area2(Pt a, Pt b, Pt c) {
  return (b - a)^(c - a); } //a is the central point
inline ld area(Pt a, Pt b, Pt c) {
  return abs(area2(a,b,c))/2.0;
}
inline T dist2(Pt a, Pt b) {return (a - b)*(a - b); }
inline ld dist(Pt a, Pt b) {return sqrt(dist2(a,b));}
inline T norm2(Pt a) { return a*a; }
inline ld norm(Pt a) { return sqrt(a*a); }
inline Pt unit(Pt a) { return a/norm(a); }


bool comp(Pt a, Pt b) {
  return (a^b) < 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<Pt> V(n);
  for (int i = 0; i < n; ++i) cin >> V[i].x >> V[i].y;
  sort(V.begin(), V.end());
  ld res = 0;
  for (int ini = 0; ini + k <= n; ++ini) {
    vector<Pt> S;
    for (int i = ini+1; i < n; ++i) {
      S.push_back(V[i] - V[ini]);
      S.back().ind = i;
    }
    sort(S.begin(), S.end(), comp);

    vvvld D(S.size() +1, vvld(S.size()+1, vld(k,0)));
    int sz = S.size();
    for (int i = 1; i <= sz; ++i) {
      vector<Pt> H1, H2;
      for (int j = 0; j < i-1; ++j) {
        H1.push_back(V[S[j].ind] - V[S[i-1].ind]);
        H1.back().ind = j+1;
      }
      for (int j = i; j < sz; ++j) {
        H2.push_back(V[S[j].ind] - V[S[i-1].ind]);
        H2.back().ind = j+1;
      }
      sort(H1.begin(), H1.end(), comp);
      sort(H2.begin(), H2.end(), comp);
      int index = n+10;
      for (int j = (int)H2.size()-1; j >= 0; --j) {
        if (H2[j].ind >= index) H2[j].ind = -1;
        else index = H2[j].ind;
      }
      vld N = D[0][i];
      int ind1 = 0;
      for (int ww = 0; ww < (int)H2.size(); ++ww) {
        if (H2[ww].ind == -1) continue;
        auto p = H2[ww];
        while (ind1 < (int)H1.size() and (H1[ind1]^p) >= 0) {
          int id = H1[ind1].ind;
          for (int w = 2; w < k; ++w) {
            if (D[id][i][w] < EPS) break;
            N[w] = max(N[w], D[id][i][w]);
          }
          ++ind1;
        }
        for (int j = 2; j < k; ++j) {
          if (j > 2 and N[j-1] < EPS) break;
          D[i][p.ind][j] = max(D[i][p.ind][j], N[j-1] + area(V[ini], V[S[i-1].ind], V[S[p.ind-1].ind])); 
        }
      }
      while (ind1 < (int)H1.size()) {
        int id = H1[ind1].ind;
        N[k-1] = max(N[k-1], D[id][i][k-1]);
        ++ind1;
      }
      res = max(res, N[k-1]);
    }
  }
  cout << setprecision(2) << fixed << res << '\n';
}