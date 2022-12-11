#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef vector<pi> vpi;

struct inter{
  pi cord;
  int num;
};

bool comp(inter a, inter b) {
  return a.cord < b.cord;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  map<int, pi> M;
  map<int, int> T;
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (!M.count(x)) {
      M[x] = pi(i,i);
      T[x] = 1;
    }
    else {
      M[x].second = i;
      ++T[x];
    }
  }
  vector<inter> S;
  for (auto it : M) {
    inter t;
    t.num = T[it.first];
    t.cord = it.second;
    S.push_back(t);
  }
  sort(S.begin(), S.end(), comp);
  int res = 0;
  int m = -1;
  int num = 0;
  for (auto x : S) {
    if (x.cord.first > m) {
      m = x.cord.second;
      num = x.num;
    } else {
      m = max(x.cord.second, m);
      res += min(num, x.num);
      num = max(num, x.num);
    }
  }
  cout << res << '\n';
}