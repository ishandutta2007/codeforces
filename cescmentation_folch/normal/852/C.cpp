#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef pair<ld, ld> pld;
typedef pair<ld, int> pli;

pld operator*(pld a, pld b) {
  pld c;
  c.first = a.first*b.first - a.second*b.second;
  c.second = a.first*b.second + a.second*b.first;
  return c;
}

pld mit(pld a, pld b, ld f) {
  pld c;
  c.first = (b.first - a.first)*f + a.first;
  c.second = (b.second - a.second)*f + a.second;
  return c;
}

ld dist(pld a, pld b) {
  ld x = a.first - b.first;
  ld y = a.second - b.second;
  return sqrt(x*x + y*y);
}

ld area(pld a, pld b, pld c) {
  ld d1 = dist(a, b);
  ld d2 = dist(b, c);
  ld d3 = dist(c, a);
  ld d = (d1 + d2 + d3)/2.0;
  return sqrt(d*(d-d1)*(d-d2)*(d-d3));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vi P(n);
  for (int i = 0; i < n; ++i) cin >> P[i];
  ld PI = acos(-1.0);
  ld alpha = PI/ld(n);
  pld ang(cos(alpha), sin(alpha));
  vector<pld> V(2*n);
  V[0] = pld(1,0);
  for (int i = 1; i < 2*n; ++i) V[i] = V[i-1]*ang;
  //for (int i = 0; i < 2*n; ++i) cerr << V[i].first << ' ' << V[i].second << endl;
  //cerr << endl;
  vector<pli> S(n);
  for (int i = 0; i < n; ++i) {
    pld a = mit(V[2*i], V[2*i+1], ld(P[i])/ld(n));
    pld b = mit(V[(2*i+2)%(2*n)], V[(2*i+3)%(2*n)], ld(P[(i+1)%n])/ld(n));
    //cerr << a.first << ' ' << a.second << ' ' << b.first << ' ' << b.second << endl;
    pld c1 = V[2*i+1];
    pld c2 = V[(2*i+2)%(2*n)];
    ld a1 = area(a, b, c1);
    ld a2 = area(a, b, c2);
    //cerr << c1.first << ' ' << c1.second << endl;
    //cerr << c2.first << ' ' << c2.second << endl;
    //cerr << a1 << ' ' << a2 << endl;
    if (a1 > a2) {
      S[i] = pli(a2 - a1, i+1);
    }
    else {
      S[i] = pli(a1 - a2, -i-1);
    }
    //cerr << i << ' '  << S[i].first << ' ' << S[i].second << endl;
  }
  sort(S.begin(), S.end());
  vi p2(n);
  int a = 0;
  int b = n-1;
  for (int i = 0; i < n; ++i) {
    int ind = abs(S[i].second) - 1;
    if (S[i].second > 0) p2[ind] = a++;
    else p2[ind] = b--;
  }
  for (int i = 0; i < n; ++i) {
    if (i) cout << ' ';
    cout << p2[i];
  }
  cout << '\n';
}