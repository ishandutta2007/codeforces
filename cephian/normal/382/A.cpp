#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

vector<char> l,r;

int main() {
  string a,b;
  cin >> a >> b;
  bool s=0;
  for(int i = 0; i < a.size(); ++i) {
    if(a[i]=='|') s=1;
    else if(s){
      r.push_back(a[i]);
    } else {
      l.push_back(a[i]);
    }
  }
  for(int i = 0; i < b.size(); ++i) {
    if(l.size() <= r.size()) {
      l.push_back(b[i]);
    } else r.push_back(b[i]);
  }
  if(l.size() != r.size()) {
    cout << "Impossible\n";
    return 0;
  }
  for(int i = 0; i < l.size(); ++i)
    cout << char(l[i]);
  cout << "|";
  for(int i = 0; i < r.size(); ++i)
    cout << char(r[i]);
  cout << "\n";
}