#include <iostream>

using namespace std;

int pw(int a, int b) {
  if(b == 0) return 1;
  return a*pw(a,b-1);
}
int main() {
  ios::sync_with_stdio(0);
  string s;
  cin >> s;
  s = "0"+s;
  int k = (s[s.size()-2]-'0')*10 + (s[s.size()-1]-'0');
  k %=4;
  cout << (1+pw(2,k)+pw(3,k)+pw(4,k))%5 << "\n";
  return 0;
}