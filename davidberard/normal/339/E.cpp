#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int kf;
vector<pii> vf;

bool solve(vector<int>& v, int k) {
  //cerr << " K " << k << endl;
  bool good = true;
  for (int i=0; i<v.size(); ++i) {
    if (v[i] != i+1) {
      good = false;
      break;
    }
  }
  if (good) {
    return true;
  }

  if (k == 3) {
    return false;
  }

  int ep[25];
  int epc=0;
  ep[epc++] = 0;
  for (int i=1; i<v.size(); ++i) {
    if (abs(v[i]-v[i-1]) != 1) {
      for (int j=i-1; j<=i; ++j) {
        if (ep[epc-1]<j) {
          ep[epc++] = j;
        }
      }
    }
  }
  if (ep[epc-1]<v.size()) {
    ep[epc++] = v.size();
  }

  for (int i=0; i<epc; ++i) {
    for (int j=i+1; j<epc; ++j) {
      if (ep[j]-ep[i] == 1) {
        continue;
      }
      vf.emplace_back(ep[i], ep[j]);
      reverse(v.begin()+ep[i], v.begin()+ep[j]);
      bool res = solve(v, k+1);
      if (res) {
        return res;
      }
      reverse(v.begin()+ep[i], v.begin()+ep[j]);
      vf.pop_back();
    }
  }
  return false;
};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  vector<int> v;
  int n;
  cin >> n;
  for (int i=1; i<=n; ++i) {
    int a;
    cin >> a;
    v.push_back(a);
  }
  bool res = solve(v, 0);
  assert(res);
  cout << vf.size() << endl;
  reverse(vf.begin(), vf.end());
  for (auto& p : vf) {
    cout << p.first+1 << " " << p.second << "\n";
  }

  return 0;
}