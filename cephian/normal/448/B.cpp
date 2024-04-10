#include <iostream>
#include <algorithm>

using namespace std;

bool subseq(string& a, string& b) {
  int j = 0;
  for(int i = 0; i < a.size(); ++i) {
    if(j < b.size() && a[i]==b[j]) ++j;
  }
  return j == b.size();
}
int main() {
  ios::sync_with_stdio(0);
  string a,b;
  cin >>a>>b;
  if(subseq(a,b)) {
    cout << "automaton\n";
    return 0;
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  if(a==b) {
    cout << "array\n";
    return 0;
  }
  if(subseq(a,b)) {
    cout << "both\n";
    return 0;
  }
  cout << "need tree\n";
  return 0;
}