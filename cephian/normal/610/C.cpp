#include <iostream>
#include <vector>

using namespace std;

vector<string> ls;

string flip(string s) {
  string q = s;
  for(int i = 0; i < s.size(); ++i) {
    if(q[i]=='+') q[i]='*';
    else q[i] = '+';
  }
  return q;
}

int main() {
  int k;
  cin >> k;
  ls.push_back("+");
  for(int i = 0; i < k; ++i) {
    for(int j = 0; j < (1<<i); ++j) {
      ls.push_back(ls[j] + flip(ls[j]));
      ls[j] += ls[j];
    }
  }
  for(int i = 0; i < ls.size(); ++i)
    cout << ls[i] << endl;
  return 0;
}