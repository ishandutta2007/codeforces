#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

bool alingx(pll a, pll b) {
  return a.first == b.first;
}

bool alingy(pll a, pll b) {
  return a.second == b.second;
}

bool forax(pll a, pll b, pll c) {
  if (c.first < max(a.first, b.first) and c.first > min(a.first, b.first)) return false;
  return true;
}

bool foray(pll a, pll b, pll c) {
  if (c.second < max(a.second, b.second) and c.second > min(a.second, b.second)) return false;
  return true;
}

int main() {
  pll a[3];
  for (int i = 0; i < 3; ++i) cin >> a[i].first >> a[i].second;
  
  if ((alingx(a[0], a[1]) and alingx(a[0], a[2])) or (alingy(a[0], a[1]) and alingy(a[0], a[2]))) {
    cout << 1 << endl;
    return 0;
  }
  
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (i == j) continue;
      for (int w = 0; w < 3; ++w) {
	if (i == w or j == w) continue;
	if ((alingx(a[i], a[j]) and foray(a[i], a[j], a[w])) or (alingy(a[i], a[j]) and forax(a[i], a[j], a[w]))) {
	  cout << 2 << endl;
	  return 0;
	}
      }
    }
  }
  cout << 3 << endl;
}