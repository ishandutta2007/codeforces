#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

void MakePw2(int b, int e, vector<pair<int, int>>& ans) {
  int n = e - b;
  if (n == 1) return;
  
  int m = (b + e) / 2;
  MakePw2(b, m, ans);
  MakePw2(m, e, ans);
  for (int i = 0; i < (m - b); ++i) {
    ans.emplace_back(b + i, m + i);
  }
}

vector<pair<int, int>> Solve(int n) {
  int at = 0;
  
  vector<pair<int, int>> ret;
  vector<vector<int>> ap(32);
  int max_bit = 0;
  for (int bit = 0; (1 << bit) <= n; ++bit) {
    if (n & (1 << bit)) {
      MakePw2(at, at + (1 << bit), ret);
      for (int i = at; i < (at + (1 << bit)); ++i)
        ap[bit].push_back(i);
      at += (1 << bit);
      max_bit = bit;
    }
  }

  if (max_bit < 2) return ret;
  
  vector<int> take = ap[max_bit];
  ap[max_bit].clear();

  for (int bit = 0; bit < max_bit; ++bit) {
    if (ap[bit].empty()) continue;
    assert(take.size() >= ap[bit].size());
    
    vector<int> buff;
    for (int it = 0; it < (int)ap[bit].size(); ++it) {
      buff.push_back(take.back());
      take.pop_back();
    }
    
    int bit2 = bit;
    while (bit2 < max_bit && ap[bit2].size()) {
      for (int i = 0; i < (int)ap[bit2].size(); ++i) {
        ret.emplace_back(buff[i], ap[bit2][i]);
        buff.push_back(ap[bit2][i]);
      }
      ap[bit2].clear();
      ++bit2;
    }
    ap[bit2] = buff;
  }  
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  /*
  for (int n = 1; n <= 15000; ++n) {
    cout << "n = " << n << " " << Solve(n).size() << endl;
  }
  */
    

  int n; cin >> n;
  auto ret = Solve(n);
  cout << ret.size() << endl;
  for (auto p : ret) {
    cout << p.first + 1 << " " << p.second + 1 << '\n';
  }

  return 0;
}