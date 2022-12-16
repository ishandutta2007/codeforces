#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int m;
vector<int> opt;
int z=0;
clock_t clk;
vector<int> ord;
bool reach;
int mx;

bool check(int s1, int s2, int last, int k) {
  /*
  if (mx < k) {
    //cerr << " K " << k << endl;
    for (auto& x : ord) {
      //cerr << "  " << x;
    }
    //cerr << endl;
    mx = k;
  }
  */
  if (k == m) {
    return true;
  }
  for (int i=0; i<10; ++i) {
    ++z;
    if (z%1000 == 0) {
      if ((float) (clock()-clk)/CLOCKS_PER_SEC > 1.9/35) {
        reach = true;
        return false;
      }
    }
    int q = opt[rand()%opt.size()];
    if (q != last && s1+q > s2) {
      ord.push_back(q);
      bool res = check(s2, s1+q, q, k+1);
      if (res) {
        return true;
      }
      if (reach) {
        return false;
      }
      ord.pop_back();
    }
  }
  return false;
}
//

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  srand(12356);
  cin >> s;
  for (int i=1; i<=10; ++i) {
    if (s[i-1] == '1') {
      opt.push_back(i);
    }
  }
  cin >> m;
  if (opt.size() == 0) {
    cout << "NO\n";
    return 0;
  }
  bool res = false;
  for (int j=0; j<10 && !res; ++j) {
    reach = false;
    clk = clock();
    ord.clear();
    res = check(0, 0, -1, 0);
  }
  if (!res) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (auto& x : ord) {
      cout << x << " ";
    }
    cout << "\n";
  }
  return 0;
}