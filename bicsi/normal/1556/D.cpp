#include <bits/stdc++.h>

using namespace std;
const bool DRY = false;

vector<int> GT = {1392871, 13298712, 3121, 3871231, 123871238, 1328971239};
int n, k;
vector<int> r;

void Init() {
  if (DRY) { n = GT.size(); k = 2; }
  else { cin >> n >> k; --k; }
}
int Qry(string s, int a, int b) {
  cout << s << " " << a + 1 << " " << b + 1 << endl;
  int res;
  if (DRY) {
    if (s == "and") res = (GT[a] & GT[b]);
    else res = (GT[a] | GT[b]);
  } else {
    cin >> res;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  Init();
  r.assign(n, 0);
  int AND[3][3], OR[3][3];
  for (int j = 0; j < 3; ++j) {
    for (int k = j + 1; k < 3; ++k) {
      AND[j][k] = AND[k][j] = Qry("and", j, k);
      OR[j][k] = OR[k][j] = Qry("or", j, k);
    }
  }
  for (int bit = 31; bit >= 0; --bit) {
    int okk = 0;
    for (int msk = 0; msk < 8; ++msk) {
      int b[3] = {(msk & 1), ((msk >> 1) & 1), ((msk >> 2) & 1)};
      bool ok = true;
      for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 3; ++j) {
          ok &= ((AND[i][j] >> bit) & 1) == (b[i] & b[j]);
          ok &= ((OR[i][j] >> bit) & 1) == (b[i] | b[j]);
        }
      }
      if (ok) {
        for (int i = 0; i < 3; ++i)
          if (b[i])
            r[i] |= (1 << bit);
        okk = 1;
        break;
      }
    }   
    assert(okk);
  }
  for (int i = 3; i < n; ++i) {
    int a = Qry("and", i, 0);
    int b = Qry("or", i, 0);
    int c = (a ^ b);
    r[i] = (c ^ r[0]);
  }
  
  if (DRY) {
    assert(r == GT);
    cerr << "OK\n";
  } else {
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int a, int b) { return r[a] < r[b]; });
    cout << "finish " << r[o[k]] << endl;
  }
  return 0;
}