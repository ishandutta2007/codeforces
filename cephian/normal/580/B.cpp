#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

queue<pii> Q;
int n, d;
vector<pii> v;

int main() {
  //freopen("2.in", "r", stdin);

  cin >> n >> d;
  for(int i = 0; i < n; ++i) {
    int m, f;
    cin >> m >> f;
    v.push_back(pii(m, f));
  }
  sort(v.begin(), v.end());
  ll sum = 0;
  ll mx = 0;
  for(int i = 0; i < v.size(); ++i) {
    while(!Q.empty() && v[i].first - Q.front().first >= d) {
        sum -= Q.front().second;
        Q.pop();
    }
    Q.push(v[i]);
    sum += v[i].second;
    mx = max(sum, mx);
  }
  cout << mx << "\n";
  return 0;
}