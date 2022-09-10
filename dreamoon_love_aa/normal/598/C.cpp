#include <bits/stdc++.h>
using namespace std;

const long double PI = acos(-(long double)1);
typedef complex<long double> pt;
double dot(pt a, pt b) { return real(conj(a) * b); }

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  vector<pair<pt, int>> V;
  int n; cin >> n;
  long double x, y;
  for (int i = 0; i < n; ++i) cin >> x >> y, V.push_back({{x, y}, i});
  int j = 0;
  long double ang = 10;
  sort(V.begin(), V.end(), [](pair<pt, int> a, pair<pt, int> b) { 
    return arg(a.first) < arg(b.first);
  });
  for (int i = 0; i < n; ++i) {
    auto A = V[i].first, B = V[(i + 1) % n].first;
    long double diff = fabs(arg(A)-arg(B));
    if(diff>PI)diff=2*PI-diff;
    if (diff < ang) ang = diff, j = i;
  }
  cout << V[j].second + 1 << ' ' << V[(j + 1) % n].second + 1 << '\n';
}