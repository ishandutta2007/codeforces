#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<string> v;
int amt = 6;

int dif(string& a, string& b) {
  int d = 0;
  for(int i = 0; i < 6; ++i)
    d += a[i] != b[i];
  return (d-1)/2;
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    v.push_back(s);
  }

  for(int i = 0; i < n; ++i) {
    for(int j = i+1; j < n; ++j) {
      amt = min(amt, dif(v[i],v[j]));
    }
  }
  cout << amt << "\n";

  return 0;

}