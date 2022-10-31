#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;

vector<pii> v;

bool cmp(const pii& a, const pii& b) {
  return abs(a.first) + abs(a.second) < abs(b.first) + abs(b.second);
}

stringstream ss;

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    pii p;
    cin >> p.first >> p.second;
    v.push_back(p);
  }
  int ans = 2*n;
  sort(v.begin(), v.end(), cmp);
  for(int i = 0; i < n; ++i) {
    if(v[i].first > 0) ss << "1 " << v[i].first << " R\n";
    else if(v[i].first < 0) ss << "1 " << -v[i].first << " L\n";
    if(v[i].second > 0) ss << "1 " << v[i].second << " U\n";
    else if(v[i].second < 0) ss << "1 " << -v[i].second << " D\n";
    ss << "2\n";
    if(v[i].second > 0) ss << "1 " << v[i].second << " D\n";
    else if(v[i].second < 0) ss << "1 " << -v[i].second << " U\n";
    if(v[i].first > 0) ss << "1 " << v[i].first << " L\n";
    else if(v[i].first < 0) ss << "1 " << -v[i].first << " R\n";
    ss << "3\n";
    if(v[i].first != 0) ans += 2;
    if(v[i].second != 0) ans += 2;
  }
  cout << ans << "\n" << ss.str();
  return 0;
}