#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

int ask(const vector<int>& a, const vector<int> & b) {
  cout << len(a) << ' ' << len(b) << ' ';
  for (auto i: a) cout << i << ' ';
  for (auto i: b) cout << i << ' ';
  cout << endl;
  int res; cin >> res;
  return res;
}

void answer(int num) {
  cout << "-1 " << num << endl;
}

vector<int> join(vector<int> a, const vector<int>& b) {
  a.insert(a.end(), all(b));
  return a;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    rep(testcase, ntest) {
      int n; cin >> n;
      vector<int> a(1, n);
      vector<int> b(n - 1);
      rep(i, n - 1) b[i] = i + 1;
      int tdist = ask(a, b);
      while (len(b) > 1) {
        int mid = len(b) / 2;
        vector<int> ta = vector<int>(b.begin(), b.begin() + mid);
        vector<int> tb = vector<int>(b.begin() + mid, b.end());
        int cur_dist = ask(a, ta);

        if (cur_dist == tdist) {
          b = ta;
        } else {
          b = tb;
        }
      }
      a.clear();
      rep(i, n) if ((i + 1) != b[0]) a.push_back(i + 1);
      answer(ask(a, b));
    }

    return 0;
}