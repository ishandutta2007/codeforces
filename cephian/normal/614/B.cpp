#include <iostream>

using namespace std;

string s, init="";

bool pf() {
  if(s[0] != '1') return false;
  for(int i = 1; i < s.size(); ++i)
    if(s[i] !='0') return false;
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  int n0 = 0,n,h0 = 0, ni= 0;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> s;
    if(s=="0")
      h0 = 1;
    else if(pf())
      n0 += s.size()-1;
    else {init = s; ni=1;}
  }
  if(h0) {
    cout << "0\n";
    return 0;
  }
  if(!ni) init+='1';
  for(int i = 0; i < n0; ++i)
    init+='0';
  cout << init << "\n";
  return 0;
}