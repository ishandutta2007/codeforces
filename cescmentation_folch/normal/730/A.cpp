#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using VI = vector<int>;
using VB = vector<bool>;
using VVB = vector<VB>;

void mins(const VI& v, int& m1, int& m2, int& mn) {
  m1 = 0;
  m2 = 1;
  mn = 0;
  if (v[m1] < v[m2]) swap(m1, m2);
  if (v[1] < v[0]) mn = 1;

  for (int i = 2; i < int(v.size()); ++i) {
    if (v[i] < v[mn]) mn = i;
    if (v[i] > v[m1]) {
      swap(m1, m2);
      m1 = i;
    } else if (v[i] > v[m2]) {
      m2 = i;
    }
  }
}

void mins(const VI& v, int& m1, int& m2, int& m3, int& mn) {
  mn = 0;
  for (int i= 0; i < 3; ++i) {
    if (v[i] < v[mn]) mn = i;
  }
  m1 = mn;
  m2 = mn;
  m3 = mn;
  for (int i = 0; i < 3; ++i) {
    if (v[i] >= v[m1]) m1 = i;
  }
  for (int i = 0; i < 3; ++i) {
    if (v[i] >= v[m2] && i != m1) m2 = i;
  }
  for (int i = 0; i < 3; ++i) {
    if (v[i] >= v[m3] && i != m2 && i != m1) m3 = i;
  }


  for (int i = 3; i < int(v.size()); ++i) {
    if (v[i] < v[mn]) mn = i;
    if (v[i] > v[m1]) {
      swap(m1, m2);
      swap(m2, m3);
      m1 = i;
    } else if (v[i] > v[m2]) {
      swap(m2, m3);
      m2 = i;
    } else if (v[i] > v[m3]) {
      m3 = i;
    }
  }
}

int dowork(VI& v, VVB& vprint, int& round) {
  while (true) {
    int m1;
    int m2;
    int mn;
    mins(v, m1, m2, mn);
    if (v[mn] == v[m1]) break;
    for (int i = 0; i < int(v.size()); ++i) {
      vprint[round][i] = (i == m1 || i == m2);
    }
    round++;
    v[m1] = max(0, v[m1]-1);
    v[m2] = max(0, v[m2]-1);
  }
  return v[0];
}

int main() {
  VVB ans(10005, VB(105, false));
  VVB ans3(10005, VB(105, false));

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n; cin >> n;
  VI v(n);
  for (auto& x : v) cin >> x;
  VI v3(v);

  int round = 0;
  int x = dowork(v, ans, round);

  if (n > 3) {
    int m1, m2, m3, mn;
    int r3 = 0;
    mins(v3, m1, m2, m3, mn);
    if (v3[mn] != v3[m1]) {
      for (int i = 0; i < n; ++i) {
        ans3[r3][i] = (i == m1 || i == m2 || i == m3);
      }
      r3++;
      v3[m1] = max(0, v3[m1]-1);
      v3[m2] = max(0, v3[m2]-1);
      v3[m3] = max(0, v3[m3]-1);
    }
    int x3 = dowork(v3, ans3, r3);
    if (x3 > x) {
      x = x3;
      swap(ans, ans3);
      swap(round, r3);
    }
  }

  cout << x << "\n" << round  << "\n";
  for (int i = 0; i < round; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << ans[i][j];
    }
    cout << endl;
  }
}