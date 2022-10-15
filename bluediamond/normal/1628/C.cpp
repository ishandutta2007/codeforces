#include <bits/stdc++.h>


using namespace std;

struct Restriction {
  int thexor;
  vector<int> rep;
  Restriction(int thexor) : thexor(thexor) {};
};


signed main() {
  bool home = 1;
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("iron_man.txt","r",stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0), cin.tie(0);
  }

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int n;
    cin >> n;
    vector<Restriction> restrictions;
    vector<int> solution(n * n, -1);
    vector<vector<int>> whereAmI;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int code = i * n + j, xorVec;
        cin >> xorVec;
        restrictions.push_back(xorVec);
        if (i > 0) restrictions.back().rep.push_back(code - n);
        if (i + 1 < n) restrictions.back().rep.push_back(code + n);
        if (j > 0) restrictions.back().rep.push_back(code - 1);
        if (j + 1 < n) restrictions.back().rep.push_back(code + 1);
        whereAmI.push_back(restrictions.back().rep);
      }
    }
    function<void(int, int)> relax = [&] (int code, int x) {
      assert(0 <= code && code < (int) solution.size());
      assert(solution[code] == -1);
      assert(x != -1);
      solution[code] = x;
      for (auto &id : whereAmI[code]) {
        int pos_of_code = -1;
        for (int k = 0; k < (int) restrictions[id].rep.size(); k++) {
          if (restrictions[id].rep[k] == code) {
            pos_of_code = k;
          }
        }
        assert(pos_of_code != -1);
        swap(restrictions[id].rep[pos_of_code], restrictions[id].rep.back());
        restrictions[id].rep.pop_back();
        restrictions[id].thexor ^= x;
      }
      for (auto &id : whereAmI[code]) {
        if ((int) restrictions[id].rep.size() == 0) {
          assert(restrictions[id].thexor == 0);
        }
        if ((int) restrictions[id].rep.size() == 1) {
          relax(restrictions[id].rep[0], restrictions[id].thexor);
        }
      }
    };
    for (int i = 0; i < n * n; i++) {
      if (solution[i] == -1) {
        relax(i, 0);
      }
    }
    int print = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        print ^= solution[i * n + j];
       // cout << solution[i * n + j] << " ";
      }
    //  cout << "\n";
    }
    cout << print << "\n";

  }
}