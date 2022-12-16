#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll k;

const string codeforces = "codeforces";

string of (int i, int j) {
  //cerr << " I J " << i << " " << j << endl;
  string ans;
  for (int x=0; x<j; ++x) 
    ans += codeforces[i];
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> k;
  for (int i=1; i<=60; ++i) {
    string bs;
    for (int j=0; j<10; ++j) {
      string s;
      ll amt = 1;
      for (int x=0; x<j; ++x) {
        amt *= i+1;
        s += of(x, i+1);
      }
      for (int y=j; y<10; ++y) {
        amt *= i;
        s += of(y, i);
      }
      //cerr << " I J " << i << " " << j << " AMT " << amt << endl;
      if (amt >= k) {
        cout << s << "\n";
        return 0;
      }
    }
  }
  return 1;
}