#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, m;
vector<LL> sumrow;
vector<LL> sumcol;
vector<vector<LL>> mat;

// Returns the sum of the largest k elements of vec.
// Complexity O(|vec|*k).
LL sum_max(vector<LL> vec, int k) {
  vector<LL> maxs;
  for (LL x: vec) {
    maxs.push_back(x);
    int it = maxs.size();
    while (it >= 2 and maxs[it-1] > maxs[it-2]) swap(maxs[it-1], maxs[it-2]), it--; 
    if (k < (int)maxs.size()) maxs.pop_back();
  }
  LL res = 0;
  for (LL x: maxs) res += x;
  return res;
}

void transpose_matrix() {
  swap(n, m);
  vector<vector<LL>> new_mat(n, vector<LL>(m));
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) new_mat[i][j] = mat[j][i];
  mat = new_mat;
  sumrow.clear();
  sumcol.clear();
  sumrow.resize(n, 0);
  sumcol.resize(m, 0);
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) sumrow[i] += mat[i][j], sumcol[j] += mat[i][j];
}

LL zero_or_one_row() {
  LL res = sum_max(sumrow, 4);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) sumcol[j] -= mat[i][j];
    res = max(res, sumrow[i] + sum_max(sumcol, 3));
    for (int j = 0; j < m; j++) sumcol[j] += mat[i][j];
  }
  return res;
}

int main() {
    // ifstream in("i/
  cin >> n >> m;
  mat.resize(n, vector<LL>(m, 0));
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> mat[i][j];
  transpose_matrix();
  LL res = zero_or_one_row();
  transpose_matrix();
  res = max(res, zero_or_one_row());
  if (n > m) transpose_matrix();
  for (int i1 = 0; i1 < n; i1++) for (int i2 = i1+1; i2 < n; i2++) {
    for (int j = 0; j < m; j++) sumcol[j] -= mat[i1][j] + mat[i2][j];
    res = max(res, sumrow[i1] + sumrow[i2] + sum_max(sumcol, 2));
    for (int j = 0; j < m; j++) sumcol[j] += mat[i1][j] + mat[i2][j];
  }
  cout << res << "\n";
}